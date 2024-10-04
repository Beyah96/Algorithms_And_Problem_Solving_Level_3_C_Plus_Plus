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


	bool IsTheNumberExist(int Arr[3][3], int GivenNumber) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (Arr[i][j] == GivenNumber)
					return true;
		return false;
	}


	void PrintIntersectedNumbersInMatrices(int Arr1[3][3], int Arr2[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++){
				if (IsTheNumberExist(Arr2, Arr1[i][j]))
					printf("%d   ", Arr1[i][j]);
		}
	}
}