#include <iostream>
#include "MyMatrixMethods.h";

using namespace std;

int main() {
	int Arr[3][3];
	MyMatrixMethods::FillMatrixWithOrderedNumbers(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr, "The following is a 3x3 ordered matrix : ");
	return 0;
}