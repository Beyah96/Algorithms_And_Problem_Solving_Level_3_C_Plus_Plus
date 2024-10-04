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

	bool IsPalaindromeMatrix(int Arr[3][3]) {
		int Counter = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < floor(3/2); j++)
				if (Arr[i][j] == Arr[i][3 - j - 1])
					Counter++;
		return (Counter == 3);
	}

	void PrintIfMatrixIsPalaindrome(int Arr[3][3]) {
		if (IsPalaindromeMatrix(Arr))
			cout << "\n\nYes, the matrix is palaindrome .";
		else
			cout << "\n\nNo, the matrix is not palaindrome .";
	}
}