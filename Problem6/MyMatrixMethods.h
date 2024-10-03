#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

namespace MyMatrixMethods
{
	void FillMatrixWithOrderedNumbers(int Arr[3][3]) {
		int Counter = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = ++Counter;
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

