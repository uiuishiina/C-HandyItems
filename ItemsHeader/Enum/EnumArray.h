#pragma once
#include"EnumToIndex.h"
#include<array>

/// <summary>
/// 列挙体名前空間
/// </summary>
namespace Enum {


	template<concepts::EnumHasCount Enum, typename Value>
	struct EnumArray {

		/// <summary>
		/// 保存配列
		/// </summary>
		std::array<Value, enum_to_index(Enum::Count)> array_{};

		EnumArray() = default;

		Value& operator[](Enum value){
			return array_[enum_to_index(value)];
		}

		Value& operator[](std::size_t value) {
			return array_[value];
		}
	};
}