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

	int CountGivenNumberInMatrix(int Arr[3][3], int GivenNumber) {
		int Counter = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (Arr[i][j] == GivenNumber)
					Counter++;
		return Counter;
	}

	void PrintIfMatrixIsSparse(int Arr[3][3]) {
		if (CountGivenNumberInMatrix(Arr, 0) >= ceil(3 * 3 / 2))
			cout << "Yes, it is Sparse.";
		else
			cout << "No, it is not Sparse.";

	}
}