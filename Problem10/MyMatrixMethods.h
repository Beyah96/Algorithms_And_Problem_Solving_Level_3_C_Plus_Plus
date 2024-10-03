#pragma once

#include <iostream>
#include <cstdio>
#include <iomanip>
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
				printf("%02d   ", Arr[i][j]);
			cout << endl;
		}
	}

	int CalculateSumOfAllMatrixElements(int Arr[3][3]) {
		int Sum = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				Sum += Arr[i][j];
		}
		return Sum;
	}


	void PrintSumOfAllMatrixElements(int Arr[3][3]) {
		int Sum = CalculateSumOfAllMatrixElements(Arr);
		cout << "\n\nThe sum of all the matrix elements is : " << Sum << endl;
		}

}