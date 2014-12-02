#include "MathLib.h"

Matrix4::Matrix4()
{

}

Matrix4::Matrix4(float const m00, float const m01, float const m02, float const m03,
				 float const m10, float const m11, float const m12, float const m13,
				 float const m20, float const m21, float const m22, float const m23,
				 float const m30, float const m31, float const m32, float const m33)
{
	m_matrixArray[0][0] = m00, m_matrixArray[0][1] = m01, m_matrixArray[0][2] = m02, m_matrixArray[0][3] = m03;
	m_matrixArray[1][0] = m10, m_matrixArray[1][1] = m11, m_matrixArray[1][2] = m12, m_matrixArray[1][3] = m13;
	m_matrixArray[2][0] = m20, m_matrixArray[2][1] = m21, m_matrixArray[2][2] = m22, m_matrixArray[2][3] = m23;
	m_matrixArray[3][0] = m30, m_matrixArray[3][1] = m31, m_matrixArray[3][2] = m32, m_matrixArray[3][3] = m33;
}

Matrix4::Matrix4(Matrix4& a_RHS)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_matrixArray[i][j] = a_RHS.m_matrixArray[i][j];
		}
	}
}

void Matrix4::Identity()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				m_matrixArray[i][j] = 1;
			}
			else 
			{
				m_matrixArray[i][j] = 0;
			}
		}
	}
}

Matrix4 Matrix4::operator=(Matrix4& a_RHS)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_matrixArray[i][j] = a_RHS.m_matrixArray[i][j];
		}
	}
	return *this;
}

bool Matrix4::operator==(Matrix4& a_RHS)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_matrixArray[i][j] != a_RHS.m_matrixArray[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, Matrix4& a_RHS)
{
	out << "Matrix4*****************" << std::endl 
		<< a_RHS.m_matrixArray[0][0] << ", " << a_RHS.m_matrixArray[0][1] << ", " << a_RHS.m_matrixArray[0][2] << ", " << a_RHS.m_matrixArray[0][3] << std::endl <<
		   a_RHS.m_matrixArray[1][0] << ", " << a_RHS.m_matrixArray[1][1] << ", " << a_RHS.m_matrixArray[1][2] << ", " << a_RHS.m_matrixArray[1][3] << std::endl <<
	   	   a_RHS.m_matrixArray[2][0] << ", " << a_RHS.m_matrixArray[2][1] << ", " << a_RHS.m_matrixArray[2][2] << ", " << a_RHS.m_matrixArray[2][3] << std::endl <<
		   a_RHS.m_matrixArray[3][0] << ", " << a_RHS.m_matrixArray[3][1] << ", " << a_RHS.m_matrixArray[3][2] << ", " << a_RHS.m_matrixArray[3][3] << std::endl <<
		   "*********************" << std::endl;
	return out;
}

Matrix4 Matrix4::operator+(Matrix4& a_RHS)
{
	Matrix4 temp;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			temp.m_matrixArray[col][row] = m_matrixArray[col][row] + a_RHS.m_matrixArray[col][row];
		}
	}
	return temp;
}

Matrix4 Matrix4::operator-(Matrix4& a_RHS)
{
	Matrix4 temp;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			temp.m_matrixArray[col][row] = m_matrixArray[col][row] - a_RHS.m_matrixArray[col][row];
		}
	}
	return temp;
}

Matrix4 Matrix4::operator*(Matrix4& a_RHS)
{
	Matrix4 temp;
	//vectors of the matrix by row
	Vector4 row1(m_matrixArray[0][0], m_matrixArray[0][1], m_matrixArray[0][2], m_matrixArray[0][3]);
	Vector4 row2(m_matrixArray[1][0], m_matrixArray[1][1], m_matrixArray[1][2], m_matrixArray[1][3]);
	Vector4 row3(m_matrixArray[2][0], m_matrixArray[2][1], m_matrixArray[2][2], m_matrixArray[2][3]);
	Vector4 row4(m_matrixArray[3][0], m_matrixArray[3][1], m_matrixArray[3][2], m_matrixArray[3][3]);

	//vectors of the multiplying matrix's columns
	Vector4 col1(a_RHS.m_matrixArray[0][0], a_RHS.m_matrixArray[1][0], a_RHS.m_matrixArray[2][0], a_RHS.m_matrixArray[3][0]);
	Vector4 col2(a_RHS.m_matrixArray[0][1], a_RHS.m_matrixArray[1][1], a_RHS.m_matrixArray[2][1], a_RHS.m_matrixArray[3][1]);
	Vector4 col3(a_RHS.m_matrixArray[0][2], a_RHS.m_matrixArray[1][2], a_RHS.m_matrixArray[2][2], a_RHS.m_matrixArray[3][2]);
	Vector4 col4(a_RHS.m_matrixArray[0][3], a_RHS.m_matrixArray[1][3], a_RHS.m_matrixArray[2][3], a_RHS.m_matrixArray[3][3]);

	// final matrix by columns
	//column 1
	temp.m_matrixArray[0][0] = row1.DotProduct(col1);
	temp.m_matrixArray[0][1] = row1.DotProduct(col2);
	temp.m_matrixArray[0][2] = row1.DotProduct(col3);
	temp.m_matrixArray[0][3] = row1.DotProduct(col4);

	//column 2
	temp.m_matrixArray[1][0] = row2.DotProduct(col1);
	temp.m_matrixArray[1][1] = row2.DotProduct(col2);
	temp.m_matrixArray[1][2] = row2.DotProduct(col3);
	temp.m_matrixArray[1][3] = row2.DotProduct(col4);

	//column 3
	temp.m_matrixArray[2][0] = row3.DotProduct(col1);
	temp.m_matrixArray[2][1] = row3.DotProduct(col2);
	temp.m_matrixArray[2][2] = row3.DotProduct(col3);
	temp.m_matrixArray[2][3] = row3.DotProduct(col4);

	//column 4
	temp.m_matrixArray[3][0] = row4.DotProduct(col1);
	temp.m_matrixArray[3][1] = row4.DotProduct(col2);
	temp.m_matrixArray[3][2] = row4.DotProduct(col3);
	temp.m_matrixArray[3][3] = row4.DotProduct(col4);

	return temp;
}

Matrix4 Matrix4::OrthoProjection(const float right, const float left, const float top, const float bottom, const float far, const float near)
{
	Matrix4 temp;
	temp.Identity();
	temp.m_matrixArray[0][0] = 2.0f / (right - left);
	temp.m_matrixArray[0][3] = -1.0f *(right + left) / (right - left);
	temp.m_matrixArray[1][1] = 2.0f / (top - bottom);
	temp.m_matrixArray[1][3] = -1.0f *(top + bottom) / (top - bottom);
	temp.m_matrixArray[2][2] = -2.0f / (far - near);
	temp.m_matrixArray[2][3] = -1.0f *(far + near) / (far - near);
	temp.m_matrixArray[3][3] = 1.0f;
	return temp;
}

Matrix4::~Matrix4()
{

}