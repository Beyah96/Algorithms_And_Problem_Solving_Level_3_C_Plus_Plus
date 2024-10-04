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
	GivenNumber = MyLib::ReadNumber("Please enter  a Number between 0 and 10 : ");
	MyMatrixMethods::PrintGivenNumberInMatrixCount(Arr , GivenNumber);

}