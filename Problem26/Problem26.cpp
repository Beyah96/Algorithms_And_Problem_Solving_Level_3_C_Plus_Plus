#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadText() {
	string Message;
	cout << "Please enter your text  : ";
	getline(cin, Message);
	return Message;
}

bool ReadOperation() {
	bool Operation;
	cout << "Do you want to upper (1) or lower (0) the integral text ? please enter 0 or 1 : ";
	cin >> Operation;
	return Operation;
}

void PrintIntegralStringUpperCased(string Message, bool UpperOrLower) {
	bool isFirstLetter = true;
	for (int i = 0; i < Message.length(); i++){
		if (UpperOrLower){
			Message[i] = toupper(Message[i]);
		}
		else
			Message[i] = tolower(Message[i]);
	}
	cout << Message;
}


int main() {
	string Text = ReadText();
	cout << "Your given text : " << Text << endl;
	bool Operation = ReadOperation();
	if (Operation)
		cout << "String after upper : ";
	else
		cout << "String after lower : ";
	PrintIntegralStringUpperCased(Text, Operation);
	cout << endl;
	return 0;
}