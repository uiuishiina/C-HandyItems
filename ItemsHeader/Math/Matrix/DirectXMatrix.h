#pragma once
#include<DirectXMath.h>

/// <summary>
/// DirectX名前空間
/// </summary>
namespace directx {

	/// <summary>
	/// 行列名前空間
	/// </summary>
	namespace matrix {

		/// <summary>
		/// 行列ラッパー構造体
		/// </summary>
		struct Matrix {

		private:
			/* ========== Privateメンバー変数 ========== */

			/// <summary>
			/// 行列
			/// </summary>
			DirectX::XMMATRIX matrix_{};

		public:
			/* ========== Publicメンバー関数 ========== */
			
			/* -- 設定 -- */

			/// <summary>
			/// 引数付きコンストラクタ
			/// </summary>
			/// <param name="matrix">設定する行列</param>
			Matrix(DirectX::XMMATRIX matrix) :
				matrix_{ matrix } {}

			/// <summary>
			/// コピーコンストラクタ
			/// </summary>
			/// <param name="">コピー元行列ラッパー構造体</param>
			Matrix(const Matrix&) = default;

			/// <summary>
			/// コピー演算子オーバーロード
			/// </summary>
			/// <param name="">コピー元行列ラッパー構造体</param>
			/// <returns>コピーした後の自身参照</returns>
			Matrix& operator=(const Matrix&) = default;

			/// <summary>
			/// ムーブコンストラクタ
			/// </summary>
			/// <param name="">ムーブ元行列ラッパー構造体</param>
			Matrix(Matrix&&) = default;

			/// <summary>
			/// ムーブ演算子オーバーロード
			/// </summary>
			/// <param name="">ムーブ元行列ラッパー構造体</param>
			/// <returns>ムーブした後の自身参照</returns>
			Matrix& operator=(Matrix&&) = default;
			
			/// <summary>
			/// 乗算演算子オーバーロード
			/// </summary>
			/// <param name="rhs">右辺の行列</param>
			/// <returns>乗算した行列</returns>
			[[nodiscard]] Matrix operator*(const Matrix& rhs) const noexcept {
				return Matrix{
					DirectX::XMMatrixMultiply(
						matrix_,
						rhs.get_matrix()
					)
				};
			}

			/// <summary>
			/// 乗算代入演算子オーバーロード
			/// </summary>
			/// <param name="rhs">乗算する行列</param>
			/// <returns>乗算した後の自身参照</returns>
			[[nodiscard]] Matrix& operator*=(const Matrix& rhs) noexcept {
				matrix_ = DirectX::XMMatrixMultiply(
					matrix_,
					rhs.matrix_
				);
				return *this;
			}


			/* -- 取得関数 -- */

			/// <summary>
			/// 行列取得関数
			/// </summary>
			/// <returns>行列</returns>
			DirectX::XMMATRIX& get_matrix() noexcept {
				return matrix_;
			}
			const DirectX::XMMATRIX& get_matrix() const noexcept {
				return matrix_;
			}

			/// <summary>
			/// 転置行列取得関数
			/// </summary>
			/// <returns>転置行列</returns>
			[[nodiscard]] Matrix transpose() const noexcept {
				return Matrix{
					DirectX::XMMatrixTranspose(matrix_)
				};
			}

			/// <summary>
			/// 逆行列取得関数
			/// </summary>
			/// <returns>逆行列</returns>
			[[nodiscard]] Matrix inverse() const noexcept {
				return Matrix{
					DirectX::XMMatrixInverse(
						nullptr,
						matrix_
					)
				};
			}

		};

		/* ========== 行列ラッパー構造体補助関数群 ========== */

		/// <summary>
		/// 単位行列作成関数
		/// </summary>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix identity() noexcept {
			return Matrix{
				DirectX::XMMatrixIdentity()
			};
		}

