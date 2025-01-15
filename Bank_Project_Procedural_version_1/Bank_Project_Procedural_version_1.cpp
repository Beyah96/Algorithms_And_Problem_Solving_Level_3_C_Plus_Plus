#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>


using namespace std;
static string Delim = "###|||###";
static string FileName = "ClientFile.Text";

enum enMainMenuOptions{eClientList = 1, eAddClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eExit = 6};
vector <string> LoadClientsFromFile(string FileName) {
	vector <string> vString;
	string sLine;
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open()) {
		while (getline(MyFile, sLine)) {
			vString.push_back(sLine);
		}
		MyFile.close();
	}
	return vString;
};

void ShowClientList() {
	cout << " --------------------------------------------------------------------------------" << endl;
	cout << "|" << left << setw(14) << "Account Number" << "|" << left << setw(10) << "PIN Code" << "|" << left << setw(30) << "Client Name " << "|" << left << setw(10) << "Phone Number" << "|" << left << setw(10) << "Balance" << "|" << endl;
	cout << " --------------------------------------------------------------------------------" << endl;
}
void GoBackToMainMenuScreen() {

};
vector <string> ConvertLineToRecord(string RecordLine) {
	vector <string> vRecord;
	string sWord = "";
	short Pos = 0;
	while ((Pos = RecordLine.find(Delim)) != string::npos) {
		sWord = RecordLine.substr(0, Pos);
		if (sWord != " ") 
			vRecord.push_back(sWord);
		RecordLine.erase(0, Pos + Delim.length());
	}
	if (RecordLine != "")
		vRecord.push_back(RecordLine);
	return vRecord;
}

void PrintClientRecordLine(string RecordLine) {
	vector <string> vRecord = ConvertLineToRecord(RecordLine);
	cout << "|" << left << setw(14) << vRecord[0] << "|" << left << setw(10) << "PIN Code" << "|" << left << setw(30) << "Client Name " << "|" << left << setw(10) << "Phone Number" << "|" << left << setw(10) << "Balance" << "|" << endl;

}
void ShowAllClientsScreen() {
	vector <string> vString = LoadClientsFromFile(FileName);
	cout << " --------------------------------------------------------------------------------" << endl;
	cout << "|" << left << setw(14) << "Account Number" << "|" << left << setw(10) << "PIN Code" << "|" << left << setw(30) << "Client Name " << "|" << left << setw(10) << "Phone Number" << "|" << left << setw(10) << "Balance" << "|" << endl;
	cout << " --------------------------------------------------------------------------------" << endl;
	if (vString.size() == 0)
		cout << "No Client Available in the system!" << endl;
	else
		for (string sString : vString) {
			PrintClientRecordLine(sString);
		}

};

void ShowAddClientScreen() {

};

void ShowDeleteClientScreen() {

};

void ShowUpdateClientScreen() {

};

void ShowFindClientScreen() {

};

void ShowEndScreen() {

};

void PerformingMainMenueOption(enMainMenuOptions MainMenuOption) {
	system("cls");
	switch (MainMenuOption)
	{
	case eClientList:
		ShowAllClientsScreen();
		break;
	case eAddClient:
		ShowAddClientScreen();
		break;
	case eDeleteClient:
		ShowDeleteClientScreen();
		break;
	case eUpdateClient:
		ShowUpdateClientScreen();
		break;
	case eFindClient:
		ShowFindClientScreen();
		break;
	case eExit:
		ShowEndScreen();
		break;
	default:

		break;
	}

	GoBackToMainMenuScreen();
}

short ReadMainMenuOption() {
	short Choice;
	do {
		cout << "Chose what do you want to do? [1 to 6]" << endl;
		cin >> Choice;
	} while (Choice < 1 || Choice > 6);
	return Choice;
}
void PrintMainMenuScreen() {
	cout << "======================================" << endl;
	cout << setw(5) << "Main Menu Screen : " << endl;
	cout << "======================================" << endl;
	cout << setw(3) << "[1] Show client list." << endl;
	cout << setw(3) << "[2] Add New client." << endl;
	cout << setw(3) << "[3] Delete client." << endl;
	cout << setw(3) << "[4] Update client info." << endl;
	cout << setw(3) << "[5] Find client." << endl;
	cout << setw(3) << "[6] Exit" << endl;
	cout << "======================================" << endl << endl;
	
	PerformingMainMenueOption((enMainMenuOptions) ReadMainMenuOption());
}

int main() {
	ShowClientList();
	PrintMainMenuScreen();

	system("pause>0");
	return 0;
}