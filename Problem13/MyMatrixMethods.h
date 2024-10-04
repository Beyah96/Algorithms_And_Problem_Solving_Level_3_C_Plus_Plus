#pragma once

#include <iostream>
#include <cstdio>
#include "MyLib.h";

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

	bool CheckIfMatrixIsIdentity(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				if (i == j && Arr[i][j] != 1)
					return false;
				else if (i != j && Arr[i][j] != 0)
					return false;
			}
		return true;
	}

	void PrintIfMatrixIsIdentity(int Arr[3][3]) {
		if (CheckIfMatrixIsIdentity(Arr))
			cout << "Yes, Matrix is identity." << endl;
		else
			cout << "No, Matrix is not identity." << endl;
	}
}