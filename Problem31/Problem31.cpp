#include <iostream>
#include <cctype>
#include <string>
#include <cstdio>

using namespace std;
char InvertLetterCase(char c) {
	return (isupper(c) ? tolower(c) : toupper(c));
}

int CountLetterOccurence(string Message, char SearchedLetter, bool AllCases = false) {
	int Number = 0, NumberUnMachCase = 0;

	for (int i = 0; i < Message.length(); i++){
		if (Message[i] == SearchedLetter)
			Number++;
		if (Message[i] == InvertLetterCase(SearchedLetter) && AllCases)
			NumberUnMachCase++;
	}
	return Number + NumberUnMachCase;
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

	printf("\nLetter %c count  = %d", SearchedLetter, CountLetterOccurence(Text, SearchedLetter));
	printf("\nLetter %c count  = %d", SearchedLetter, CountLetterOccurence(Text, SearchedLetter, true));

	return 0;
}