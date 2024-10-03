#include <iostream>
#include <cstdlib>

#include "MyMatrixMethods.h";

int main() {
	srand((unsigned)time(NULL));
	int Arr[3][3];
	MyMatrixMethods::FillMatrixWithRandoms(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr);
	cout << "The middle row of matrix is : " << endl;
	MyMatrixMethods::PrintMiddelRow(Arr);
	cout << "The middle col of matrix is : " << endl;
	MyMatrixMethods::PrintMiddelCol(Arr);
	return 0;
}