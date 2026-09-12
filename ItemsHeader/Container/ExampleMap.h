#pragma once
#include"KeyMap.h"
#include"../Enum/EnumArray.h"
#include"../Key/FeistelKeyConverter.h"


enum class AAA {
	A,
	B,
	C,

	Count
};

struct BBB {
	std::uint32_t key_value{};
	int* i_{};
};


/// <summary>
/// 便利アイテム名前空間
/// </summary>
namespace HandyItem {

	/// <summary>
	/// コンテナ用名前空間
	/// </summary>
	namespace container {

		template<typename Value>
		class ExMap
		{
		public:

			[[nodiscard]] bool add_value(const AAA& Enum, const Value& value) {

				key::DefaultKey key{};
				key.key_value = Enum::enum_to_index(Enum);

				return map_.add_value(key, value);
			}

			[[nodiscard]] std::optional<Value> get_value(const AAA& key) const noexcept {
				return map_.get_value(enum_array[key]);
			}

			[[nodiscard]] std::optional<Value> get_value(const BBB& key) const noexcept {
				return map_.get_value(key);
			}

		private:

			KeyMap<key::DefaultKey, BBB, Value, key::FeistelKeyConverter<key::DefaultKey, BBB>> map_{};

			Enum::EnumArray<AAA, key::DefaultKey> enum_array{};
		};
	}
}