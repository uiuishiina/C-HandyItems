#pragma once
#include<cstdint>
#include<concepts>

/// <summary>
/// キー名前空間
/// </summary>
namespace key {

	/// <summary>
	/// テンプレートコンセプト定義用名前空間
	/// </summary>
	namespace concepts {
	
		/// <summary>
		/// キー指定コンセプト
		/// </summary>
		template<typename T>
		concept HasKeyValue = requires(const T & value) {

			/*
			[ key_value ] というメンバー変数があり
			それが [ std::uint32_t ] であることを保証する
			*/

			{ value.key_value } -> std::same_as<std::uint32_t>;
		};
	}

	/* ========== キー変換基底クラス定義 ========== */

	/// <summary>
	/// キー変換基底クラス
	/// </summary>
	/// <details>
	/// [ 変換する型 ] の制約を示す, [ 可逆性とアルゴリズム ] は派生で示す
	/// </details>
	/// <typeparam name="T">エンコードするキー</typeparam>
	/// <typeparam name="U">デコードするキー</typeparam>
	template<concepts::HasKeyValue T, concepts::HasKeyValue U>
	class KeyConverterBase
	{
	public:
		/* ===== メンバー関数 ===== */

		//	通常コンストラクタ削除
		KeyConverterBase() = delete;

		/// <summary>
		/// 引数付きコンストラクタ
		/// </summary>
		/// <param name="convert">変換定数</param>
		explicit KeyConverterBase(std::uint32_t convert) :
			conversion_constant{ convert }{}

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~KeyConverterBase() = default;
		
		/// <summary>
		/// エンコード関数
		/// </summary>
		/// <param name="value">エンコードしたいキー</param>
		/// <returns>エンコードされたキー</returns>
		virtual [[nodiscard]] U encode_key(const T& value) const = 0;

		/// <summary>
		/// デコード関数
		/// </summary>
		/// <param name="value">デコードしたいキー</param>
		/// <returns>デコードされたキー</returns>
		virtual [[nodiscard]] T decode_key(const U& value) const = 0;

	protected:
		/* ===== メンバー変数 ===== */

		/// <summary>
		/// 変換定数
		/// </summary>
		const std::uint32_t conversion_constant{};

	};
}