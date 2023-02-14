#pragma once
#include "Quad.h"
static const int kRowHeight = 20;
static const int kColumnWidth = 55;

class Matrix3x3
{
public:

	float m[3][3];

public:

	//�f�t�H���g�R���X�g���N�^
	Matrix3x3();
	//��������R���X�g���N�^
	Matrix3x3(float a, float b, float c, float d);
	Matrix3x3(float a, float b, float c, float d, float e, float f, float g, float h, float i);

	Matrix3x3 Inverse();

	//�s��̑����Z
	Matrix3x3 operator +(const Matrix3x3& other) const;
	//�s��̈����Z
	Matrix3x3 operator -(const Matrix3x3& other) const;
	//�s��̊|���Z
	Matrix3x3 operator *(const Matrix3x3& other) const;
	//�s��̃X�J���[�{
	Matrix3x3 operator *(const float& other) const;

	/// <summary>
	/// �A�t�B���s��
	/// </summary>
	/// <param name="k">�����{��</param>
	/// <param name="l">�c���{��</param>
	/// <param name="theta">��]�p�x</param>
	/// <param name="a">�|�W�V����</param>
	/// <returns></returns>
	static Matrix3x3 MakeWorldMatrix(float k, float l, float theta, Vec2& a);

	//�]�u
	static Matrix3x3 Transpose(Matrix3x3& mat);
	//���s�ړ��s��
	static Matrix3x3 MakeTranslateMatrix(Vec2& a);
	//��]�s��
	static Matrix3x3 MakeRotateMatrix(float theta);
	//�g�k�s��
	static Matrix3x3 MakeScaleMatrix(float k, float l);

	//���ˉe�s��
	static Matrix3x3 MakeOrthographicMatrix(Quad screen);

	//���ˉe�s��
	static Matrix3x3 MakeViewportMatrix(Quad screen);

	
	//Matrix�o��
	static void ScreenPrintf(int x, int y, Matrix3x3 matrix);

};



