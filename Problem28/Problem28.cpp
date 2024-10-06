#include <iostream>
#include <cctype>
#include <string>

using namespace std;

char InvertLetterCase(char c) {
	return (isupper(c) ? tolower(c) : toupper(c));
}

string ReadText() {
	string Text;
	cout << "Please enter your text : ";
	getline(cin, Text);
	return Text;
}

void PrintInvetedTextCase(string Text) {
	for (int i = 0; i < Text.length(); i++)
		if (Text[i] != ' ')
			Text[i] = InvertLetterCase(Text[i]);
	cout << "The inverted text : " << Text << endl;
}

int main() {
	PrintInvetedTextCase(ReadText());
	return 0;
}