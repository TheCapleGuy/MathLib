#include "MathLib.h"

Vector4::Vector4(float a_x, float a_y, float a_z, float a_w)
{
	x = a_x;
	y = a_y;
	z = a_z;
	w = a_w;
}

void Vector4::operator=(Vector4& a_RHS)
{
	x = a_RHS.x;
	y = a_RHS.y;
	z = a_RHS.z;
	w = a_RHS.w;
}

bool Vector4::operator==(Vector4& a_RHS)
{
	Vector4 temp = *this;
	if (temp.x != a_RHS.x || temp.y != a_RHS.y || temp.z != a_RHS.z || temp.w != a_RHS.w)
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::ostream& operator<<(std::ostream& out, Vector4& a_RHS)
{
	
	out << "Vector4:" << "(" << a_RHS.x << ", " << a_RHS.y << ", " << a_RHS.z << ", " << a_RHS.w << ")" << std::endl;
	return out;
}


Vector4 Vector4::operator*(Vector4& a_RHS)
{
	Vector4 temp = *this;
	temp.x *= a_RHS.x;
	temp.y *= a_RHS.y;
	temp.z *= a_RHS.z;
	temp.w *= a_RHS.w;
	return temp;

}

Vector4 Vector4::operator*(float scalar)
{
	Vector4 temp = *this;
	temp.x *= scalar;
	temp.y *= scalar;
	temp.z *= scalar;
	temp.w *= scalar;
	return temp;
}

Vector4 Vector4::operator+(Vector4& a_RHS)
{
	Vector4 temp = *this;
	temp.x += a_RHS.x;
	temp.y += a_RHS.y;
	temp.z += a_RHS.z;
	temp.w += a_RHS.w;
	return temp;
}

Vector4 Vector4::operator-(Vector4& a_RHS)
{
	Vector4 temp = *this;
	temp.x -= a_RHS.x;
	temp.y -= a_RHS.y;
	temp.z -= a_RHS.z;
	temp.w -= a_RHS.w;
	return temp;
}

float Vector4::DotProduct(Vector4& a_RHS)
{
	Vector4 temp = *this;
	return ((temp.x * a_RHS.x) + (temp.y * a_RHS.y) + (temp.z * a_RHS.z) + (temp.w * a_RHS.w));
}

float Vector4::Magnitude()
{
	Vector4 temp = *this;
	float magnitude;
	temp.x *= temp.x;
	temp.y *= temp.y;
	temp.z *= temp.z;
	temp.w *= temp.w;
	magnitude = temp.x + temp.y + temp.z + temp.w;
	return sqrt(magnitude);
}

void Vector4::Normalise()
{
	x /= Magnitude();
	y /= Magnitude();
	z /= Magnitude();
	w /= Magnitude();
}