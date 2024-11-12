#pragma once
#include <iostream>
#include <string>


using namespace std;

namespace LibReaders {
	string ReadString(string Message) {
		string Text;
		cout << Message << " : ";
		getline(cin >> ws, Text);
		return Text;
	}

	ClientLib::stClient ReadClient() {
		ClientLib::stClient Client;
		Client.AccountNumber = ReadString("Please enter your account number : ");
		Client.PinCode = ReadString("Please enter your Pin Code : ");
		Client.FullName = ReadString("Please enter your FullName : ");
		Client.PhoneNumber = ReadString("Please enter your phone number : ");
		Client.AccountBalance = stod(ReadString("Please enter your account balance : "));
		return Client;
	}

}