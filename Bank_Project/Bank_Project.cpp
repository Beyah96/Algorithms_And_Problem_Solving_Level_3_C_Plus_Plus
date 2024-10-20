#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct stClient{ 
	string AccountNumber, PINCode, FullName, PhoneNumber;
	double AccountBalance;
	bool MarkToDelete = false;
};

void GoToMainMenuScreen(string, string);
bool isFound(vector <stClient>, string);
vector <stClient> ParseClientsRecords(string, string);

string ReadString(string Message) {
	string Text;
	cout << Message;
	getline(cin >> ws, Text);
	return Text;
}

string SetWidth(int Number) {
	string StringWightSpace = "";
	for (int i = 0; i < Number; i++)
		StringWightSpace += "\t";
	return StringWightSpace;
}

void PrintMessage(string Message) {
	cout << endl << endl << " ---------------------------------------------------------------------------------------------- " << endl;
	cout << SetWidth(1) << Message << endl;
	cout << " ---------------------------------------------------------------------------------------------- " << endl << endl;
}



string ConvertRecordToStringLine(stClient Client, string Delim) {
	return Client.AccountNumber + Delim + Client.PINCode + Delim + Client.FullName + Delim +  Client.PhoneNumber + Delim + to_string(Client.AccountBalance);
}

void AddNewClient(string FileName, string Delim,vector <stClient> vClients) {
	stClient Client;
	cout << "Adding New Client" << endl;
	Client.AccountNumber = ReadString("Account Number  : ");
	if (!isFound(vClients, Client.AccountNumber))
	{
		Client.PINCode = ReadString("PINCode         : ");
		Client.FullName = ReadString("Full Name       : ");
		Client.PhoneNumber = ReadString("Phone Number    : ");
		Client.AccountBalance = stod(ReadString("Account Balance : "));
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << ConvertRecordToStringLine(Client, Delim) << endl;
			MyFile.close();
		}
	}
	else {
		PrintMessage(" Client with account Number (" + Client.AccountNumber + ") already exists, enter another account number.");
	}
}

vector <string> ReadFileContent(string FileName, string Delim) {
	vector <string> vLines;
	fstream MyFile;
	string Line;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		while (getline(MyFile, Line)) {
			vLines.push_back(Line);
		}
		MyFile.close();
	}
	return vLines;
}

vector <string> SplitClientDetails(string Line, string Delim) {
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

vector <stClient> ParseClientsRecords(string FileName, string Delim) {
	vector <stClient> vClients;
	vector <string> vLine;
	stClient Client;
	vector <string> vLines = ReadFileContent(FileName, Delim);
	for (string Line : vLines){
			vLine = SplitClientDetails(Line, Delim);
			Client.AccountNumber = vLine[0];
			Client.PINCode = vLine[1];
			Client.FullName = vLine[2];
			Client.PhoneNumber = vLine[3];
			Client.AccountBalance = stod(vLine[4]);
			vClients.push_back(Client);
	}
	return vClients;
}


void PrintHeader() {
	
	cout << " ==================================================================================== " << endl;
	cout << "|" << left << setw(15) << "Account Number";
	cout << "|" << left << setw(9) << "PIN Code";
	cout << "|" << left << setw(27) << "Fulll Name";
	cout << "|" << left << setw(13) << "Phone Number";
	cout << "|" << left << setw(16) << "Account Balance" << "|" << endl;
	cout << " ==================================================================================== " << endl;
}

void PrintClient(stClient Client) {
	cout << "|" << left << setw(15) << Client.AccountNumber;
	cout << "|" << left << setw(9) << Client.PINCode;
	cout << "|" << left << setw(27) << Client.FullName;
	cout << "|" << left << setw(13) << Client.PhoneNumber;
	cout << "|" << left << setw(16) << Client.AccountBalance << "|" << endl;
	cout << " ------------------------------------------------------------------------------------ " << endl;
}
void ShowClientList(vector <stClient> vClients) {
	cout << endl << endl;
	cout << SetWidth(4) << "Clients List : " << vClients.size() << " client(s)." << endl;
	PrintHeader();
	for (stClient Client : vClients)
		PrintClient(Client);
}


bool isFound(vector <stClient> vClients, string SearchedAccountNumber) {
	for (stClient Client : vClients)
		if (Client.AccountNumber == SearchedAccountNumber){
			PrintHeader();
			PrintClient(Client);
			return true;
		}
	return false;
}

void MarkClientDelete(vector <stClient>& vClients, string SearchedAccountNumber) {
	for (stClient& Client : vClients)
		if (Client.AccountNumber == SearchedAccountNumber)
			Client.MarkToDelete = true;
}

void SaveChanges(string FileName, string Delim, vector <stClient>& vClients) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open()) {
		for (stClient& Client : vClients)
			if (!Client.MarkToDelete)
				MyFile << ConvertRecordToStringLine(Client, Delim) << endl;
		MyFile.close();
	}
}

