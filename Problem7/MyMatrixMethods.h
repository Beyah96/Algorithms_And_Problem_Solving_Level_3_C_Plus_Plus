#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include "MyLib.h";

using namespace std;

namespace MyMatrixMethods
{
	void FillMatrixWithOrderedNumbers(int Arr[3][3]) {
		int Counter = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = ++Counter;
	}

	void TransposeMatrix(int Arr[3][3]) {
		for (int i = 0; i < (3 - floor(3 / 2)); i++)//
			for (int j = i+1; j < 3; j++)
				MyLib::Swap(Arr[i][j], Arr[j][i]);
	}

	void PrintMatrixContent(int Arr[3][3], string Message) {
		cout << Message << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << setw(3) << Arr[i][j] << "   ";
			cout << endl;
		}
	}
}

