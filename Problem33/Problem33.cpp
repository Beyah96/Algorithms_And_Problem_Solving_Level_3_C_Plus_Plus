#include <iostream>
#include <cstdio>
#include <string>

using  namespace std;

string ReadText() {
	string Message;
	cout << "Please enter your text : ";
	getline(cin, Message);
	return Message;
}

bool IsVowel(char c) {
	c = tolower(c);
	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

int CountVowelsInText(string Message) {
	int Counter = 0;
	for (int i = 0; i < Message.length(); i++)
		if (IsVowel(Message[i]))
			Counter++;
	return Counter;
}

int main() {
	cout << "Number of vowels is : " << CountVowelsInText(ReadText());
	return 0;
}