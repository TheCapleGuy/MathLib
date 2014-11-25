#ifndef _MATHLIB_H_
#define _MATHLIB_H_
#include <math.h>

// 2 Dimentional Vector Math
class Vector2
{
public:
	float scalar;
	float x, y;
	Vector2();
	Vector2(float a_x, float a_y);
	Vector2(Vector2& a_RHS);
	~Vector2();
	Vector2 operator+(Vector2& other);
	Vector2 operator-(Vector2& other);
	Vector2 operator*(float a_scalar);
	Vector2 operator*(Vector2& other);
	void operator=(Vector2& other);

	bool operator==(Vector2& a_RHS);
	Vector2 operator+=(Vector2& a_RHS);
	Vector2 operator-=(Vector2& a_RHS);
	Vector2 operator*=(Vector2& a_RHS);
	

	float Magnitude();
	void Normalise();
	Vector2 GetNormal();
	float VectorDistance(Vector2& other);
	float DotProduct(Vector2& other);

};
// 3 Dimentional Vector Math
class Vector3
{
public:
	float x, y, z;
	float scalar;
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();
	Vector3 operator+(Vector3 &other);
	Vector3 operator-(Vector3 &other);
	Vector3 operator*(float a_scalar);
	Vector3 operator*(Vector3 &other);
	void operator=(Vector3 &other);

	bool operator==(Vector3& a_RHS);

	float Magnitude();
	void Normalise();
	Vector3 GetNormal();
	float VectorDistance(Vector3 &other);
	float DotProduct(Vector3 &other);

};
// 2 Dimentional Matrix Math
class Matrix3
{
public:
	Matrix3();
	Matrix3(float const m00,
		float const m01,
		float const m02,
		float const m10,
		float const m11,
		float const m12,
		float const m20,
		float const m21,
		float const m22);
	Matrix3(Matrix3& a_RHS);

	~Matrix3();

	static Matrix3 Identity();

	Matrix3& Transpose();

	Matrix3 GetTranspose();


	Matrix3& operator =(const Matrix3& a_RHS);
	Matrix3 operator +(Matrix3& a_RHS);
	Matrix3 operator -(Matrix3& a_RHS);
	Matrix3 operator *(Matrix3& a_RHS);

	bool operator ==(Matrix3& a_RHS);
	Matrix3 operator +=(Matrix3& a_RHS);
	Matrix3 operator -=(Matrix3& a_RHS);
	Matrix3 operator *=(Matrix3& a_RHS);

	Matrix3 GetTranslationMatrix(Vector2& a_RHS);
	Matrix3 GetRotationMatrix(float theta);

	float m_matrixArray[3][3];

};
// 3 dimentional Matrix Math

// Vector 4 Math

//Misc Math

#endif