#pragma once
#include<cstdlib>
#include<ctime>

namespace Randam{

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="min">�ŏ��l</param>
	/// <param name="max">�ő�l</param>
	/// <returns>int�^</returns>
	int RAND(int min, int max);

	float RAND(float min, float max);

	unsigned int ColorRAND();


	void SRAND();
	///srand((unsingned)time(NULL));
}