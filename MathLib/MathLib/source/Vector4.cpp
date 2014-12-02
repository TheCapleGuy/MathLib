#include "MathLib.h"

Vector4::Vector4(float a_x, float a_y, float a_z, float a_w)
{
	x = a_x;
	y = a_y;
	z = a_z;
	w = a_w;
}

float Vector4::DotProduct(Vector4& a_RHS)
{
	Vector4 temp = *this;

	return ((temp.x * a_RHS.x) + (temp.y * a_RHS.y) + (temp.z * a_RHS.z) + (temp.w * a_RHS.w));
}

Vector4::~Vector4()
{

}