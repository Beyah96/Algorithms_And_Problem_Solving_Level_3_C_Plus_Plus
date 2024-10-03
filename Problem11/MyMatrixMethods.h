#pragma once

#include <iostream>
#include <iomanip>
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
	void PrintMatrixContent(int Arr[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				printf("%02d ", Arr[i][j]);
			cout << endl;
		}
	}

	int CalculateMatrixElementsSum(int Arr[3][3]) {
		int Sum = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Sum += Arr[i][j];
		return Sum;
	}

	bool CheckIfMatricesAreEqual(int Arr1[3][3], int Arr2[3][3]) {
		return (CalculateMatrixElementsSum(Arr1) == CalculateMatrixElementsSum(Arr2));
	}

	void PrintMatricesEqualOrNot(int Arr1[3][3], int Arr2[3][3]) {
		if (CheckIfMatricesAreEqual(Arr1, Arr2))
			cout << "\nYes ! They are equal." << endl;
		else
			cout << "\nNo, they are not equal." << endl;
	}

}
