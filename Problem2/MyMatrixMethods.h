#pragma once
#include <iostream>
#include <iomanip>
#include <cstdio>

#include "MyInputLib.h";

using namespace std;

namespace MyMatrixMethods
{
	void FillMatrixWithRandomNumbers(int Arr[3][3]) {
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++)
				Arr[i][j] = MyInputLib::GetRandomNumbers(1, 100);
	}

	void PrintMatrixContent(int Arr[3][3]) {
		cout << "The following is a 3x3 random matrix : " << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << setw(3) << Arr[i][j] << "   ";
			cout << endl;
		}
	}

	void CalcluateEachRowSum(int Arr[3][3]) {
		int Sum;
		cout << "\n\nThe following are the sum of each row in the matrix : " << endl;
		for (int i = 0; i < 3; i++) {
			Sum = 0;
			for (int j = 0; j < 3; j++)
				Sum += Arr[i][j];
			printf("Row %d Sum = %d\n", i, Sum);
		}
	}
}