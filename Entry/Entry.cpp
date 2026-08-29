#include<iostream>
#include"../ItemsHeader/Container/KeyMap.h"
#include"../ItemsHeader/Key/FeistelKeyConverter.h"

using namespace std;

struct A {
	std::uint32_t key_value{};
};
struct B {
	std::uint32_t key_value{};
};

int main() {

	key::FeistelKeyConverter<A, B> converter{};
	A original{};
	original.key_value = 0x1;

	container::KeyMap<A,B,bool,key::FeistelKeyConverter<A,B>> con{};
	if (con.add_value(original, true)) {
		auto key = con.encode_key(original);
		if (auto value = con.get_value(key); value.has_value()) {
			if (value.value()) {
				cout << "Hello HandyItems" << endl;
			}
		}
	}
	

	return 0;
}