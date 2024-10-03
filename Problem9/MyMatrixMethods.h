#pragma once

#include <iostream>
#include <iomanip>
#include <cstdio>
#include "MyLib.h";
#include <cmath>

using namespace std;

namespace MyMatrixMethods
{
	void FillMatrixWithRandoms(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = MyLib::GetRandomNumber(1, 100);
	}
	
	void PrintMatrixContent(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)	{
			for (int j = 0; j < 3; j++)
				printf("%0*d   ", 2, Arr[i][j]);
			cout << endl;
		}
	}

	void PrintMiddelRow(int Arr[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				if (i == ceil(3 / 2))
					printf("%0*d   ", 2, Arr[i][j]);
			cout << endl;
		}
	}

	void PrintMiddelCol(int Arr[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				if (j == ceil(3 / 2))
					printf("%0*d   ", 2, Arr[i][j]);
		}
	}
}