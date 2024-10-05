#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadText() {
	string Message;
	cout << "Please enter your text  : "; 
	getline(cin, Message);
	return Message;
}

void PrintFristWordLowerCased() {
	string Message = ReadText();
	bool isFirstLetter = true;
	for (int i = 0; i < Message.length(); i++) {
		if (Message[i] != ' ' && isFirstLetter)
			Message[i] = tolower(Message[i]);
		isFirstLetter = (Message[i] == ' ') ? true : false;
	}
	cout << Message;
}

int main() {
	PrintFristWordLowerCased();
	return 0;
}