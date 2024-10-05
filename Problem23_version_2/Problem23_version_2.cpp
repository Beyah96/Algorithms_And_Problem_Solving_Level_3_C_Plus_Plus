#include <iostream>
#include <string>
using namespace std;

string ReadText() {
	string Message;
	cout << "Please enter your Text : ";
	getline(cin, Message);
	return Message;
}

void PrintFirstLetters() {
	string Message = ReadText();
	bool isFirstLetter = true;
	for (int i = 0; i < Message.length(); i++){
		if (Message[i] != ' ' && isFirstLetter)
			cout << Message[i] << endl;
		isFirstLetter = (Message[i] == ' ');
	}
}

int main() {
	PrintFirstLetters();
	return 0;
}