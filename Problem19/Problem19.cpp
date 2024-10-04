#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";
#include "MyLib.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr[3][3];
	
	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr);
	cout << "Matrice : " << endl;
	MyMatrixMethods::PrintMatrixContent(Arr);
	
	cout << endl;

	cout << "Minimum Number is : " << MyMatrixMethods::GetMinNumberInMatrix(Arr) << endl;
	cout << "Maximum Number is : " << MyMatrixMethods::GetMaxNumberInMatrix(Arr) << endl;
	//	cout << endl;

}