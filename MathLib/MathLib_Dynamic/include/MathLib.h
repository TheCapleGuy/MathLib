#ifdef MATHLIB_EXPORTS
#define MATHLIBDLL_API __declspec(dllexport) 
#else
#define MATHLIBDLL_API __declspec(dllimport) 
#endif

#ifndef _MATHLIB_H_
#define _MATHLIB_H_

#define _USE_MATH_DEFINES
#include <cmath>
#include <ostream>



// 2 Dimentional Vector Math
class MATHLIBDLL_API Vector2
{
public:
	float scalar;
	float x, y;
	/*Vector2 void construct*/
	Vector2();
	/*Vector2 construct with 2 floats; x and y*/
	Vector2(float a_x, float a_y);
	/*Vector2 construct from another vector2*/
	Vector2(Vector2& a_RHS);
	~Vector2();
	
	/*Vector2 addition Vector2 = Vector2 + Vector2*/
	Vector2 operator+(Vector2& other);
	/*Vector2 subtraction Vector2 = Vector2 - Vector2*/
	Vector2 operator-(Vector2& other);
	/*Vector multiplication with a scalar*/
	Vector2 operator*(float a_scalar);
	/*Vector multiplication with another vector2*/
	Vector2 operator*(Vector2& other);
	/*Vector assigning*/
	void operator=(Vector2& other);

	/*checking if two vectors have equivelent values*/
	bool operator==(Vector2& a_RHS);
	/*Vector2 addition Vector2 += Vector2*/
	Vector2 operator+=(Vector2& a_RHS);
	/*Vector2 subtraction Vector2 -= Vector2*/
	Vector2 operator-=(Vector2& a_RHS);
	/*Vector multiplication Vector2*= Vector2*/
	Vector2 operator*=(Vector2& a_RHS);
	
	/*gets magnitude of vector2 and returns it in a float*/
	float Magnitude();
	/*Normalizes a vector2's values*/
	void Normalise();
	/*Gets the normalized values of Vector2*/
	Vector2 GetNormal();
	/*finds distance between two vectors, takes in vector for rhs*/
	float VectorDistance(Vector2& other);
	/*finds dot product of two vectors, takes in vector for rhs*/
	float DotProduct(Vector2& other);
	/*finds cross product of two vectors, takes in vector for rhs*/
	Vector2 CrossProduct(Vector2& a_RHS);
	/*Lerping between two vectors. 
	takes in second vector and percentage between the vectors, percent between 0-1*/
	Vector2 Lerp(Vector2& end, const float percentage);
	/*static function that takes in two vectors and a percent to Lerp between
	percent between 0-1, or 0 and 100%*/
	static Vector2 Lerp(Vector2& begin, Vector2& end, const float percentage);
};
// 3 Dimentional Vector Math
class MATHLIBDLL_API Vector3
{
public:
	float x, y, z;
	float scalar;
	/*Vector3 void construct*/
	Vector3();
	/*Vector3 construct with 3 floats; x, y, and z*/
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();

	/*Vector3 addition Vector3 = Vector3 + Vector3*/
	Vector3 operator+(Vector3 &other);
	/*Vector3 subtraction Vector3 = Vector3 - Vector3*/
	Vector3 operator-(Vector3 &other);
	/*Vector multiplication with a scalar*/
	Vector3 operator*(float a_scalar);
	/*Vector multiplication with another vector3*/
	Vector3 operator*(Vector3 &other);
	/*Vector assigning*/
	void operator=(Vector3 &other);

	/*checking if two vectors have equivelent values*/
	bool operator==(Vector3& a_RHS);
	/*gets magnitude of vector3 and returns it in a float*/
	float Magnitude();
	/*Normalizes a vector3's values*/
	void Normalise();
	/*Gets the normalized values of Vector3*/
	Vector3 GetNormal();
	/*finds distance between two vectors, takes in vector for rhs*/
	float VectorDistance(Vector3 &other);
	/*finds dot product of two vectors, takes in vector for rhs*/
	float DotProduct(Vector3 &other);
	/*finds cross product of two vectors, takes in vector for rhs*/
	Vector3 CrossProduct(Vector3& a_RHS);
	/*Lerping between two vectors.
	takes in second vector and percentage between the vectors, percent between 0-1*/
	Vector3 Lerp(Vector3& end, const float percentage);
	/*static function that takes in two vectors and a percent to Lerp between
	percent between 0-1, or 0 and 100%*/
	static Vector3 Lerp(Vector3& begin, Vector3& end, const float percentage);

};
// 2 Dimentional Matrix Math
class MATHLIBDLL_API Matrix3
{
public:
	/*Matrix3 void construct*/
	Matrix3();
	/*Matrix3 construct. hard code 9 float values for matrix in row major order
	00, 01, 02,
	10, 11, 12,
	20, 21, 22*/
	Matrix3(float const m00, float const m01, float const m02,
			float const m10, float const m11, float const m12,
			float const m20, float const m21, float const m22);
	/*Matrix3 construct. copies existing Matrix3*/
	Matrix3(Matrix3& a_RHS);

	~Matrix3();
	/*Identity Matrix:
	1,0,0
	0,1,0
	0,0,1*/
	void Identity();

	/*Transposes a matrix3*/
	Matrix3& Transpose();
	/*gets transposed values of a matrix3*/
	Matrix3 GetTranspose();

