// UnitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "MathLib.h"
// Vector2 Tests
TEST(vector2, equality)
{
	Vector2 v1;
	Vector2 v2;
	EXPECT_TRUE(v1 == v2);
}

TEST(vector2, copying)
{
	Vector2 v1(6, 5);
	Vector2 v2(v1);
	EXPECT_TRUE(v1 == v2);
}

TEST(vector2, addition)
{
	Vector2 v1(6, 5);
	Vector2 v2(6, 5);
	Vector2 v3(12, 10);
	v1 = v2 + v1;
	EXPECT_TRUE(v1 == v3);
}

TEST(vector2, subtraction)
{
	Vector2 v1(6, 5);
	Vector2 v2(6, 5);
	Vector2 v3;
	v1 = v2 - v1;
	EXPECT_TRUE(v1 == v3);
}

TEST(vector2, scalar)
{
	Vector2 v1(6, 5);
	Vector2 v3(12, 10);
	v1 = v1 * 2;
	EXPECT_TRUE(v1 == v3);
}

TEST(vector2, multiplication)
{
	Vector2 v1(6, 5);
	Vector2 v2(2, 2);
	Vector2 v3(12, 10);
	v1 = v1 * v2;
	EXPECT_TRUE(v1 == v3);
}

TEST(vector2, magnitude)
{
	Vector2 v1(4, 5);
	float magnitude = 6.4031;
	EXPECT_NEAR(magnitude, v1.Magnitude(), .0001);
}

TEST(vector2, dotproduct)
{
	Vector2 v1(2, 3);
	Vector2 v2(4, 5);
	float dotProduct = v1.DotProduct(v2);
	float expectedResult = 23;
	EXPECT_TRUE(dotProduct == expectedResult);
}

TEST(vector2, vectordistance)
{
	Vector2 v1(2, 3);
	Vector2 v2(4, 5);
	float distance = v1.VectorDistance(v2);
	float expectedResult = sqrt(8);
	EXPECT_TRUE(distance == expectedResult);
}

TEST(vector2, lerp)
{
	Vector2 v1(0,0);
	Vector2 v2(5,5);
	v1 = v1.Lerp(v2, .5f);
	Vector2 result(2.5, 2.5);

	EXPECT_TRUE(v1 == result);
	
	v1 = Vector2(5,5);
	v2 = Vector2(2,2);
	v1 = v1.Lerp(v2, .5f);
	result = Vector2(3.5, 3.5);

	EXPECT_TRUE(v1 == result);
	
}

TEST(vector2, lerp2vectors)
{
	Vector2 v1(0,0);
	Vector2 v2(5,5);
	Vector2 result(2.5, 2.5);

	EXPECT_TRUE(Vector2::Lerp(v1, v2, .5f) == result);
}

// Vector3 Tests
TEST(vector3, equality)
{
	Vector3 v1(1,2,3);
	Vector3 v2(1,2,3);
	EXPECT_TRUE(v1 == v2);
}

TEST(vector3, copying)
{
	Vector3 v1(6, 5, 7);
	Vector3 v2(v1);
	EXPECT_TRUE(v1 == v2);
}

TEST(vector3, addition)
{
	Vector3 v1(6, 5, 7);
	Vector3 v2(6, 5, 7);
	Vector3 v3(12, 10, 14);
	v1 = v2 + v1;
	EXPECT_TRUE(v1 == v3);
}

TEST(vector3, subtraction)
{
	Vector3 v1(6, 5, 2);
	Vector3 v2(6, 5, 2);
	Vector3 v3;
	v1 = v2 - v1;
	EXPECT_TRUE(v1 == v3);
}

TEST(vector3, scalar)
{
	Vector3 v1(6, 5, 3);
	Vector3 v3(12, 10, 6);
	v1 = v1 * 2;
	EXPECT_TRUE(v1 == v3);
}

TEST(vector3, multiplication)
{
	Vector3 v1(6, 5, 4);
	Vector3 v2(2, 2, 3);
	Vector3 v3(12, 10, 12);
	v1 = v1 * v2;
	EXPECT_TRUE(v1 == v3);
}

TEST(vector3, magnitude)
{
	Vector3 v1(4, 5, 6);
	float magnitude = sqrt(77);
	EXPECT_NEAR(magnitude, v1.Magnitude(), .0001);
}

TEST(vector3, dotproduct)
{
	Vector3 v1(2, 3, 6);
	Vector3 v2(4, 5, 3);
	float dotProduct = v1.DotProduct(v2);
	float expectedResult = 41;
	EXPECT_TRUE(dotProduct == expectedResult);
}

TEST(vector3, vectordistance)
{
	Vector3 v1(2, 3, -10);
	Vector3 v2(4, 5, 2);
	float distance = v1.VectorDistance(v2);
	float expectedResult = 12.328828005938;
	EXPECT_TRUE(distance == expectedResult);
}

TEST(vector3, crossproduct)
{
	Vector3 v1(3,2,-6);
	Vector3 v2(6, -1, 4);
	Vector3 v3 = v1.CrossProduct(v2);
	Vector3 v4(2, -48, -15);

	EXPECT_TRUE(v3 == v4);
}

