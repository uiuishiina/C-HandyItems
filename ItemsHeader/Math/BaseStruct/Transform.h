#pragma once
#include"../Function/MathFMatrix.h"

/// <summary>
/// 便利アイテム名前空間
/// </summary>
namespace HandyItem {

	/// <summary>
	/// 数学名前空間
	/// </summary>
	namespace Math {

		/// <summary>
		/// トランスフォーム構造体
		/// </summary>
		struct Transform {

			/* ========== メンバー変数 ========== */

			/// <summary>
			/// 平行移動量
			/// </summary>
			Float3 translation_{};

			/// <summary>
			/// 回転量
			/// </summary>
			Quaternion rotation_{};

			/// <summary>
			/// 拡大率
			/// </summary>
			Float3 scale_{};

			/* ========== メンバー関数 ========== */

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Transform() = default;

			/// <summary>
			/// 引数付きコンストラクタ
			/// </summary>
			/// <param name="translate">平行移動量</param>
			/// <param name="rotate">回転量</param>
			/// <param name="scale">拡大率</param>
			Transform(const Float3& translate,
				const Quaternion& rotate,
				const Float3& scale
			) :
				translation_{ translate },
				rotation_{ rotate },
				scale_{ scale } {
			}

			/// <summary>
			/// 行列取得関数
			/// </summary>
			/// <returns>取得した行列</returns>
			[[nodiscard]] Matrix get_matrix() const {

				return MathF::transform_to_matrix(
					translation_,
					rotation_,
					scale_
				);
			}

			void translate(const Float3& move) {

				MathF::apply_translation()
			}

		};
	}
}