#include "MathLib.h"

Matrix3::Matrix3()
{
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			m_matrixArray[col][row] = 0;
		}
	}
}

Matrix3::Matrix3(float const m00,
				float const m01,
				float const m02,
				float const m10,
				float const m11,
				float const m12,
				float const m20,
				float const m21,
				float const m22)
{
	m_matrixArray[0][0] = m00;
	m_matrixArray[0][1] = m01;
	m_matrixArray[0][2] = m02;
	m_matrixArray[1][0] = m10;
	m_matrixArray[1][1] = m11;
	m_matrixArray[1][2] = m12;
	m_matrixArray[2][0] = m20;
	m_matrixArray[2][1] = m21;
	m_matrixArray[2][2] = m22;
}

Matrix3::Matrix3(Matrix3& a_RHS)
{
	*this = a_RHS;
}

Matrix3& Matrix3::operator=(const Matrix3& a_RHS)
{
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			m_matrixArray[col][row] = a_RHS.m_matrixArray[col][row];
		}
	}
	return *this;
}

Matrix3 Matrix3::operator+(Matrix3& a_RHS)
{
	Matrix3 temp;
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			temp.m_matrixArray[col][row] = m_matrixArray[col][row] + a_RHS.m_matrixArray[col][row];
		}
	}
	return temp;
}

Matrix3 Matrix3::operator -(Matrix3& a_RHS)
{
	Matrix3 temp;
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			temp.m_matrixArray[col][row] = m_matrixArray[col][row] - a_RHS.m_matrixArray[col][row];
		}
	}
	return temp;
}

Matrix3 Matrix3::operator*(Matrix3 & a_RHS)
{
	Matrix3 temp;
	//vectors of the matrix by row
	Vector3 row1(m_matrixArray[0][0], m_matrixArray[0][1], m_matrixArray[0][2]);
	Vector3 row2(m_matrixArray[1][0], m_matrixArray[1][1], m_matrixArray[1][2]);
	Vector3 row3(m_matrixArray[2][0], m_matrixArray[2][1], m_matrixArray[2][2]);

	//vectors of the multiplying matrix's columns
	Vector3 col1(a_RHS.m_matrixArray[0][0], a_RHS.m_matrixArray[1][0], a_RHS.m_matrixArray[2][0]);
	Vector3 col2(a_RHS.m_matrixArray[0][1], a_RHS.m_matrixArray[1][1], a_RHS.m_matrixArray[2][1]);
	Vector3 col3(a_RHS.m_matrixArray[0][2], a_RHS.m_matrixArray[1][2], a_RHS.m_matrixArray[2][2]);

	// final matrix by columns
	//column 1
	temp.m_matrixArray[0][0] = row1.DotProduct(col1);
	temp.m_matrixArray[0][1] = row1.DotProduct(col2);
	temp.m_matrixArray[0][2] = row1.DotProduct(col3);
	//column 2
	temp.m_matrixArray[1][0] = row2.DotProduct(col1);
	temp.m_matrixArray[1][1] = row2.DotProduct(col2);
	temp.m_matrixArray[1][2] = row2.DotProduct(col3);
	//column 3
	temp.m_matrixArray[2][0] = row3.DotProduct(col1);
	temp.m_matrixArray[2][1] = row3.DotProduct(col2);
	temp.m_matrixArray[2][2] = row3.DotProduct(col3);

	return temp;
}

bool Matrix3::operator==(Matrix3& a_RHS)
{
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			if (m_matrixArray[col][row] != a_RHS.m_matrixArray[col][row])
			{
				return false;
			}

		}
	}
	return true;
}

Matrix3 Matrix3::Identity()
{
	Matrix3 temp;
	for (int i = 0; i < 3; i++)
	{
		temp.m_matrixArray[i][i] = 1;
	}
	return temp;
}

Matrix3& Matrix3::Transpose()
{
	Matrix3 temp;
	temp.m_matrixArray[0][0] = m_matrixArray[0][0];
	temp.m_matrixArray[0][1] = m_matrixArray[1][0];
	temp.m_matrixArray[0][2] = m_matrixArray[2][0];

	temp.m_matrixArray[1][0] = m_matrixArray[0][1];
	temp.m_matrixArray[1][1] = m_matrixArray[1][1];
	temp.m_matrixArray[1][2] = m_matrixArray[2][1];

	temp.m_matrixArray[2][0] = m_matrixArray[0][2];
	temp.m_matrixArray[2][1] = m_matrixArray[1][2];
	temp.m_matrixArray[2][2] = m_matrixArray[2][2];
	
	*this = temp;
	return *this;
}

Matrix3 Matrix3::GetTranspose()
{
	Matrix3 result = *this;
	return result.Transpose();
	
}
 
Matrix3 Matrix3::GetTranslationMatrix(Vector2& a_RHS)
{
	Matrix3 m = Identity();
	m.m_matrixArray[0][2] = a_RHS.x;
	m.m_matrixArray[1][2] = a_RHS.y;
	return m;
}

Matrix3 Matrix3::GetRotationMatrix(float theta)
{
	Matrix3 RotateMatrix(
		cos(theta), -sin(theta), 0,
		sin(theta), cos(theta), 0,
		0, 0, 1);
	return RotateMatrix;
}

Matrix3::~Matrix3()
{

}