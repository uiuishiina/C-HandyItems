#pragma once
#include<concepts>

/// <summary>
/// その他名前空間
/// </summary>
namespace others {

	/// <summary>
	/// テンプレートコンセプト定義用名前空間
	/// </summary>
	namespace concepts {
		
		/// <summary>
		/// 列挙体指定コンセプト
		/// </summary>
		template<typename T>
		concept IsEnum = std::is_enum_v<T>;
	}
	
	/// <summary>
	/// 列挙体変換関数
	/// </summary>
	/// <param name="value">変換する列挙体変数</param>
	/// <returns>変換した値</returns>
	template<concepts::IsEnum T>
	static [[nodiscard]] size_t enum_to_index(const T& value) {
		return static_cast<size_t>(value);
	}
}

/// <summary>
/// お試し用(利用時削除推奨)
/// </summary>
enum hogehoge {
	A,
	B,
	C,

	Count
};