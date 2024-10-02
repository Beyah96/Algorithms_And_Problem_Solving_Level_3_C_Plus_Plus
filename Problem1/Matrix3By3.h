#pragma once

#include <iostream>
#include "MyInputLib.h";
#include <iomanip>

using namespace std;

namespace Matrix3By3
{
	void FillTwoDimentionalArrayWithRandoms(int Arr[3][3]) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				Arr[i][j] = MyInputLib::RandomNumber(1,100);
	}

	void PrintTwoDimentionalArray(int Arr[3][3]) {
		cout << "The following is a 3x3 random matrix : " << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << setw(3) << Arr[i][j]<< "   ";
			cout << endl;
		}
	}


}