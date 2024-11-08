#include <iostream>
#include <string>
#include "LibScreens.h";
#include "LibReader.h";

using namespace std;

int main() {
	LibScreens::PrintMainMenuScreen();
	LibScreens::ShowClientListScreen();
	ClientLib::AddingNewLineToFile("Clients.txt", "#//#");
	return 0;
}