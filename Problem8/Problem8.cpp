#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr1[3][3], Arr2[3][3], ArrProduct[3][3] = { 0 };
	MyMatrixMethods::FillArrayWithRandomNumbers(Arr1);
	MyMatrixMethods::PrintMatrixContent(Arr1, "\n\nThe following is the first 3x3 random matrix : ");

	MyMatrixMethods::FillArrayWithRandomNumbers(Arr2);
	MyMatrixMethods::PrintMatrixContent(Arr2, "\n\nThe following is the Second 3x3 random matrix : ");

	MyMatrixMethods::CalculateMatrixProduct(Arr1, Arr2, ArrProduct);
	MyMatrixMethods::PrintMatrixContent(ArrProduct, "\n\nThe following is the first 3x3 random matrix : ");
	
}