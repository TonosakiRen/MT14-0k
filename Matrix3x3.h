#pragma once
#include "Quad.h"
static const int kRowHeight = 20;
static const int kColumnWidth = 55;

class Matrix3x3
{
public:

	float m[3][3];

public:

	//ftHgRXgN^
	Matrix3x3();
	//๘ ่RXgN^
	Matrix3x3(float a, float b, float c, float d);
	Matrix3x3(float a, float b, float c, float d, float e, float f, float g, float h, float i);

	Matrix3x3 Inverse();

	//s๑ฬซตZ
	Matrix3x3 operator +(const Matrix3x3& other) const;
	//s๑ฬ๘ซZ
	Matrix3x3 operator -(const Matrix3x3& other) const;
	//s๑ฬ|ฏZ
	Matrix3x3 operator *(const Matrix3x3& other) const;
	//s๑ฬXJ[{
	Matrix3x3 operator *(const float& other) const;

	/// <summary>
	/// AtBs๑
	/// </summary>
	/// <param name="k">ก{ฆ</param>
	/// <param name="l">c{ฆ</param>
	/// <param name="theta">๑]px</param>
	/// <param name="a">|WV</param>
	/// <returns></returns>
	static Matrix3x3 MakeWorldMatrix(float k, float l, float theta, Vec2& a);

	//]u
	static Matrix3x3 Transpose(Matrix3x3& mat);
	//ฝsฺฎs๑
	static Matrix3x3 MakeTranslateMatrix(Vec2& a);
	//๑]s๑
	static Matrix3x3 MakeRotateMatrix(float theta);
	//gks๑
	static Matrix3x3 MakeScaleMatrix(float k, float l);

	//ณหes๑
	static Matrix3x3 MakeOrthographicMatrix(Quad screen);

	//ณหes๑
	static Matrix3x3 MakeViewportMatrix(Quad screen);

	
	//Matrixoอ
	static void ScreenPrintf(int x, int y, Matrix3x3 matrix);

};



