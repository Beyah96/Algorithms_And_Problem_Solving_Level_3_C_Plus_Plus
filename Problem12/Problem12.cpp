#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr1[3][3], Arr2[3][3];
	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr1);
	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr2);
	MyMatrixMethods::PrintMatrixContent(Arr1, "Matrix 1 :");
	MyMatrixMethods::PrintMatrixContent(Arr2, "\n\nMatrix 2 :");
	MyMatrixMethods::PrintIfMatricesAreTypical(Arr1, Arr2);

	return 0;
}