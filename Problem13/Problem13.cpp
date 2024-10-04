#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";

using namespace std;

int main() {

	srand((unsigned)time(NULL));
	int Arr[3][3];
//	int ArrTest[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr);
	MyMatrixMethods::PrintIfMatrixIsIdentity(Arr);

	
	//	MyMatrixMethods::PrintMatrixContent(ArrTest);
   //	MyMatrixMethods::PrintIfMatrixIsIdentity(ArrTest);

}