void DeleteClient(string FileName, string Delim, vector <stClient> vClients) {
	char DeleteAccount;
	string SearchedAccountNumber;
	cout << "Account Number ? :";
	cin >> SearchedAccountNumber;
	if (isFound(vClients, SearchedAccountNumber)){
		cout << "Are you sure you want delete this client ? Y or N :";
		cin >> DeleteAccount;
		if (toupper(DeleteAccount) == 'Y')
			MarkClientDelete(vClients, SearchedAccountNumber);
		SaveChanges(FileName, Delim, vClients);
		PrintMessage("Client deleted successfully!");
	}
	else {
		PrintMessage(" Client with account Number (" + SearchedAccountNumber + ") is not Found.");
	}
}

void AskForClientUpdate(stClient& Client) {
	PrintMessage("Updating Client records :");
	Client.PINCode = ReadString("Please enter your new PIN Code : ");
	Client.FullName = ReadString("Please enter your Full Name: ");
	Client.PhoneNumber = ReadString("Please enter your phone number : ");
	Client.AccountBalance = stod(ReadString("Please enter the balance : "));
}

void UpdateClientInfo(string FileName, string Delim,vector <stClient> vClients) {
	 
	string SearchedAccountNumber;
	cout << "Account Number ? :";
	cin >> SearchedAccountNumber;
	system("cls");
	if (isFound(vClients, SearchedAccountNumber)){
		for (stClient& Client : vClients)
			if (Client.AccountNumber == SearchedAccountNumber)
				AskForClientUpdate(Client);
		SaveChanges(FileName, Delim, vClients);
	}
	else {
		PrintMessage(" Client with account Number (" + SearchedAccountNumber + ") is not Found.");
	}
}

void FindClient(string FileName, string Delim) {
	vector <stClient> vClients = ParseClientsRecords(FileName, Delim);
	string SearchedAccountNumber;
	cout << "Account Number ? :";
	cin >> SearchedAccountNumber;
	if (!isFound(vClients, SearchedAccountNumber)){
		PrintMessage(" Client with account Number (" + SearchedAccountNumber + ") is not Found.");
	}
}


short ReadUserInput(string Message) {
	short Number;
	do {
		cout << Message;
		cin >> Number;

	} while (Number > 6 || Number < 1);
	return Number;
}


short DiplayMainMenuScreen() {
	short Number;
	cout << " ==================================================================================== " << endl;
	cout << SetWidth(4) << "Main Menu Screen : " << endl;
	cout << " ==================================================================================== " << endl;
	cout << SetWidth(2) << "[1] Show Client List" << endl;
	cout << SetWidth(2) << "[2] Add New Client" << endl;
	cout << SetWidth(2) << "[3] Delete Client" << endl;
	cout << SetWidth(2) << "[4] Update Client Info" << endl;
	cout << SetWidth(2) << "[5] Find Client" << endl;
	cout << SetWidth(2) << "[6] Exit" << endl;	
	cout << " ==================================================================================== " << endl;

	Number = ReadUserInput(SetWidth(2) + "Chose what do you want to do? [1 to 6] : ");
	return Number;
}


int main() {
	string FileName = "Clients.txt", Delim = "#;/**/;#";
	//vector <stClient> vClients;
	short Number;
	do {
		vector <stClient>	vClients = ParseClientsRecords(FileName, Delim);
		system("cls");
		Number = DiplayMainMenuScreen();
		system("cls");
		switch (Number) {
		case 1:
			ShowClientList(vClients);
			break;
		case 2:

			AddNewClient(FileName, Delim,vClients);

			break;
		case 3:
			DeleteClient(FileName, Delim,vClients);
			break;
		case 4:
			UpdateClientInfo(FileName, Delim, vClients);
			break;
		case 5:
			FindClient(FileName, Delim);
			break;
		case 6:
			PrintMessage(" Program Ends :-)");
			break;
		default:
			cout << "Wrong choice .";
		}
		if (Number != 6) {
			cout << " Press any letter / Number + Enter to go back to the main menu screen : ";
			_getch();

			system("cls");

		}

	} while (Number != 6);
	return 0;
}