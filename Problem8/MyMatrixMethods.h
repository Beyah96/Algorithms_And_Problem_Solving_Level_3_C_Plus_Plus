#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include "MyLib.h";

using namespace std;

namespace MyMatrixMethods
{
	void FillArrayWithRandomNumbers(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = MyLib::GetRandomNumber(1, 100);
	}

	void PrintMatrixContent(int Arr[3][3], string Message) {
		cout << Message << endl;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++)
				cout << setw(3) << Arr[i][j] << "   ";
			cout << endl;
		}
	}

	void TransposeMatrix(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = i + 1; j < 3; j++)
				MyLib::Swap(Arr[i][j], Arr[j][i]);
	}


/*
	void CalculateMatrixProduct(int Arr1[3][3], int Arr2[3][3], int ArrProduct[3][3]) {
		TransposeMatrix(Arr2);
		int Sum;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				Sum = 0;
				for (int k = 0; k < 3; k++)
					Sum += Arr2[j][k] * Arr2[j][k];
				ArrProduct[i][j] = Sum;
			}
		}
	}
*/
	void CalculateMatrixProduct(int Arr1[3][3], int Arr2[3][3], int ArrProduct[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++) {
					ArrProduct[i][j] += Arr1[i][k] * Arr2[k][j];
				}
			}
		}

	}





}

