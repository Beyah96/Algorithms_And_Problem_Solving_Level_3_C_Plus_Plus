#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include "MyInputReader.h";

using namespace std;

namespace MyMatrixMethods
{
	void FillMatrixWithRandoNumbers(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = MyInputReader::GetRandomNumber(1, 100);
	}

	void PrintMatrixContent(int Arr[3][3]){
		cout << "The following is a 3x3 random matrix : " << endl;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++)
				cout << setw(9) << Arr[i][j] << "   ";
			cout << endl;
		}
	}

	void PrintMatrixColsSum(int Arr[3][3]){
		int Sum;
		cout << "\n\nThe following are the sum of each col in the random matrix : " << endl;
		for (int i = 0; i < 3; i++){
			Sum = 0;
			for (int j = 0; j < 3; j++)
				Sum += Arr[j][i];
			printf("Col %d sum = %d\n", i, Sum);
		}
	}
}