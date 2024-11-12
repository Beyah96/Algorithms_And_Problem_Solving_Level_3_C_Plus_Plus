#pragma onces
#include <iostream>
#include <string>
#include <iomanip>
#include "LibReaders.h"
#include <fstream>
using namespace std;
using namespace LibReaders;
namespace ClientLib {

	struct stClient {
		string AccountNumber, PinCode, FullName, PhoneNumber;
		double AccountBalance;
	};

	string ConvertRecordToStringLine(stClient Client, string Delim) {
		return Client.AccountNumber + Delim + Client.PinCode + Delim + Client.FullName + Delim + Client.PhoneNumber + Delim + to_string(Client.AccountBalance);
	}

	void AddNewLineToFile(string FileName, string Line) {
		fstream MyFile;
		MyFile.open(FileName, ios::out || ios::app);
		if (MyFile.is_open()) {
			MyFile << Line << endl ;
			MyFile.close();
		}
	}

	void AddingNewLineToFile(string FileName, string Delim) {
		char AddMore;
		do {
			AddNewLineToFile(FileName, ConvertRecordToStringLine(ReadClient(), Delim));
			cout << "Do you want to add more clients ? ";
			cin >> AddMore;
		} while (toupper(AddMore) == 'Y');
	}


	void ReadLinesFromFile(string FileName) {

	}
}