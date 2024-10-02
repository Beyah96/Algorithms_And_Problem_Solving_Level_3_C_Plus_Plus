#pragma once

#include <iostream>
#include <iomanip>
#include <cstdio>
#include "MyInputReader.h";

using namespace std;

namespace MyMatrixMethods
{
	void FillArrayWithRandomNumbers(int Arr[3][3]) {
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
	
	void CalculateMatrixEachRowSum(int Arr[3][3], int Sum[3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Sum[i] += Arr[i][j];

	}
	
	void PrintMatrixEachRowSum(int Arr[3][3]) {
		cout << "\n\nThe following are the sum of each row in the matrix : " << endl;
		int Sum[3] = { 0, 0, 0 };
		CalculateMatrixEachRowSum(Arr, Sum);
		for (int i = 0; i < 3; i++)
			printf("Row % d Sum = %d\n", i + 1, Sum[i]);
	}

}
