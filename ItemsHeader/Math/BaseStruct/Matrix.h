#pragma once
#include"Float4.h"

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
		struct Matrix {

			/* ========== メンバー変数 ========== */

			/// <summary>
			/// 行列
			/// </summary>
			Float4 matrix_[4] = {
				{ 0.0f, 0.0f, 0.0f, 0.0f},
				{ 0.0f, 0.0f, 0.0f, 0.0f},
				{ 0.0f, 0.0f, 0.0f, 0.0f},
				{ 0.0f, 0.0f, 0.0f, 1.0f}
			};

			/* ========== メンバー関数 ========== */

			/// <summary>
			/// コンストラクタ
			/// </summary>
			Matrix() = default;

			/// <summary>
			/// 引数付きコンストラクタ
			/// </summary>
			/// <param name="r1">[ matrix_[0] ] の値</param>
			/// <param name="r2">[ matrix_[1] ] の値</param>
			/// <param name="r3">[ matrix_[2] ] の値</param>
			/// <param name="r4">[ matrix_[3] ] の値</param>
			Matrix(
				Float4 r1, 
				Float4 r2, 
				Float4 r3, 
				Float4 r4
			) {

				matrix_[0] = r1;
				matrix_[1] = r2;
				matrix_[2] = r3;
				matrix_[3] = r4;
			}


			/// <summary>
			/// 要素アクセス演算子
			/// </summary>
			/// <param name="index">
			/// 要素番号（0: matrix_[0]、1: matrix_[1]、2: matrix_[2]、3: matrix_[3]）
			/// </param>
			/// <returns>指定した要素への参照</returns>
			[[nodiscard]] Float4& operator[](std::size_t index) {
				assert(index < 4 && "Matrix index out of range");
				switch (index)
				{
				case 0:
					return matrix_[0];
				case 1:
					return matrix_[1];
				case 2:
					return matrix_[2];
				default:
					return matrix_[3];
				}
			}


			/// <summary>
			/// 要素アクセス演算子
			/// </summary>
			/// <param name="index">
			/// 要素番号（0: matrix_[0]、1: matrix_[1]、2: matrix_[2]、3: matrix_[3]）
			/// </param>
			/// <returns>指定した要素へのConst参照</returns>
			[[nodiscard]] const Float4& operator[](std::size_t index) const {
				assert(index < 4 && "Matrix index out of range");
				switch (index)
				{
				case 0:
					return matrix_[0];
				case 1:
					return matrix_[1];
				case 2:
					return matrix_[2];
				default:
					return matrix_[3];
				}
			}

		};
	}
}