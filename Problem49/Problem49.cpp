#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
struct stClient{ 
	string AccountNumber, PINCode, FullName, PhoneNumber;
	double AccountBalance;
};

string PromptUserInput(const string& Message) {
	string sWord;
	cout << Message;
	getline(cin >> ws, sWord);
	return sWord;
}

double PromptPositveDoubleInput(const string& Message) {
	double dNumber;
	cout << Message;
	cin >> dNumber;
	return dNumber;
}

stClient CollectClientData() {
	stClient Client;
	cout << "Adding new client  : " << endl;
	Client.AccountNumber = PromptUserInput("Account Number  : ");
	Client.PINCode = PromptUserInput("Pin Code        : ");
	Client.FullName = PromptUserInput("Full Name       : ");
	Client.PhoneNumber = PromptUserInput("Phone Number    : ");
	Client.AccountBalance = PromptPositveDoubleInput("Account Balance : ");

	return Client;
}

string FormatClientInfo(const stClient& Client, const string& Delim) {
	return Client.AccountNumber + Delim + Client.PINCode + Delim + Client.FullName + Delim + Client.PhoneNumber + Delim + to_string(Client.AccountBalance);
}

void AppendNewClientToFile(const string& FileName, const string& Line) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << Line << endl;
		MyFile.close();
	}
}

void AppendAllGivenClientsToFile(const string& FileName, const string& Delim) {
	char AddMore;
	stClient Client;
	do {
		AppendNewClientToFile(FileName, FormatClientInfo(CollectClientData(), Delim));
		cout << "Successfuly added, do you want to add more clients ? Y (yes) or n (no) : ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

vector <string> ReadLinesFromFile(string FileName) {
	string sLine;
	vector <string> vLines;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()){
		while (getline(MyFile, sLine)) {
			vLines.push_back(sLine);
		}
		MyFile.close();
	}
	return vLines;
}


void PrintVectorContent(string FileName) {
	vector <string> vLines = ReadLinesFromFile(FileName);
	for (string Line : vLines) {
		cout << Line << endl;
	}
}

vector <string> SplitLineToFields(string Line, string Delim) {
	vector <string> vLine;
	string sWord;
	short Pos;
	while ((Pos = Line.find(Delim)) != string::npos) {
		sWord = Line.substr(0, Pos);
		if (sWord != " ")
			vLine.push_back(sWord);
		Line.erase(0, Pos + Delim.length());
	}
	if (sWord != "")
		vLine.push_back(sWord);
	return vLine;
}

vector <stClient> ParseClientRecords(string FileName, string Delim) {
	vector <stClient> vClientsList;
	vector <string> vLines = ReadLinesFromFile(FileName), ClientDetails;
	stClient Client;

	for (string& sLine : vLines) {
		ClientDetails = SplitLineToFields(sLine, Delim);
		Client.AccountNumber = ClientDetails[0];
		Client.PINCode = ClientDetails[1];
		Client.FullName = ClientDetails[2];
		Client.PhoneNumber = ClientDetails[3];
		Client.AccountBalance = stod(ClientDetails[4]);
		vClientsList.push_back(Client);
	}
	return vClientsList;
}

void PrintClients(string FileName, string Delim) {
	//cout << endl << "\t\t\t\tClients list : " << vClients.size() << " clients." << endl;
	cout << endl << "----------------------------------------------------------------------------------------" << endl;
	cout << "|" << left << setw(16) << "Account Number";
	cout << "|" << left << setw(16) << "PIN Code";
	cout << "|" << left << setw(22) << "Full Name";
	cout << "|" << left << setw(13) << "Phone Number";
	cout << "|" << left << setw(16) << "Account Balance" << "|";
	cout << endl << "----------------------------------------------------------------------------------------" << endl;
	vector <stClient> vClients = ParseClientRecords(FileName, Delim);

	for (stClient& Client : vClients) {
		cout << "|" << left << setw(16) << Client.AccountNumber;
		cout << "|" << left << setw(16) << Client.PINCode;
		cout << "|" << left << setw(22) << Client.FullName;
		cout << "|" << left << setw(13) << Client.PhoneNumber;
		cout << "|" << left << setw(16) << Client.AccountBalance << "|";

		cout << endl;
	}
}
int main() {
	string FileName = "Clients.txt", Delim = "#**//**#";
	//AppendAllGivenClientsToFile(FileName, Delim);
	//PrintVectorContent(FileName);
	PrintClients(FileName, Delim);
	return 0;
}