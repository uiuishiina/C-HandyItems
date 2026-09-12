#include<iostream>
#include"../ItemsHeader/Math/Function/MathFQuaternion.h"
#include"../ItemsHeader/Math/Function/MathFMatrix.h"
#include <iomanip>

using namespace std;
using namespace HandyItem;

int main() {

	Math::Quaternion Q_{}, q_{};

	q_ = Math::from_axis_angle(
		{ 0.0f, 1.0f, 0.0f },
		Math::MathF::HALF_PI
	);

	const auto result = Math::lerp(Q_, q_, 0.5f);

	std::cout << "Q_.x_ = " << Q_.x_ << endl;
	std::cout << "Q_.y_ = " << Q_.y_ << endl;
	std::cout << "Q_.z_ = " << Q_.z_ << endl;
	std::cout << "Q_.w_ = " << Q_.w_ << endl << endl;

	std::cout << "result = " << result.length() << endl;

	//std::cout << "q_.x_ = " << q_.x_ << endl;
	//std::cout << "q_.y_ = " << q_.y_ << endl;
	//std::cout << "q_.z_ = " << q_.z_ << endl;
	//std::cout << "q_.w_ = " << q_.w_ << endl << endl;

	std::cout << "result.x_ = " << result.x_ << endl;
	std::cout << "result.y_ = " << result.y_ << endl;
	std::cout << "result.z_ = " << result.z_ << endl;
	std::cout << "result.w_ = " << result.w_ << endl << endl;

	return 0;
}