		/// <summary>
		/// 平行移動行列作成関数
		/// </summary>
		/// <param name="x">X軸座標</param>
		/// <param name="y">Y軸座標</param>
		/// <param name="z">Z軸座標</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix translation(
			float x,
			float y,
			float z
		) noexcept {
			return Matrix{
				DirectX::XMMatrixTranslation(x, y, z)
			};
		}

		/// <summary>
		/// 平行移動行列作成関数
		/// </summary>
		/// <param name="vec3">移送するベクトル</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix translation(
			DirectX::XMFLOAT3 vec3
		) noexcept {
			return Matrix{
				translation(vec3.x, vec3.y, vec3.z)
			};
		}

		/// <summary>
		/// スケール行列作成関数
		/// </summary>
		/// <param name="x">X軸サイズ</param>
		/// <param name="y">Y軸サイズ</param>
		/// <param name="z">Z軸サイズ</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix scaling(
			float x,
			float y,
			float z
		) noexcept {
			return Matrix{
				DirectX::XMMatrixScaling(x, y, z)
			};
		}
		
		/// <summary>
		/// スケール行列作成関数
		/// </summary>
		/// <param name="vec3">スケールするベクトル</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix scaling(
			DirectX::XMFLOAT3 vec3
		) noexcept {
			return Matrix{
				scaling(vec3.x,vec3.y,vec3.z)
			};
		}

		/// <summary>
		/// 回転行列作成関数
		/// </summary>
		/// <param name="pitch">X軸回転（ラジアン）</param>
		/// <param name="yaw">Y軸回転（ラジアン）</param>
		/// <param name="roll">Z軸回転（ラジアン）</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix rotation(
			float pitch,
			float yaw,
			float roll
		) noexcept {
			return Matrix{
				DirectX::XMMatrixRotationRollPitchYaw(
					pitch,
					yaw,
					roll
				)
			};
		}

		/// <summary>
		/// 回転行列作成関数
		/// </summary>
		/// <param name="vec3">回転するベクトル</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix rotation(
			DirectX::XMFLOAT3 vec3
		) noexcept {
			return Matrix{
				rotation(vec3.x,vec3.y,vec3.z)
			};
		}

		/// <summary>
		/// 回転行列作成関数
		/// </summary>
		/// <param name="quaternion">回転クォータニオン</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix rotation(const DirectX::XMVECTOR& quaternion) noexcept {
			return Matrix{
				DirectX::XMMatrixRotationQuaternion(quaternion)
			};
		}

		/// <summary>
		/// X軸回転行列作成関数
		/// </summary>
		/// <param name="radian">回転量（ラジアン）</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix rotation_x(float radian) noexcept {
			return Matrix{
				DirectX::XMMatrixRotationX(radian)
			};
		}

		/// <summary>
		/// Y軸回転行列作成関数
		/// </summary>
		/// <param name="radian">回転量（ラジアン）</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix rotation_y(float radian) noexcept {
			return Matrix{
				DirectX::XMMatrixRotationY(radian)
			};
		}

		/// <summary>
		/// Z軸回転行列作成関数
		/// </summary>
		/// <param name="radian">回転量（ラジアン）</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix rotation_z(float radian) noexcept {
			return Matrix{
				DirectX::XMMatrixRotationZ(radian)
			};
		}

		/// <summary>
		/// View行列作成関数
		/// </summary>
		/// <param name="eye">視点の位置ベクトル</param>
		/// <param name="focus">注視点の位置</param>
		/// <param name="up">視点の上ベクトル</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix look_at(
			const DirectX::XMVECTOR& eye,
			const DirectX::XMVECTOR& focus,
			const DirectX::XMVECTOR& up
		) noexcept {
			return Matrix{
				DirectX::XMMatrixLookAtLH(
					eye,
					focus,
					up
				)
			};
		}

		/// <summary>
		/// 透視投影行列作成関数
		/// </summary>
		/// <param name="fov_y">垂直方向の視野角（ラジアン）</param>
		/// <param name="aspect_ratio">アスペクト比</param>
		/// <param name="near_z">ニアクリップ距離</param>
		/// <param name="far_z">ファークリップ距離</param>
		/// <returns>作成した行列</returns>
		[[nodiscard]] inline Matrix perspective_fov(
			float fov_y,
			float aspect_ratio,
			float near_z,
			float far_z
		) noexcept {
			return Matrix{
				DirectX::XMMatrixPerspectiveFovLH(
					fov_y,
					aspect_ratio,
					near_z,
					far_z
				)
			};
		}
	}
}