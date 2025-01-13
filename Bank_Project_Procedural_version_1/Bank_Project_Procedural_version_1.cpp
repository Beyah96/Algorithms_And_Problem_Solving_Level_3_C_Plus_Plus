#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



void ShowClientList() {
	cout << " --------------------------------------------------------------------------------" << endl;
	cout << "|" << left << setw(14) << "Account Number" << "|" << left << setw(10) << "PIN Code" << "|" << left << setw(30) << "Client Name " << "|" << left << setw(10) << "Phone Number" << "|" << left << setw(10) << "Balance" << "|" << endl;
	cout << " ----------------------------------------------------------------------" << endl;
}

void PrintMainMenuScreen() {
	cout << "======================================" << endl;
	cout << setw(5) << "Main Menu Screen : " << endl;
	cout << "======================================" << endl;
	cout << setw(3) << "[1] Show client list." << endl;
	cout << setw(3) << "[1] Add New client." << endl;
	cout << setw(3) << "[1] Delete client." << endl;
	cout << setw(3) << "[1] Update client info." << endl;
	cout << setw(3) << "[1] Find client." << endl;
	cout << setw(3) << "[1] Exit" << endl;
	cout << "======================================" << endl;
	cout << "Chose what do you want to do" << endl;
	//cin >>
}

int main() {
	ShowClientList();
	PrintMainMenuScreen();

	system("pause>0");
	return 0;
}