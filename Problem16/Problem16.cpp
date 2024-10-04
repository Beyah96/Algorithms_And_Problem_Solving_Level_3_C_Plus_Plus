#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";
#include "MyLib.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr[3][3], ArrTest[3][3] = {{0, 1, 2}, {0, 0, 3}, {0, 0, 4}};

	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr);
	MyMatrixMethods::PrintIfMatrixIsSparse(Arr);
	cout << endl;
	MyMatrixMethods::PrintMatrixContent(ArrTest);
	MyMatrixMethods::PrintIfMatrixIsSparse(ArrTest);

}