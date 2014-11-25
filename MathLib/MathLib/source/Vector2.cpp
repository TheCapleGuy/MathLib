#include "math.h"
#include "MathLib.h"

Vector2::Vector2()
{
	x = 0, y = 0;
}

Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

Vector2::Vector2(Vector2& a_RHS)
{
	x = a_RHS.x;
	y = a_RHS.y;
}

Vector2 Vector2::operator+(Vector2& other)
{
	Vector2 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	return temp;
}

Vector2 Vector2::operator-(Vector2& other)
{
	Vector2 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	return temp;

}

Vector2 Vector2::operator*(Vector2& other)
{
	Vector2 temp = *this;
	temp.x *= other.x;
	temp.y *= other.y;
	return temp;

}

void Vector2::operator=(Vector2& other)
{
	x = other.x;
	y = other.y;
}

Vector2 Vector2::operator*(float scalar)
{
	Vector2 temp = *this;
	temp.x *= scalar;
	temp.y *= scalar;
	return temp;
}

bool Vector2::operator==(Vector2& a_RHS)
{
	if (x != a_RHS.x || y != a_RHS.y)
	{
		return false;
	}
	else
	{
		return true;
	}
}

float Vector2::Magnitude()
{
	Vector2 temp = *this;
	float magnitude;
	temp.x *= temp.x;
	temp.y *= temp.y;
	magnitude = temp.x + temp.y;
	return sqrt(magnitude);
}

void Vector2::Normalise()
{
	x /= Magnitude();
	y /= Magnitude();

}

Vector2 Vector2::GetNormal()
{
	Vector2 temp = *this;
	temp.Normalise();
	return temp;
}

float Vector2::VectorDistance(Vector2& other)
{
	Vector2 temp = *this;
	return sqrt(pow(temp.x - other.x, 2.0f) +
		pow(temp.y - other.y, 2.0f));
}

float Vector2::DotProduct(Vector2& other)
{
	Vector2 temp = *this;

	return ((temp.x * other.x) + (temp.y * other.y));
}

Vector2::~Vector2()
{

}