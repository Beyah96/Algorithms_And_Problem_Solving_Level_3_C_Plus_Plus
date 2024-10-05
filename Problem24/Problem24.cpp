#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadText() {
	string Message;
	cout << "Please enter your text : ";
	getline(cin, Message);
	return Message;
}

void PrintFirstLettersUpperCase() {
	string Message = ReadText();
	bool isFirstLetter = true;
	for (int i = 0; i < Message.length(); i++) {
		if (Message[i] != ' ' && isFirstLetter)
			Message[i] = toupper(Message[i]);
		isFirstLetter = (Message[i] == ' ');
	}
	cout << Message;
}

int main() {
	PrintFirstLettersUpperCase();
	return 0;
}