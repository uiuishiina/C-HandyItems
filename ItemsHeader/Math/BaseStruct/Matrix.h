#pragma once
#include"Float3.h"
#include"Float4.h"
#include<cassert>

/// <summary>
/// 便利アイテム名前空間
/// </summary>
namespace HandyItem {

	/// <summary>
	/// 数学名前空間
	/// </summary>
	namespace Math {

		/// <summary>
		/// 行列構造体
		/// </summary>
		/// <details>
		/// 列ベクトルを使用し、行単位で保持
		/// </details>
		struct Matrix {

			/* ========== メンバー変数 ========== */

			/// <summary>
			/// 行列
			/// </summary>
			Float4 matrix_[4] = {
				{ 1.0f, 0.0f, 0.0f, 0.0f},
				{ 0.0f, 1.0f, 0.0f, 0.0f},
				{ 0.0f, 0.0f, 1.0f, 0.0f},
				{ 0.0f, 0.0f, 0.0f, 1.0f}
			};

			/* ========== メンバー関数 ========== */

			/* -- 設定 -- */

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Matrix() = default;

			/// <summary>
			/// 
			/// </summary>
			
			/// <summary>
			/// 引数付きコンストラクタ
			/// </summary>
			/// <param name="row0">[ matrix_[0] ] の値</param>
			/// <param name="row1">[ matrix_[1] ] の値</param>
			/// <param name="row2">[ matrix_[2] ] の値</param>
			/// <param name="row3">[ matrix_[3] ] の値</param>
			Matrix(
				const Float4& row0,
				const Float4& row1,
				const Float4& row2,
				const Float4& row3
			) :
				matrix_{ row0, row1, row2, row3 } {}

			/// <summary>
			/// スケール成分指定コンストラクタ
			/// </summary>
			/// <param name="value">XYZの対角成分</param>
			Matrix(
				const Float3& diagonal
			) {

				matrix_[0] = { diagonal.x_, 0.0f, 0.0f, 0.0f };
				matrix_[1] = { 0.0f, diagonal.y_, 0.0f, 0.0f };
				matrix_[2] = { 0.0f, 0.0f, diagonal.z_, 0.0f };
				matrix_[3] = { 0.0f, 0.0f, 0.0f ,1.0f };
			}

			/// <summary>
			/// 対角成分指定コンストラクタ
			/// </summary>
			/// <param name="value">対角成分の値</param>
			Matrix(
				const Float4& diagonal
			) {

				matrix_[0] = { diagonal.x_, 0.0f, 0.0f, 0.0f };
				matrix_[1] = { 0.0f, diagonal.y_, 0.0f, 0.0f };
				matrix_[2] = { 0.0f, 0.0f, diagonal.z_, 0.0f };
				matrix_[3] = { 0.0f, 0.0f, 0.0f ,diagonal.w_ };
			}


			/* -- 演算子オーバーロード -- */

			/* -- アクセス -- */

			/// <summary>
			/// 要素アクセス演算子
			/// </summary>
			/// <param name="index">
			/// 要素番号（0: matrix_[0]、1: matrix_[1]、2: matrix_[2]、3: matrix_[3]）
			/// </param>
			/// <returns>指定した要素への参照</returns>
			[[nodiscard]] Float4& operator[](
				std::size_t index
				) {

				assert(index < 4 && "Matrix index out of range");
				return matrix_[index];
			}


			/// <summary>
			/// 要素アクセス演算子
			/// </summary>
			/// <param name="index">
			/// 要素番号（0: matrix_[0]、1: matrix_[1]、2: matrix_[2]、3: matrix_[3]）
			/// </param>
			/// <returns>指定した要素へのConst参照</returns>
			[[nodiscard]] const Float4& operator[](
				std::size_t index
				) const {

				assert(index < 4 && "Matrix index out of range");
				return matrix_[index];
			}

			/* -- 演算 -- */

			/// <summary>
			/// 乗算演算子
			/// </summary>
			/// <param name="right">右辺値</param>
			/// <returns>乗算結果</returns>
			[[nodiscard]] Matrix operator * (
				const Matrix& right
				) const {

				Matrix result{};

				for (std::size_t row = 0; row < 4; ++row) {
					for (std::size_t col = 0; col < 4; ++col) {

						result[row][col] = (
							(*this)[row][0] * right[0][col] +
							(*this)[row][1] * right[1][col] +
							(*this)[row][2] * right[2][col] +
							(*this)[row][3] * right[3][col]
							);
					}
				}

				return result;
			}

			/// <summary>
			/// 乗算代入演算子
			/// </summary>
			/// <param name="right">右辺値</param>
			/// <returns>乗算後の自身参照</returns>
			Matrix& operator *= (
				const Matrix & right
				) {

				*this = *this * right;

				return *this;
			}

			/// <summary>
			/// 乗算演算子
			/// </summary>
			/// <details>
			/// 行列と四次元ベクトルの乗算
			/// </details>
			/// <param name="right">右辺の四次元ベクトル</param>
			/// <returns>行列による変換後の四次元ベクトル</returns>
			[[nodiscard]] Float4 operator * (
				const Float4& right
				) const {

				return {

					//	X成分
					matrix_[0][0] * right.x_ +
					matrix_[0][1] * right.y_ +
					matrix_[0][2] * right.z_ +
					matrix_[0][3] * right.w_,

					//	Y成分
					matrix_[1][0] * right.x_ +
					matrix_[1][1] * right.y_ +
					matrix_[1][2] * right.z_ +
					matrix_[1][3] * right.w_,

					//	Z成分
					matrix_[2][0] * right.x_ +
					matrix_[2][1] * right.y_ +
					matrix_[2][2] * right.z_ +
					matrix_[2][3] * right.w_,

					//	W成分
					matrix_[3][0] * right.x_ +
					matrix_[3][1] * right.y_ +
					matrix_[3][2] * right.z_ +
					matrix_[3][3] * right.w_
				};
			}

		};
	}
}