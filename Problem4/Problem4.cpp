#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr[3][3];
	MyMatrixMethods::FillMatrixWithRandoNumbers(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr);
	MyMatrixMethods::PrintMatrixColsSum(Arr);
	return 0;
}