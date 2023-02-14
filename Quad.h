#pragma once
#include "Vec2.h"
class Quad {
public:
	Vec2 LeftTop;
	Vec2 RightTop;
	Vec2 LeftBottom;
	Vec2 RightBottom;

public:

	Quad();
	/// <summary>
	/// 0,0���S
	/// </summary>
	/// <param name="width">����</param>
	/// <param name="height">�c��</param>
	Quad(int width, int height);
	Quad(Vec2 LeftTop, Vec2 RightTop, Vec2 LeftBottom, Vec2 RightBottom);
	Quad(Vec2 LeftTop, int width, int height);
	Quad(int width, int height,Vec2 pos);

	/// <summary>
	/// ����
	/// </summary>
	/// <returns></returns>
	float GetWidth() const { return RightTop.DistanceFrom(LeftTop); }
	/// <summary>
	/// �c��
	/// </summary>
	/// <returns></returns>
	float GetHeight() const { return LeftTop.DistanceFrom(LeftBottom); }

	/// <summary>
	/// �^��(�΂ߖ���)
	/// </summary>
	/// <returns></returns>
	Vec2 GetCenter() const { return { LeftTop.x + GetWidth() / 2.0f,LeftTop.y - GetHeight() / 2.0f }; }

	/// <summary>
	/// ���ɑ���
	/// </summary>
	/// <param name="add">�����l</param>
	void WidthAdd(float add);

	/// <summary>
	/// �����ɑ���
	/// </summary>
	/// <param name="add">�����l</param>
	void VerticalAdd(float add);

	/// <summary>
	/// ���ƍ����ɑ���
	/// </summary>
	/// <param name="add">�����l</param>
	void WidthVerticalAdd(float add);

	Quad operator + (const Vec2& s) const;
	Quad operator - (const Vec2& s) const;
	Quad operator * (const float& s)const;
	Quad operator * (const Matrix3x3& s)const;
};