TEST(vector3, lerp)
{
	Vector3 v1(0, 0, 0);
	Vector3 v2(5, 5, 5);
	v1 = v1.Lerp(v2, .5f);
	Vector3 result(2.5, 2.5, 2.5);

	EXPECT_TRUE(v1 == result);

	v1 = Vector3(5, 5, 5);
	v2 = Vector3(2, 2, 2);
	v1 = v1.Lerp(v2, .5f);
	result = Vector3(3.5, 3.5, 3.5);

	EXPECT_TRUE(v1 == result);
}

TEST(vector3, lerp2vectors)
{
	Vector3 v1(0, 0, 0);
	Vector3 v2(5, 5, 5);
	Vector3 result(2.5, 2.5, 2.5);

	EXPECT_TRUE(Vector3::Lerp(v1, v2, .5f) == result);
}

// Matrix3 tests
TEST(matrix3, transpose)
{
	Matrix3 m1(
		00,01,02,
		10,11,12,
		20,21,22);
	Matrix3 m2(
		00,10,20,
		01,11,21,
		02,12,22);
	m1.Transpose();
	EXPECT_TRUE(m1 == m2);
}

TEST(matrix3, assignment)
{
	Matrix3 m1(
		05, 05, 05,
		05, 05, 05,
		05, 05, 05);
	Matrix3 m2(
		05, 05, 05,
		05, 05, 05,
		05, 05, 05);
	Matrix3 m3(m2);
	EXPECT_TRUE(m1 == m3);
}

TEST(matrix3, addition)
{
	Matrix3 m1(
		05, 05, 05,
		05, 05, 05,
		05, 05, 05);
	Matrix3 m2(
		03, 03, 03,
		03, 03, 03,
		03, 03, 03);
	Matrix3 m3(
		02, 02, 02,
		02, 02, 02,
		02, 02, 02);

	m2 = m2 + m3;
	EXPECT_TRUE(m1 == m2);
}

TEST(matrix3, subtraction)
{
	Matrix3 m1(
		05,05,05,
		05,05,05,
		05,05,05);
	Matrix3 m2(
		03,03,03,
		03,03,03,
		03,03,03);
	Matrix3 m3(
		02,02,02,
		02,02,02, 
		02,02,02);
	m1 = m1 - m2;
	EXPECT_TRUE(m1 == m3);
}

TEST(matrix3, multiplication)
{
	Matrix3 m1(
		00, 01, 02,
		03, 04, 05,
		06, 07, 10);
	Matrix3 m2(
		00, 01, 02,
		03, 04, 05,
		06, 07, 10);
	Matrix3 m3(
		15, 18, 25,
		42, 54, 76,
		81, 104, 147);
	m1 = m1 * m2;
	EXPECT_TRUE(m1 == m3);
}

TEST(matrix3, GetTranslationMatrix)
{
	Vector2 v1(3, -7);
	Matrix3 m = m.GetTranslationMatrix(v1);
	Matrix3 solution(
		1, 0, 3,
		0, 1, -7,
		0, 0, 1);
	EXPECT_TRUE(m == solution);
}

TEST(matrix3, GetRotationMatrix)
{
	float x = 0;
	Matrix3 m1 = m1.GetRotationMatrix(x);
	Matrix3 m2(
		cos(x), -sin(x), 0,
		sin(x), cos(x), 0,
		0, 0, 1);

	EXPECT_TRUE(m1 == m2);
}

//Matrix4 Tests
TEST(matrix4, makingMatrices)
{
	Matrix4 m2(00, 01, 02, 03,
		10, 11, 12, 13,
		20, 21, 22, 23,
		30, 31, 32, 33);
	Matrix4	m1(m2);
	EXPECT_TRUE(m1 == m2);

	m1 = m1 + m2;
	Matrix4 result(00, 02, 04, 06,
		20, 22, 24, 26,
		40, 42, 44, 46,
		60, 62, 64, 66);
	EXPECT_TRUE(m1 == result);

	m1 = m1 - m2;
	result = m2;
	EXPECT_TRUE(m1 == result);
}

TEST(matrix4, identitymatrix)
{
	Matrix4 m1(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	Matrix4 iD;
	iD.Identity();
	EXPECT_TRUE(m1 == iD);
}

TEST(matrix4, multiplication)
{
	Matrix4 m1(2, 2, 2, 2,
		4, 4, 4, 4,
		6, 6, 6, 6,
		8, 8, 8, 8);
	Matrix4 m2(m1);
	Matrix4 result(40, 40, 40, 40,
		80, 80, 80, 80,
		120, 120, 120, 120,
		160, 160, 160, 160);
	m1 = m1 * m2;
	EXPECT_TRUE(m1 == result);
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	/*The method is initializes the Google framework and must be called before RUN_ALL_TESTS */
	::testing::InitGoogleTest(&argc, argv);

	/*RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro.
	It's must be called only once in the code because multiple calls lead to conflicts and,
	therefore, are not supported.
	*/
	RUN_ALL_TESTS();
	system("pause");
	return 0;
	
}
