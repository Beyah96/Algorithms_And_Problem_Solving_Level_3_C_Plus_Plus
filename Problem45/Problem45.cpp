#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct stBankInfo {
	string AccountNumber, PhoneNumber, FullName, PINCode;
	double AccountBalance;
};

string ReadString(string Message) {
	string Text;
	cout << Message;
	getline(cin, Text);
	return Text;
}
double ReadDoubleNumber(string Message) {
	double Number;
	do {
		cout << Message;
		cin >> Number;
	} while (Number < 0);
	
	return Number;
}


string GetTextConcatenated(stBankInfo BankInfo, string Delim) {
	return BankInfo.AccountNumber + Delim + BankInfo.PINCode + Delim + BankInfo.FullName + Delim + BankInfo.PhoneNumber + Delim + to_string(BankInfo.AccountBalance);
}


int main() {
	stBankInfo BankInfo;
	BankInfo.AccountNumber = ReadString("Enter Account Number : ");
	BankInfo.FullName = ReadString("Enter Full Name : ");
	BankInfo.PhoneNumber = ReadString("Enter Phone Number : ");
	BankInfo.PINCode = ReadString("Enter PIN code : ");
	BankInfo.AccountBalance = ReadDoubleNumber("Enter Account Balance : ");
	cout << GetTextConcatenated(BankInfo, "#//#");
	return 0;
}