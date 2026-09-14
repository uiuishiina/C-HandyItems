#include<iostream>
#include"../ItemsHeader/Math/Function/MathFMatrix.h"
#include <iomanip>

using namespace std;
using namespace HandyItem::Math;

int main() {

	Matrix matrix{ 
		Float4{ 1.0f, 2.0f, 3.0f, 4.0f },
		Float4{ 0.0f, 1.0f, 2.0f, 3.0f },
		Float4{ 0.0f, 0.0f, 1.0f, 2.0f },
		Float4{ 0.0f, 0.0f, 0.0f, 1.0f }
	};

	const auto result = matrix.inverse();

	if (result.has_value()) {

		const auto value = result.value();

		cout << "value[0][0] = " << value[0][0] << endl;
		cout << "value[1][1] = " << value[1][1] << endl;
		cout << "value[2][2] = " << value[2][2] << endl;
		cout << "value[3][3] = " << value[3][3] << endl;

		const auto iden = matrix * value;
		const auto iden2 = value * matrix;
		cout << "is_identity = " << iden.is_identity() << endl;
		cout << "is_identity = " << iden2.is_identity() << endl;
	}
	
	return 0;
}