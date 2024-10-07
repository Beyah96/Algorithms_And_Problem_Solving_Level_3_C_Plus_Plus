#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stClient {
	string AccountNumber, FullName, PINCode, PhoneNumber;
	double AccountBalance;
};

string ReadText() {
	string Text;
	cout << "Please enter your text : ";
	getline(cin, Text);
	return Text;
}
vector <string> TextToVector(string Text, string Delim) {
	vector <string> vText;
	string sWord;
	short Pos;
	while ((Pos = Text.find(Delim)) != string::npos) {
		sWord = Text.substr(0, Pos);
		if (sWord != " ")
			vText.push_back(sWord);
		Text.erase(0, Pos + Delim.length());
	}
	if (Text != "")
		vText.push_back(Text);
	return vText;
}
stClient GetRecordDetails(vector <string> vText, stClient& Client) {
	Client.AccountNumber = vText[0];
	Client.PINCode = vText[1];
	Client.FullName = vText[2];
	Client.PhoneNumber = vText[3];
	Client.AccountBalance = stod(vText[4]);
	return Client;
}
void PrintRecordDetails(stClient Client) {
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "PINCode         : " << Client.PINCode << endl;
	cout << "Full Name       : " << Client.FullName << endl;
	cout << "Phone Number    : " << Client.PhoneNumber << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;
}

int main() {
	stClient Client;
	string Text = ReadText(), Delim = "#//*//#";
	cout << "The following is the extracted client record : " << endl;
	PrintRecordDetails(GetRecordDetails(TextToVector(Text, Delim), Client));
	return 0;
}