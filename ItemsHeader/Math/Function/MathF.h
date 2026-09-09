#pragma once
#include<cmath>

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

			/* ========== 基礎数学 ========== */

			/* -- 三角関数 -- */

			/// <summary>
			/// SIN計算関数
			/// </summary>
			/// <param name="value">角度（ラジアン）</param>
			/// <returns>[ SIN ] の計算結果</returns>
			[[nodiscard]] inline float sin(float value) {
				return std::sin(value);
			}

			/// <summary>
			/// COS計算関数
			/// </summary>
			/// <param name="value">角度（ラジアン）</param>
			/// <returns>[ COS ] の計算結果</returns>
			[[nodiscard]] inline float cos(float value) {
				return std::cos(value);
			}

			/// <summary>
			/// TAN計算関数
			/// </summary>
			/// <param name="value">角度（ラジアン）</param>
			/// <returns>[ TAN ] の計算結果</returns>
			[[nodiscard]] inline float tan(float value) {
				return std::tan(value);
			}

			/* -- 逆三角関数 -- */

			/// <summary>
			/// ASIN計算関数
			/// </summary>
			/// <param name="value">計算する値</param>
			/// <returns>[ ASIN ] の計算結果 [ 角度（ラジアン）]</returns>
			[[nodiscard]] inline float asin(float value) {
				return std::asin(value);
			}

			/// <summary>
			/// ACOS計算関数
			/// </summary>
			/// <param name="value">計算する値</param>
			/// <returns>[ ACOS ] の計算結果 [ 角度（ラジアン）]</returns>
			[[nodiscard]] inline float acos(float value) {
				return std::acos(value);
			}

			/// <summary>
			/// ATAN計算関数
			/// </summary>
			/// <param name="value">計算する値</param>
			/// <returns>[ ATAN ] の計算結果 [ 角度（ラジアン）]</returns>
			[[nodiscard]] inline float atan(float value) {
				return std::atan(value);
			}

			/// <summary>
			/// ATAN2計算関数
			/// </summary>
			/// <param name="y">[ Y軸 ] の値</param>
			/// <param name="x">[ X軸 ] の値</param>
			/// <returns>[ ATAN2 ] の計算結果 [ 角度（ラジアン）]</returns>
			[[nodiscard]] inline float atan2(float y, float x) {
				return std::atan2(y, x);
			}

			/* -- 数値計算 -- */

			/// <summary>
			/// 平方根計算関数
			/// </summary>
			/// <param name="value">計算する値</param>
			/// <returns>[ 平方根 ] の計算結果</returns>
			[[nodiscard]] inline float sqrt(float value) {
				return std::sqrt(value);
			}

			/// <summary>
			/// 絶対値計算関数
			/// </summary>
			/// <param name="value">計算する値</param>
			/// <returns>[ 絶対値 ] の計算結果</returns>
			[[nodiscard]] inline float abs(float value) {
				return std::abs(value);
			}

			/// <summary>
			/// 最小値取得関数
			/// </summary>
			/// <param name="left">比較する左辺値</param>
			/// <param name="right">比較する右辺値</param>
			/// <returns>[ 小さい方 ] の値</returns>
			[[nodiscard]] inline float min(float left,float right) {
				return left < right ? left : right;
			}

			/* -- 数値制限 -- */

			/// <summary>
			/// 最大値取得関数
			/// </summary>
			/// <param name="left">比較する左辺値</param>
			/// <param name="right">比較する右辺値</param>
			/// <returns>[ 大きい方 ] の値</returns>
			[[nodiscard]] inline float max(float left, float right) {
				return left > right ? left : right;
			}

			/// <summary>
			/// Clamp関数
			/// </summary>
			/// <param name="value">制限する値</param>
			/// <param name="min">最小値</param>
			/// <param name="max">最大値</param>
			/// <returns>[ 範囲内に制限 ] された値</returns>
			[[nodiscard]] inline float clamp(float value, float min,float max) {
				if (min <= value && value <= max) {
					return value;
				}
				else if (value < min) {
					return min;
				}
				else {
					return max;
				}
			}
		}
	}
}