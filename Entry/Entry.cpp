#include<iostream>
#include"../ItemsHeader/Container/UnorderedMapBase.h"

using namespace std;

int main() {

	container::UnorderedMapBase<int, bool> con{};
	con.add_value(1, true);
	if (con.get_value(1).value()) {
		cout << "Hello HandyItems" << endl;
	}

	return 0;
}