#pragma once 
#include <iostream>
#include <cstdlib>

using namespace std;

namespace MyLib
{
	int GetRandomNumber(int From, int To) {
		return rand() % (To - From + 1) + From;
	}

	int ReadNumber(string Message) {
		int Number;
		do { 
			cout << Message;
			cin >> Number;
		} while (Number < 0 || Number > 10);
		return Number;
	}
}