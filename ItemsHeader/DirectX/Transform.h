#pragma once
#include"DirectXMatrix.h"

/// <summary>
/// DirectX名前空間
/// </summary>
namespace directx {

	/// <summary>
	/// 行列名前空間
	/// </summary>
	namespace matrix {

		/// <summary>
		/// 行列ラッパークラス
		/// </summary>
		struct Transform {

		private:
			/* ========== Privateメンバー変数 ========== */

			/// <summary>
			/// 位置座標
			/// </summary>
			DirectX::XMFLOAT3 position_{};

			/// <summary>
			/// 回転座標
			/// </summary>
			DirectX::XMFLOAT3 rotation_{};

			/// <summary>
			/// スケール座標
			/// </summary>
			DirectX::XMFLOAT3 scale_{ 1.0f, 1.0f, 1.0f };

			
		public:
			/* ========== Publicメンバー関数 ========== */

			/// <summary>
			/// 引数付きコンストラクタ
			/// </summary>
			/// <param name="pos">位置座標</param>
			/// <param name="rot">回転座標</param>
			/// <param name="scale">スケール座標</param>
			Transform(
				DirectX::XMFLOAT3 pos,
				DirectX::XMFLOAT3 rot,
				DirectX::XMFLOAT3 scale
			) :
				position_{ pos }, rotation_{ rot }, scale_{ scale } {}

			/// <summary>
			/// 行列取得関数
			/// </summary>
			/// <returns></returns>
			[[nodiscard]] const Matrix& get_matrix() const noexcept {
				
				const auto scale = scaling(scale_);

				const auto rot = rotation(rotation_);

				const auto pos = translation(position_);

				//	行列作成
				return scale * rot * pos;
			}

			/// <summary>
			/// 位置座標取得関数
			/// </summary>
			/// <returns>位置座標</returns>
			DirectX::XMFLOAT3& get_pos() noexcept {
				return position_;
			}
			const DirectX::XMFLOAT3& get_pos()const noexcept {
				return position_;
			}

			/// <summary>
			/// 回転座標取得関数
			/// </summary>
			/// <returns>回転座標</returns>
			DirectX::XMFLOAT3& get_rot() noexcept {
				return rotation_;
			}
			const DirectX::XMFLOAT3& get_rot()const noexcept {
				return rotation_;
			}

			/// <summary>
			/// スケール座標取得関数
			/// </summary>
			/// <returns>スケール座標</returns>
			DirectX::XMFLOAT3& get_scale() noexcept {
				return scale_;
			}
			const DirectX::XMFLOAT3& get_scale()const noexcept {
				return scale_;
			}

		};
	}
}