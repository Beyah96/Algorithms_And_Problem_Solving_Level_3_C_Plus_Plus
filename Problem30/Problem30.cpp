#include <iostream>
#include <cctype>
#include <string>
#include <cstdio>

using namespace std;

int CountLetterOccurence(string Message, char SearchedLetter) {
	int Number = 0;
	for (int i = 0; i < Message.length(); i++)
		if (Message[i] == SearchedLetter)
			Number++;
	return Number;
}



char ReadLetter() {
	char Letter;
	cout << "Please enter a text : ";
	cin >> Letter;
	return Letter;
}


string ReadText() {
	string Message;
	cout << "Please enter a text : ";
	getline(cin, Message);
	return Message;
}

int main() {
	string Text = ReadText();
	char SearchedLetter = ReadLetter();

	printf("Letter %c count  = %d", SearchedLetter, CountLetterOccurence(Text, SearchedLetter));

	return 0;
}