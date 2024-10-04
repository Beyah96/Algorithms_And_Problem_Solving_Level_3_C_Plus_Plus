#include <iostream>
#include <cstdlib>
#include "MyMatrixMethods.h";
#include "MyLib.h";

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int Arr[3][3], GivenNumber;

	MyMatrixMethods::FillMatrixWithRandomNumbers(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr);
	GivenNumber = MyLib::ReadNumber("Please enter a number between 0 and 9 to look for in the matrice : ");
	MyMatrixMethods::PrintIsTheNumberExist(Arr, GivenNumber);
	cout << endl;

}