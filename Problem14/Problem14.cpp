#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";

using namespace std;

int main() {

	srand((unsigned)time(NULL));
	int Arr[3][3];
    int ArrTest[3][3] = { {3, 0, 0}, {0, 3, 0}, {0, 0, 3} };

	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr);
	MyMatrixMethods::PrintIfMatrixIsScalar(Arr);

	
	MyMatrixMethods::PrintMatrixContent(ArrTest);
    MyMatrixMethods::PrintIfMatrixIsScalar(ArrTest);

}