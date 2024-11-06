#include <iostream>
#include <string>
#include "LibScreens.h";
#include "LibReader.h";

using namespace std;

int main() {
	LibScreens::PrintMainMenuScreen();
	LibScreens::ShowClientListScreen();
	LibReader::ReadPositiveNumber("Please enter the balance");
	LibReader::ReadString("Please enter you name");
	return 0;
}