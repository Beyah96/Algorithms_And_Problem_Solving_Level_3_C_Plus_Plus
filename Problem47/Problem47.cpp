#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct stClient { 
	string AccountNumber, PINCode, FullName, PhoneNumber;
	double AccountBalance;
};

string ReadText(string Message) {
	string Text;
	cout << Message;
	getline(cin, Text);
	return Text;
}

double ReadDouble(string Message) {
	double Number;
	cout << Message;
	cin >> Number;
	return Number;
}

string ConvertRecordToLine(stClient Client, string Delim) {
	return Client.AccountNumber + Delim + Client.PINCode + Delim + Client.FullName + Delim + Client.PhoneNumber + Delim + to_string(Client.AccountBalance);
}

stClient AddNewRecord() {
	stClient Client;
	cout << "----------------------------------" << endl;
	cout << "      Client Data Collect :       " << endl;
	cout << "----------------------------------" << endl;
	Client.AccountNumber = ReadText("Account Number  : ");
	Client.PINCode = ReadText("PIN code        : ");
	Client.FullName = ReadText("Full Name       : ");
	Client.PhoneNumber = ReadText("Phone Number    : ");
	Client.AccountBalance = ReadDouble("Account Balance : ");

	return Client;
}

void WriteRecordLine(string Delim) {
	char NewRecord;
	fstream MyFile;
		do {
			MyFile.open("File.txt", ios::out | ios::app);
			if (MyFile.is_open()) {
				MyFile << ConvertRecordToLine(AddNewRecord(), Delim) << endl;
				cout << "Client Added Successfully! Do you want to add more client ? Y/y or N/n : ";
				MyFile.close();
			}
				cin >> NewRecord;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (NewRecord != 'N' && NewRecord != 'n');
}
int main() {
	WriteRecordLine("#//#");
	return 0;
}