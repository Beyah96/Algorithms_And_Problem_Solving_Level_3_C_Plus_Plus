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


void SaveNewClient(string Text, string FileName) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << Text << endl;
		MyFile.close();
	}
}

void SaveClientsToFile(string FileName, string Delim) {
	char AddMore;
	do {
		system("cls");
		cout << "Add New Client : " << endl;
		SaveNewClient(FileName, ConvertClientDataToLine(ReadClientData(), Delim));
		cout << "Do you new to add more clients Y (Yes) or N (No) : ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}


vector <string> ReadRecordLineFromFile(string FileName, string Delim) {
	fstream MyFile;
	vector <string> vLines;
	string Line;
	MyFile.open(FileName, ios::in);
	while (getline(MyFile, Line)) {
		vLines.push_back(Line);
	}
	return vLines;
}

vector <stClient> GetClientsDetails(vector <string> vLines) {
	stClient Client;
	vector <stClient> vClients;
	for (string Line : vLines) {
		Client.AccountNumber = Line[0];
		Client.PINCode = Line[1];
		Client.FullName = Line[2];
		Client.PhoneNumber = Line[3];
		Client.AccountBalance = Line[4];
		vClients.push_back(Client);
	}
	return vClients;
}


void PrintClientDetailsFromLine(vector <stClient> vClients) {
	cout << endl << "----------------------------------------------------------------------------------------" << endl;
	cout << "|" << left << setw(16) << "Account Number";
	cout << "|" << left << setw(16) << "PIN Code";
	cout << "|" << left << setw(22) << "Full Name";
	cout << "|" << left << setw(13) << "Phone Number";
	cout << "|" << left << setw(16) << "Account Balance" << "|";
	cout << endl << "----------------------------------------------------------------------------------------" << endl;

	for (stClient Client : vClients){
		cout << "|" << left << setw(16) << Client.AccountNumber;
		cout << "|" << left << setw(16) << Client.PINCode;
		cout << "|" << left << setw(22) << Client.FullName;
		cout << "|" << left << setw(13) << Client.PhoneNumber;
		cout << "|" << left << setw(16) << Client.AccountBalance << "|";

		cout << endl;
	}
	}

int main() {
	//SaveClientsToFile("Clients.txt", "#//#");
	PrintClientDetailsFromLine(GetClientsDetails(ReadRecordLineFromFile("Clients.txt", "#//#")));
	return 0;
}