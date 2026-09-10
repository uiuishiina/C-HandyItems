#pragma once
#include"MathF.h"
#include"../BaseStruct/Matrix.h"
#include"../BaseStruct/Float3.h"
#include<optional>

/// <summary>
/// 便利アイテム名前空間
/// </summary>
namespace HandyItem {

	/// <summary>
	/// 数学名前空間
	/// </summary>
	namespace Math {

		/// <summary>
		/// 数学関数名前空間
		/// </summary>
		namespace MathF {

			/* ========== 行列数学 ========== */

			/// <summary>
			/// 単位行列取得関数
			/// </summary>
			/// <returns>単位行列</returns>
			[[nodiscard]] inline Matrix identity() {
				return {};
			}


			/// <summary>
			/// 転置行列計算関数
			/// </summary>
			/// <param name="matrix">対象行列</param>
			/// <returns>転置された行列</returns>
			[[nodiscard]] inline Matrix transpose(
				const Matrix& matrix
			) {

				Matrix result{};

				for (std::size_t row = 0; row < 4; ++row) {
					for (std::size_t col = 0; col < 4; ++col) {
						result[row][col] = matrix[col][row];
					}
				}

				return result;
			}


			/// <summary>
			/// 行列式計算関数
			/// </summary>
			/// <param name="matrix">対象行列</param>
			/// <returns>行列式</returns>
			[[nodiscard]] inline float determinant(
				const Matrix& matrix
			) {

				/*
					a,b,c,d
					e,f,g,h
					i,j,k,l
					m,n,o,p
				*/

				const float a = matrix[0][0];
				const float b = matrix[0][1];
				const float c = matrix[0][2];
				const float d = matrix[0][3];

				const float e = matrix[1][0];
				const float f = matrix[1][1];
				const float g = matrix[1][2];
				const float h = matrix[1][3];

				const float i = matrix[2][0];
				const float j = matrix[2][1];
				const float k = matrix[2][2];
				const float l = matrix[2][3];

				const float m = matrix[3][0];
				const float n = matrix[3][1];
				const float o = matrix[3][2];
				const float p = matrix[3][3];

				return
					a * (
						f * (k * p - l * o) -
						g * (j * p - l * n) +
						h * (j * o - k * n)
						)
					-
					b * (
						e * (k * p - l * o) -
						g * (i * p - l * m) +
						h * (i * o - k * m)
						)
					+
					c * (
						e * (j * p - l * n) -
						f * (i * p - l * m) +
						h * (i * n - j * m)
						)
					-
					d * (
						e * (j * o - k * n) -
						f * (i * o - k * m) +
						g * (i * n - j * m)
						);
			}


			/// <summary>
			/// 逆行列計算関数
			/// </summary>
			/// <param name="matrix">対象行列</param>
			/// <returns>逆行列</returns>
			[[nodiscard]] inline std::optional<Matrix> inverse(
				const Matrix& matrix
			) {

				const float det = determinant(matrix);

				//	逆行列を持たない
				if (det == 0.0f) {
					return std::nullopt;
				}

				Matrix result{};

				//	余因子行列を作成
				for (std::size_t row = 0; row < 4; ++row) {
					for (std::size_t col = 0; col < 4; ++col) {

						float minor[3][3]{};

						std::size_t minor_row = 0;

						for (std::size_t src_row = 0; src_row < 4; ++src_row) {

							if (src_row == row) {
								continue;
							}

							std::size_t minor_col = 0;

							for (std::size_t src_col = 0; src_col < 4; ++src_col) {

								if (src_col == col) {
									continue;
								}

								minor[minor_row][minor_col] =
									matrix[src_row][src_col];

								++minor_col;
							}

							++minor_row;
						}

						const float minor_det =
							minor[0][0] * (
								minor[1][1] * minor[2][2] -
								minor[1][2] * minor[2][1]
								)
							-
							minor[0][1] * (
								minor[1][0] * minor[2][2] -
								minor[1][2] * minor[2][0]
								)
							+
							minor[0][2] * (
								minor[1][0] * minor[2][1] -
								minor[1][1] * minor[2][0]
								);

						const float cofactor =
							((row + col) % 2 == 0)
							? minor_det
							: -minor_det;

						//	余因子行列の転置 = 逆行列
						result[col][row] = cofactor / det;
					}
				}

				return result;
			}


			/* ========== 変換行列 ========== */

			/// <summary>
			/// 平行移動行列生成関数
			/// </summary>
			/// <param name="translation">平行移動量</param>
			/// <returns>平行移動行列</returns>
			[[nodiscard]] inline Matrix translate(
				const Float3& translation
			) {

				Matrix result{};

				result[0][3] = translation.x_;
				result[1][3] = translation.y_;
				result[2][3] = translation.z_;

				return result;
			}


			/// <summary>
			/// 拡大縮小行列生成関数
			/// </summary>
			/// <param name="scale">XYZの拡大縮小率</param>
			/// <returns>拡大縮小行列</returns>
			[[nodiscard]] inline Matrix scale(
				const Float3& scale
			) {

				return Matrix{ scale };
			}


			/// <summary>
			/// X軸回転行列生成関数
			/// </summary>
			/// <param name="radian">回転角度（ラジアン）</param>
			/// <returns>X軸回転行列</returns>
			[[nodiscard]] inline Matrix rotate_x(
				float radian
			) {

				const float c = MathF::cos(radian);
				const float s = MathF::sin(radian);

				return Matrix{
					Float4{ 1.0f, 0.0f, 0.0f, 0.0f },
					Float4{ 0.0f, c,    -s,   0.0f },
					Float4{ 0.0f, s,     c,   0.0f },
					Float4{ 0.0f, 0.0f, 0.0f, 1.0f }
				};
			}


			/// <summary>
			/// Y軸回転行列生成関数
			/// </summary>
			/// <param name="radian">回転角度（ラジアン）</param>
			/// <returns>Y軸回転行列</returns>
			[[nodiscard]] inline Matrix rotate_y(
				float radian
			) {

				const float c = MathF::cos(radian);
				const float s = MathF::sin(radian);

				return Matrix{
					Float4{ c,    0.0f, s,    0.0f },
					Float4{ 0.0f, 1.0f, 0.0f, 0.0f },
					Float4{ -s,   0.0f, c,    0.0f },
					Float4{ 0.0f, 0.0f, 0.0f, 1.0f }
				};
			}


			/// <summary>
			/// Z軸回転行列生成関数
			/// </summary>
			/// <param name="radian">回転角度（ラジアン）</param>
			/// <returns>Z軸回転行列</returns>
			[[nodiscard]] inline Matrix rotate_z(
				float radian
			) {

				const float c = MathF::cos(radian);
				const float s = MathF::sin(radian);

				return Matrix{
					Float4{ c,    -s,   0.0f, 0.0f },
					Float4{ s,     c,   0.0f, 0.0f },
					Float4{ 0.0f, 0.0f, 1.0f, 0.0f },
					Float4{ 0.0f, 0.0f, 0.0f, 1.0f }
				};
			}

		}
	}
}
