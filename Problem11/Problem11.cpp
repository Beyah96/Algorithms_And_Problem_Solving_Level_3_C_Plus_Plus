#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr1[3][3], Arr2[3][3];
	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr1);
	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr2);
	cout << "Matrix 1 : " << endl;
	MyMatrixMethods::PrintMatrixContent(Arr1);
	cout << "\n\nMatrix 2 : " << endl;
	MyMatrixMethods::PrintMatrixContent(Arr2);
	MyMatrixMethods::CheckIfMatrixAreEqual(Arr1, Arr2);
	return 0;
}