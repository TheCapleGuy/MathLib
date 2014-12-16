#include "MathLib.h"

Vector3::Vector3()
{
	x = 0, y = 0, z = 0;
}

Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}

Vector3 Vector3::operator+(Vector3 &other)
{
	Vector3 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	temp.z += other.z;
	return temp;
}

Vector3 Vector3::operator-(Vector3 &other)
{
	Vector3 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	temp.z -= other.z;
	return temp;

}

Vector3 Vector3::operator*(Vector3 &other)
{
	Vector3 temp = *this;
	temp.x *= other.x;
	temp.y *= other.y;
	temp.z *= other.z;
	return temp;

}

void Vector3::operator=(Vector3 &other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

bool Vector3::operator==(Vector3& a_RHS)
{
	if (x != a_RHS.x || y != a_RHS.y || z != a_RHS.z)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Vector3 Vector3::operator*(float scalar)
{
	Vector3 temp = *this;
	temp.x *= scalar;
	temp.y *= scalar;
	temp.z *= scalar;
	return temp;
}

float Vector3::Magnitude()
{
	Vector3 temp = *this;
	float magnitude;
	temp.x *= temp.x;
	temp.y *= temp.y;
	temp.z *= temp.z;
	magnitude = temp.x + temp.y + temp.z;
	return sqrt(magnitude);
}

void Vector3::Normalise()
{
	x /= Magnitude();
	y /= Magnitude();
	z /= Magnitude();

}

Vector3 Vector3::GetNormal()
{
	Vector3 temp = *this;
	temp.Normalise();
	return temp;
}

float Vector3::VectorDistance(Vector3 &other)
{
	Vector3 temp = *this;
	return sqrt(pow(temp.x - other.x, 2.0f) +
		pow(temp.y - other.y, 2.0f) +
		pow(temp.z - other.z, 2.0f));
}

float Vector3::DotProduct(Vector3 &other)
{
	Vector3 temp = *this;

	return ((temp.x * other.x) + (temp.y * other.y) + (temp.z * other.z));
}

Vector3 Vector3::CrossProduct(Vector3& a_RHS)
{
	Vector3 product;
	product.x = ((y * a_RHS.z) - (z * a_RHS.y));
	product.y = ((z * a_RHS.x) - (x * a_RHS.z));
	product.z = ((x * a_RHS.y) - (y * a_RHS.x));
	return product;
}

Vector3 Vector3::Lerp(Vector3& end, const float percentage)
{
	Vector3 begin = *this;
	return begin + (end - begin) * percentage;
}

Vector3 Vector3::Lerp(Vector3& begin, Vector3& end, const float percentage)
{
	return begin + (end - begin) * percentage;
}

Vector3::~Vector3()
{

}