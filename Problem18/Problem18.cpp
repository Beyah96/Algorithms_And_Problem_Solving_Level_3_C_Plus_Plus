#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";
#include "MyLib.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr1[3][3], Arr2[3][3];
	
	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr1);
	cout << "Matrice 1 : " << endl;
	MyMatrixMethods::PrintMatrixContent(Arr1);
	
	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr2);
	cout << "\n\nMatrice 2 : " << endl;
	MyMatrixMethods::PrintMatrixContent(Arr2);
	
	cout << "\n\nIntersected Numbers are : " << endl;
	MyMatrixMethods::PrintIntersectedNumbersInMatrices(Arr1, Arr2);
	cout << endl;

}