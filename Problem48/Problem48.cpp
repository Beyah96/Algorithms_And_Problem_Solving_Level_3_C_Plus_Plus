#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
struct stClient { 
	string AccountNumber, PINCode, FullName, PhoneNumber;
	double AccountBalance;
};

string ReadText(string Message) {
	string Text;
	cout << Message;
	getline(cin >> ws, Text);
	return Text;
}

double ReadDouble(string Message) {
	double Number;
	do {
		cout << Message;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

stClient ReadClientData() {
	stClient Client;
	Client.AccountNumber = ReadText("Account Number  : ");
	Client.PINCode = ReadText("PIN Code        : ");
	Client.FullName = ReadText("Full Name       : ");
	Client.PhoneNumber = ReadText("Phone Number    : ");
	Client.AccountBalance = ReadDouble("Account Balance : ");
	return Client;
}

string ConvertClientDataToLine(stClient Client, string Delim) {
	return Client.AccountNumber + Delim + Client.PINCode + Delim + Client.FullName + Delim + Client.PhoneNumber + Delim + to_string(Client.AccountBalance);
}


void SaveNewClient(string Text) {
	fstream MyFile;
	MyFile.open("Clients.txt", ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << Text << endl;
		MyFile.close();
	}
}

void SaveClientsToFile(string Delim) {
	char AddMore;
	do {
		system("cls");
		cout << "Add New Client : " << endl;
		SaveNewClient(ConvertClientDataToLine(ReadClientData(), Delim));
		cout << "Do you new to add more clients Y (Yes) or N (No) : ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}


int main() {
	SaveClientsToFile("#//#");
	return 0;
}