#pragma once
#include <iostream>
#include <cstdio>
#include "MyLib.h";

using namespace std;

namespace MyMatrixMethods
{
	void FillMatrixWithRandomNumbers(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = MyLib::GetRandomNumber(1, 10);
	}

	void PrintMatrixContent(int Arr[3][3], string Message) {
		cout << Message << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				printf("%02d   ", Arr[i][j]);
			cout << endl;
		}
	}

	bool CheckIfMatricesAreTypical(int Arr1[3][3], int Arr2[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (Arr1[i][j] != Arr2[i][j])
					return false;
		return true;
	}

	void PrintIfMatricesAreTypical(int Arr1[3][3], int Arr2[3][3]) {
		if (CheckIfMatricesAreTypical(Arr1, Arr2))
			cout << "Yes! these matrices are typical." << endl;
		else
			cout << "No! these matrices are not typical." << endl;
	}
}