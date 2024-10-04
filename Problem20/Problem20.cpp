#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";
#include "MyLib.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr[3][3], ArrTest[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};
	
	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr);
	cout << "Matrice : " << endl;
	MyMatrixMethods::PrintMatrixContent(Arr);
	MyMatrixMethods::PrintIfMatrixIsPalaindrome(Arr);
	
	cout << endl;
	cout << "Test Matrice : " << endl;
	MyMatrixMethods::PrintMatrixContent(ArrTest);
	MyMatrixMethods::PrintIfMatrixIsPalaindrome(ArrTest);
	//	cout << endl;

}