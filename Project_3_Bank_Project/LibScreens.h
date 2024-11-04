#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
namespace LibScreens {
	
	string SetWidth(short Length) {
		string Width;
		for (int i = 0; i < Length; i++)
			Width += "\t";
		return Width;
	}

	void PrintMainMenuScreen() {
		cout << "========================================" << endl;
		cout << SetWidth(3) << "Main Menu Screen" << endl;
		cout << "========================================" << endl;
		cout << "[1] Show Client List :" << endl;
		cout << "[2] Add New Client :" << endl;
		cout << "[3] Delete Client :" << endl;
		cout << "[4] Update Client Info :" << endl;
		cout << "[5] Find Client :" << endl;
		cout << "[6] Exit :" << endl;
		cout << "========================================" << endl;
		cout << "Choose what do you want to do? [1 to 6]? " << endl;
	}

	void ShowClientListScreen() {
		cout << " ------------------------------------------------------------------------------------------" << endl;
		cout << "|" << left << setw(15) << "Account Number";
		cout << "|" << left << setw(10) << "Pin Code";
		cout << "|" << left << setw(30) << "Full Name";
		cout << "|" << left << setw(15) << "Phone Number";
		cout << "|" << left << setw(16) << "Account balance" << "|";
	}
}