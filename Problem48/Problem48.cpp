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

string PromptUserInput(const string& Message) {
	string Text;
	cout << Message;
	getline(cin >> ws, Text);
	return Text;
}

double PromptPositiveDoubleInput(const string& Message) {
	double Number;
	do {
		cout << Message;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

stClient CollectClientInfo() {
	stClient Client;
	Client.AccountNumber = PromptUserInput("Account Number  : ");
	Client.PINCode = PromptUserInput("PIN Code        : ");
	Client.FullName = PromptUserInput("Full Name       : ");
	Client.PhoneNumber = PromptUserInput("Phone Number    : ");
	Client.AccountBalance = PromptPositiveDoubleInput("Account Balance : ");
	return Client;
}

string FormatClientData(const stClient& Client, const string& Delim) {
	return Client.AccountNumber + Delim + Client.PINCode + Delim + Client.FullName + Delim + Client.PhoneNumber + Delim + to_string(Client.AccountBalance);
}


void AppendClientToFile(const string& FileName, const string& Text) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << Text << endl;
		MyFile.close();
	}
}

void AddClientsToFileLoop(const string& FileName, const string& Delim) {
	char AddMore;
	do {
		cout << "Add New Client : " << endl;
		AppendClientToFile(FileName, FormatClientData(CollectClientInfo(), Delim));
		cout << "Do you new to add more clients Y (Yes) or N (No) : ";
		cin >> AddMore;

		system("cls");
	} while (toupper(AddMore) == 'Y');
}


vector <string> ReadFileLines(const string& FileName) {
	fstream MyFile;
	vector <string> vLines;
	string Line;
	MyFile.open(FileName, ios::in);
	while (getline(MyFile, Line)) {
		vLines.push_back(Line);
	}
	return vLines;
}

vector <string> SplitLineToFields(string Line, const string& Delim) {
	vector <string> vRecord;
	string sWord;
	short Pos;
	while ((Pos = Line.find(Delim)) != string::npos) {
		sWord = Line.substr(0, Pos);
		if (sWord != " ")
			vRecord.push_back(sWord);
		Line.erase(0, Pos + Delim.length());
	}
	if (Line != "")
		vRecord.push_back(Line);
	return vRecord;
}

vector <stClient> ParseClientRecord(const vector <string>& vLines, const string& Delim) {
	stClient Client;
	vector <stClient> vClients;
	for (string Line : vLines) {
		vector <string> ClientDetails = SplitLineToFields(Line, Delim);
		Client.AccountNumber = ClientDetails[0];
		Client.PINCode = ClientDetails[1];
		Client.FullName = ClientDetails[2];
		Client.PhoneNumber = ClientDetails[3];
		Client.AccountBalance = stod(ClientDetails[4]);
		vClients.push_back(Client);
	}
	return vClients;
}


void DisplayClientList(const vector <stClient>& vClients) {
	cout << endl << "\t\t\t\tClients list : " << vClients.size() << " clients." << endl;
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
	string Delim = "#//#", FileName = "Clients.txt";
	AddClientsToFileLoop(FileName, Delim);
	DisplayClientList(ParseClientRecord(ReadFileLines(FileName), Delim));
	return 0;
}