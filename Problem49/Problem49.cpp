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


vector <string> SplitLineToFields(string Line, string Delim) {
	vector <string> vLine;
	string sWord;
	short Pos;
	while ((Pos = Line.find(Delim)) != string::npos) {
		sWord = Line.substr(0, Pos);
		vLine.push_back(sWord);
		Line.erase(0, Pos + Delim.length());
	}
	if (Line != "")
		vLine.push_back(Line);
	return vLine;
}

vector <stClient> ParseClientRecords(vector <string> vLines, string Delim) {
	vector <stClient> vClientsList;
	stClient Client;
	for (string& sLine : vLines) {
		vector <string> ClientDetails = SplitLineToFields(sLine, Delim);
		Client.AccountNumber = ClientDetails[0];
		Client.PINCode = ClientDetails[1];
		Client.FullName = ClientDetails[2];
		Client.PhoneNumber = ClientDetails[3];
		Client.AccountBalance = stod(ClientDetails[4]);
		vClientsList.push_back(Client);
	}
	return vClientsList;
}


void PrintClients(vector <stClient> vClients) {
	cout << endl << "\t\t\t\tClients list : " << vClients.size() << " clients." << endl;
	cout << endl << "----------------------------------------------------------------------------------------" << endl;
	cout << "|" << left << setw(16) << "Account Number";
	cout << "|" << left << setw(16) << "PIN Code";
	cout << "|" << left << setw(22) << "Full Name";
	cout << "|" << left << setw(13) << "Phone Number";
	cout << "|" << left << setw(16) << "Account Balance" << "|";
	cout << endl << "----------------------------------------------------------------------------------------" << endl;

	for (stClient Client : vClients) {
		cout << "|" << left << setw(16) << Client.AccountNumber;
		cout << "|" << left << setw(16) << Client.PINCode;
		cout << "|" << left << setw(22) << Client.FullName;
		cout << "|" << left << setw(13) << Client.PhoneNumber;
		cout << "|" << left << setw(16) << Client.AccountBalance << "|";

		cout << endl;
	}
}

bool IsFound(vector <stClient> vClients, string SearchedAccountNumber) {
	for (stClient Client : vClients) {
		if (Client.AccountNumber == SearchedAccountNumber) {
			return true;
		}
	}
	return false;
}

void FindClientByAccountNumber(vector <stClient> vClients, string SearchedAccountNumber) {
	vector <stClient> vTempClient;
	if (!IsFound(vClients, SearchedAccountNumber))
		cout << "The client with Account Number " << SearchedAccountNumber << " not found!";
	else
		for (stClient Client : vClients)
			if (Client.AccountNumber == SearchedAccountNumber) {
				vTempClient.push_back(Client);
				PrintClients(vTempClient);
				break;
			}
}

int main() {
	string FileName = "Clients.txt", Delim = "#**//**#", SearchedAccount = "A10645";
	AppendAllGivenClientsToFile(FileName, Delim);
	vector <stClient> vClients = ParseClientRecords(ReadLinesFromFile(FileName), Delim);
	PrintClients(vClients);
	FindClientByAccountNumber(vClients, SearchedAccount);
	return 0;
}