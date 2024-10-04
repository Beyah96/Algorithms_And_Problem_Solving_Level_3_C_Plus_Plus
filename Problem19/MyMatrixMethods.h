#pragma once

#include <iostream>
#include <cstdio>
#include "MyLib.h";
#include <cmath>

using namespace std;

namespace MyMatrixMethods
{
	void FillMatrixWithRandomNumbers(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = MyLib::GetRandomNumber(0, 9);
	}

	void PrintMatrixContent(int Arr[3][3]) {
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++)
				printf("%d   ", Arr[i][j]);
			cout << endl;
		}
	}

	int GetMinNumberInMatrix(int Arr[3][3]) {
		int MinNumber = Arr[0][0];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (Arr[i][j] < MinNumber)
					MinNumber = Arr[i][j];
		return MinNumber;
	}

	int GetMaxNumberInMatrix(int Arr[3][3]) {
		int MaxNumber = Arr[0][0];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (Arr[i][j] > MaxNumber)
					MaxNumber = Arr[i][j];
		return MaxNumber;
	}
}