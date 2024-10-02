#pragma once

#include <iostream>
#include <iomanip>
#include <cstdio>
#include "MyInputReader.h"

using namespace std;

namespace MyMatrixMethods
{
	void FillMatrixWithRandoNumbers(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = MyInputReader::GetRandomNumber(1, 100);
	}

	void PrintMatrixContent(int Arr[3][3]) {
		cout << "The following is a 3x3 random matrix : " << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << setw(3) << Arr[i][j] << "   ";
			cout << endl;
		}
	}

	void CalculateMatrixColsSum(int Arr[3][3], int ArrSum[3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				ArrSum[i] += Arr[j][i];
		}
	}

	void PrintMatrixColsSum(int Arr[3][3]) {
		cout << "\n\nThe following are the sum of each col in the matrix : " << endl;
		int ArrSum[3] = { 0, 0, 0 };
		CalculateMatrixColsSum(Arr, ArrSum);
		for (int i = 0; i < 3; i++)
			printf("Col %d Sum = %d\n", i + 1, ArrSum[i]);
	}
}