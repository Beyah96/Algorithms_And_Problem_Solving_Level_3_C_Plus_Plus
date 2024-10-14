#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

struct stClient {
	string AccountNumber, PINCode, FullName, PhoneNumber;
	double AccountBalance;
};

string PromptUserInput(string Message) {
	string Text;
	cout << Message;
	getline(cin >> ws, Text);
	return Text;
}

double PromptPositiveDoubleInput(string Message) {
	double Number;
	cout << Message;
	cin >> Number;
	return Number;
}

stClient CollectClientData() {
	stClient Client;
	Client.AccountNumber = PromptUserInput("Account Number  : ");
	Client.PINCode = PromptUserInput("PIN code        : ");
	Client.FullName = PromptUserInput("Full Name       : ");
	Client.PhoneNumber = PromptUserInput("Phone Number    : ");
	Client.AccountBalance = stod(PromptUserInput("Account Balance : "));

	return Client;
}

string ConvertClientRecodsToLine(stClient Client, string Delim) {
	return Client.AccountNumber + Delim + Client.PINCode + Delim + Client.FullName + Delim + Client.PhoneNumber + Delim + to_string(Client.AccountBalance);
}

void AppendClient(string FileName, string Text) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open()) {
		MyFile << Text << endl;
		MyFile.close();
	}
}

void AddClientsToFile(string FileName, string Delim) {
	char AddMoreClients;
	do {
		AppendClient(FileName, ConvertClientRecodsToLine(CollectClientData(), Delim));
		cout << "Do you want to add more clients ? Y/y (yes) or N/n (No) : ";
		cin >> AddMoreClients;
	} while (toupper(AddMoreClients) == 'Y');
}

vector <string> ReadFileLines(string FileName) {
	vector <string> vLines;
	string Line;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		while (getline(MyFile, Line))
			vLines.push_back(Line);
		MyFile.close();
	}
	return vLines;
}

vector <string> ParseClientRecord(string Line, string Delim) {
	string sWord;
	short Pos;
	vector <string> vLine;
	while ((Pos = Line.find(Delim)) != string::npos) {
		sWord = Line.substr(0, Pos);
		if (sWord != " ")
			vLine.push_back(sWord);
		Line.erase(0, Pos + Delim.length());
	}
	if (Line != "")
		vLine.push_back(Line);
	return vLine;
}

stClient SplitLineToClients(vector <string> vLine) {
	stClient Client;
	Client.AccountNumber = vLine[0];
	Client.PINCode = vLine[1];
	Client.FullName = vLine[2];
	Client.PhoneNumber = vLine[3];
	Client.AccountBalance = stod(vLine[4]);

	return Client;
}

vector <stClient> GetListOfClient(vector <string> vLines, string Delim) {
	stClient Client;
	vector <string> vLine;
	vector <stClient> vClients;
	for (string sLine : vLines) {
		vLine = ParseClientRecord(sLine, Delim);
		Client = SplitLineToClients(vLine);
		vClients.push_back(Client);
	}
	return vClients;
}

bool IsFound(vector <stClient> vClients, string SearchedAccountNumber, stClient& Client) {
	for (stClient sClient : vClients)
		if (sClient.AccountNumber == SearchedAccountNumber){
			Client = sClient;
			return true;
		}
	return false;
}


void DisplayClientsList(vector <stClient> vClients) {
	
	cout << "Client list (" << vClients.size() << " clients) : " << endl;
	cout << " ------------------------------------------------------------------------------------------" << endl;
	cout << "|" <<left << setw(16) << "Account Number";
	cout << "|" <<left << setw(9) << "PIN Code";
	cout << "|" <<left << setw(32) << "Full Name";
	cout << "|" <<left << setw(12) << "Phone Number";
	cout << "|" <<left << setw(17) << "Account Balance" << "|";
	cout << endl;
	cout << " ------------------------------------------------------------------------------------------" << endl;

	for (stClient Client : vClients) {
		cout << "|" << left << setw(16) << Client.AccountNumber;
		cout << "|" << left << setw(9) << Client.PINCode;
		cout << "|" << left << setw(32) << Client.FullName;
		cout << "|" << left << setw(12) << Client.PhoneNumber;
		cout << "|" << left << setw(17) << Client.AccountBalance << "|";
		cout << endl;
		cout << " ------------------------------------------------------------------------------------------" << endl;

	}
}


void FindClientById(vector <stClient> vClients, string SearchedAccountNumber) {
	stClient Client;
	vector <stClient> vTempClients;
	if (IsFound(vClients, SearchedAccountNumber, Client)) {
		vTempClients.push_back(Client);
		DisplayClientsList(vTempClients);
	}
	else
		cout << "Client not found!!" << endl;
}

vector <stClient> DeleteClientByAccountNumber(vector <stClient> vClients, string DeletedAccountNumber) {
	stClient Client;
	char DeteteAccount;
	vector <stClient> vTempClients;
	if (IsFound(vClients, DeletedAccountNumber, Client)) {
		cout << "Are you sure you want delete this Account? Y or N ? : ";
		cin >> DeteteAccount;
		if (toupper(DeteteAccount) == 'Y') {
			vector <stClient>::iterator iter;
			for (iter = vClients.end() - 1; iter <= vClients.begin(); iter--) {
				if (iter->AccountNumber != DeletedAccountNumber) {
					vTempClients.push_back(*iter);
				}
			}
			cout << "Client Deleted Successfully.";
			return vTempClients;
		}
	}
	else
		cout << "Client not found!!" << endl;
	return vClients;
}

void UpdateFileAfterDelete(string FileName, string Delim, vector <stClient> vClients, string DetetedAccountNumber) {
	vector <stClient> vTempClients = DeleteClientByAccountNumber(vClients, DetetedAccountNumber);
	for (stClient& Client : vTempClients){
		AppendClient(FileName, ConvertClientRecodsToLine(Client, Delim));
	}
}


int main() {
	string FileName = "Clients.txt", Delim = "#/**/#", SearchedAccountNumber = "A335", DeletedAccountNumber = "A335";
	vector <stClient> vClients = GetListOfClient(ReadFileLines(FileName), Delim);
	//AddClientsToFile(FileName, Delim);
	
	cout << "Before deleting anything : " << endl;
	DisplayClientsList(vClients);
	
	cout << "\n\n Search result: " << endl;
	FindClientById(vClients, SearchedAccountNumber);
	
	
	UpdateFileAfterDelete(FileName, Delim, vClients, DeletedAccountNumber);
	vClients = GetListOfClient(ReadFileLines(FileName), Delim);
	
	cout << "\n\nAfter deleting an account : " << endl;
	DisplayClientsList(vClients);
	return 0;
}