	/*assigning Matrix*/
	Matrix3& operator =(const Matrix3& a_RHS);
	/*adding to Matrices together Matrix1 = Matrix1 + Matrtix2*/
	Matrix3 operator +(Matrix3& a_RHS);
	/*subtracting to Matrices together Matrix1 = Matrix1 - Matrtix2*/
	Matrix3 operator -(Matrix3& a_RHS);
	/*multiplying to Matrices together Matrix1 = Matrix1 * Matrtix2*/
	Matrix3 operator *(Matrix3& a_RHS);

	/*checking wether or not two Matrices are equivilent*/
	bool operator ==(Matrix3& a_RHS);
	Matrix3 operator +=(Matrix3& a_RHS);
	Matrix3 operator -=(Matrix3& a_RHS);
	Matrix3 operator *=(Matrix3& a_RHS);

	/*Gets Translation from Vector2 values*/
	Matrix3 GetTranslationMatrix(Vector2& a_RHS);
	/*Uses Matrix, takes theta in radians:0-6.28*/
	Matrix3 GetRotationMatrix(float theta);

	float m_matrixArray[3][3];

};
// 3 dimentional Matrix Math
class MATHLIBDLL_API Matrix4
{
public:
	/*Matrix3 void construct*/
	Matrix4();
	/*Matrix4 construct. hard code 12 float values for matrix in row major order
	00, 01, 02, 03,
	10, 11, 12, 13, 
	20, 21, 22, 23,
	30, 31, 32, 33*/
	Matrix4(float const m00, float const m01, float const m02, float const m03,
			float const m10, float const m11, float const m12, float const m13,
			float const m20, float const m21, float const m22, float const m23,
			float const m30, float const m31, float const m32, float const m33);
	/*Copies an existing Matrix4*/
	Matrix4(Matrix4& a_RHS);
	/*Creates a Matrix4 identity Matrix
	1,0,0,0,
	0,1,0,0,
	0,0,1,0,
	0,0,0,1*/
	void Identity();
	
	/*Matrix4 orthographic projection*/
	Matrix4 OrthoProjection(const float right, const float left, const float top, const float bottom, const float far, const float near);
	/*Combines All set up rotation functions*/
	Matrix4 RotationMatrix(float xRotation, float yRotation, float zRotation);
	/*rotates Matrix4 on X-axis theta in terms of radians*/
	static Matrix4 SetupRotationX(float theta);
	/*rotates Matrix4 on Y-axis theta in terms of radians*/
	static Matrix4 SetupRotationY(float theta);
	/*rotates Matrix4 on Z-axis theta in terms of radians*/
	static Matrix4 SetupRotationZ(float theta);
	/*Checks if Matrices are equivilent*/
	bool operator==(Matrix4& a_RHS);
	/*assigns Matrices to be equal*/
	Matrix4 operator=(Matrix4& a_RHS);
	/*overloads the cout << to print out all Matrix4 values as stored*/
	MATHLIBDLL_API friend std::ostream& operator<<(std::ostream& out, Matrix4& a_RHS);
	/*addition overloader*/
	Matrix4 operator+(Matrix4& a_RHS);
	/*subtraction overloader*/
	Matrix4 operator-(Matrix4& a_RHS);
	/*multiplication overloader*/
	Matrix4 operator*(Matrix4& a_RHS);
	
	
	float m_matrixArray[4][4];
	~Matrix4();
};
// Vector 4 Math
class MATHLIBDLL_API Vector4
{
public:
	float x, y, z, w;
	/*constructs a vector4 with all float values equaling 0*/
	Vector4(){ x = 0.f; y = 0.f; z = 0.f; w = 0.f; }
	/*constructs empty Vector4 with x,y,z,w values*/
	Vector4(float a_x, float a_y, float a_z, float a_w);
	/*Vector assigning*/
	void operator=(Vector4& a_RHS);
	
	/*Checking values of two vector4s*/
	bool operator==(Vector4& a_RHS);
	/*overloads the cout << to print out all Vector4 values as stored*/
	MATHLIBDLL_API friend std::ostream& operator<<(std::ostream& out, const Vector4& a_RHS);
	/*addition overloader*/
	Vector4 operator+(Vector4& a_RHS);
	/*subtraction overloader*/
	Vector4 operator-(Vector4& a_RHS);
	/*multiplication overloader with a scalar value*/
	Vector4 operator*(float a_scalar);
	/*multiplication overloader with another Vector4*/
	Vector4 operator*(Vector4& a_RHS);

	~Vector4(){}
	/*Finds the dot product of this vector and a rhs vector*/
	float DotProduct(Vector4& a_RHS);
	/*gets magnitude of vector4 and returns it in a float*/
	float Magnitude();
	/*Normalizes a vector4's values*/
	void Normalise();
	/*takes in integers as color values and returns a single int using binary operations
	to make a 0xffffffff hexadecimal color value. */
	static Vector4 HexaColor(unsigned int hexa);
};
//Misc Math
class MATHLIBDLL_API MiscMath
{
public:
	/*percent between 0 and 1. 1 being 100%*/
	static float LERP(float begin, float end, float percent){ return begin + (end - begin) * percent; }
	/*Converts andle in degrees between 0-360 into radians*/
	static float degreesToRadians(float angleInDegs);
	/*Converts angle in radians between 0 and 6.28318 (0-2PI) into degrees*/
	static float radiansToDegrees(float angleInRads);
	/*Bool that checks if ScalarValue is a power of two*/
	static bool CheckPowerOfTwo(unsigned int ScalarValue);
	/*finds next highest power of two of 32-bit from ScalarValue */
	static unsigned int ShiftingPowerOfTwo(unsigned int ScalarValue);
};
#endif