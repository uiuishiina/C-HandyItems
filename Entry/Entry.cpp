#include<iostream>
#include"../ItemsHeader/Math/BaseStruct/Transform.h"
#include <iomanip>

using namespace std;
using namespace HandyItem::Math;

int main() {

	
	Transform trans{};
	trans.translation_ = { 10,0,0 };

	const auto mat = trans.get_matrix();

	const auto pos = MathF::translation_from_matrix(mat);

	cout << "pos.x_ = " << pos.x_ << endl;
	cout << "pos.y_ = " << pos.y_ << endl;
	cout << "pos.z_ = " << pos.z_ << endl;
	
	
	return 0;
}