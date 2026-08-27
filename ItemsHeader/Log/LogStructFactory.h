#pragma once
#include"LogStruct.h"
#include<concepts>

/// <summary>
/// ログ用名前空間
/// </summary>
namespace Log {

	/// <summary>
	/// テンプレートコンセプト定義用名前空間
	/// </summary>
	namespace concepts {

		/// <summary>
		/// 文字列変換可能コンセプト
		/// </summary>
		template<typename T>
		concept StringConvertible = requires(T value) {
			std::convertible_to<T, std::string>;
		};
	}

	/* ========== ログ用構造体作成クラス定義 ========== */

	/// <summary>
	/// ログ用構造体作成クラス
	/// </summary>
	class LogStructFactory
	{
	public:
		/* ===== メンバー関数 ===== */
		
		/// <summary>
		/// ログ構造体作成テンプレート関数
		/// </summary>
		/// <typeparam name="T">文字列に変換する型</typeparam>
		/// <param name="value">文字列に変換する値</param>
		/// <returns>Log保存用構造体</returns>
		template<concepts::StringConvertible T>
		static [[nodiscard]] LogStruct create_log(const T& value);

	private:
		/* ===== メンバー関数 ===== */
		
		//	コンストラクタ
		LogStructFactory() = default;

		//	デストラクタ
		~LogStructFactory() = default;
	};

	/// <summary>
	/// ログ構造体作成テンプレート関数
	/// </summary>
	/// <typeparam name="T">文字列に変換する型</typeparam>
	/// <param name="value">文字列に変換する値</param>
	/// <returns>Log保存用構造体</returns>
	template<concepts::StringConvertible T>
	static [[nodiscard]] LogStruct LogStructFactory::create_log(const T& value) {
		return LogStruct(value);
	}
}