#pragma once
#include<string>

/// <summary>
/// ログ用名前空間
/// </summary>
namespace Log {

	/* ========== ログ用構造体定義 ========== */

	/// <summary>
	/// Log保存用構造体
	/// Logに欲しいデータなどを定義
	/// </summary>
	struct LogStruct {

		/* ===== メンバー変数 ===== */

		/// <summary>
		/// Log文字列データ
		/// </summary>
		std::string data_{};

		/* ===== メンバー関数 ===== */

		/// <summary>
		/// コンストラクタ
		/// </summary>
		LogStruct() = default;

		/// <summary>
		/// 引数付きコンストラクタ
		/// </summary>
		/// <param name="data">Log文字列データ</param>
		LogStruct(std::string data) :
			data_(data) {};

	};
}