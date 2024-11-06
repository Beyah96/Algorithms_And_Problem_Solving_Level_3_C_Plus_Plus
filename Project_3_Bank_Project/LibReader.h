#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace LibReader {

	short ReadPositiveNumber(string Message) {
		short Number;
		do {
			cout << Message <<" : ";
			cin >> Number;
		} while (Number < 0);
		return Number;
	}

	string ReadString(string Message) {
		string Text;
		cout << Message << " : ";
		getline(cin >> ws, Text);
		return Text;
	}
}