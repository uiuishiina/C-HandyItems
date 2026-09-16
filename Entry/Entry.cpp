#include<iostream>
#include"../ItemsHeader/Math/BaseStruct/Transform.h"
#include"../ItemsHeader/Math/Function/MathFQuaternion.h"
#include"../ItemsHeader/Math/Function/MathFMatrix.h"
#include <iomanip>

using namespace std;
using namespace HandyItem::Math;

int main() {

	
	Transform trans{};
	trans.translate({ 10,0,0 });
	trans.rotate({ 0,MathF::HALF_PI,0 });
	trans.scale_by({ 2,3,4 });

	auto mat = trans.get_matrix();

	cout << "mat[0].x_ = " << mat[0].x_ << endl;
	cout << "mat[0].y_ = " << mat[0].y_ << endl;
	cout << "mat[0].z_ = " << mat[0].z_ << endl;
	cout << "mat[0].w_ = " << mat[0].w_ << endl << endl;

	cout << "mat[1].x_ = " << mat[1].x_ << endl;
	cout << "mat[1].y_ = " << mat[1].y_ << endl;
	cout << "mat[1].z_ = " << mat[1].z_ << endl;
	cout << "mat[1].w_ = " << mat[1].w_ << endl << endl;

	cout << "mat[2].x_ = " << mat[2].x_ << endl;
	cout << "mat[2].y_ = " << mat[2].y_ << endl;
	cout << "mat[2].z_ = " << mat[2].z_ << endl;
	cout << "mat[2].w_ = " << mat[2].w_ << endl << endl; 
	
	cout << "mat[3].x_ = " << mat[3].x_ << endl;
	cout << "mat[3].y_ = " << mat[3].y_ << endl;
	cout << "mat[3].z_ = " << mat[3].z_ << endl;
	cout << "mat[3].w_ = " << mat[3].w_ << endl << endl;
	
	return 0;
}