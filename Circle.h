#pragma once
#include "Vec2.h"
class Circle {
public:

	Vec2 pos;
	float radius;
public:
	Circle();
	/// <summary>
	/// ��������R���X�g���N�^
	/// </summary>
	/// <param name="a">���S���W</param>
	/// <param name="b">���a</param>
	Circle(Vec2 a,float b);
};