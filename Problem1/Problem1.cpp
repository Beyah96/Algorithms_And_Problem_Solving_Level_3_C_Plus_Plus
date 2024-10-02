#include <iostream>
#include <cstdlib>
#include "Matrix3By3.h";

using namespace std;


int main() {
	srand((unsigned)time(NULL));
	int Arr[3][3];
	Matrix3By3::FillTwoDimentionalArrayWithRandoms(Arr);
	Matrix3By3::PrintTwoDimentionalArray(Arr);	
	return 0;
}