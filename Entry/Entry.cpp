#include<iostream>
#include"../ItemsHeader/Container/KeyMap.h"
#include"../ItemsHeader/Key/FeistelKeyConverter.h"
#include"../ItemsHeader/Container/ReferenceQueue.h"

using namespace std;

struct A {
	std::uint32_t key_value{};
};
struct B {
	std::uint32_t key_value{};
};

HandyItem::key::FeistelKeyConverter<A, B> converter{};

void func(){
	A original(1);
	cout << converter.encode_key(original).key_value << endl;
}

int main() {

	HandyItem::container::ReferenceQueue<const int> onre;

	HandyItem::key::FeistelKeyConverter<A, B> converter{};
	A original{};
	A a{};
	original.key_value = 0x1;
	a.key_value = 0x2;

	
	cout << converter.encode_key(original).key_value << endl;

	func();

	cout << converter.encode_key(a).key_value << endl;

	HandyItem::container::KeyMap<A,B,bool, HandyItem::key::FeistelKeyConverter<A,B>> con{};
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