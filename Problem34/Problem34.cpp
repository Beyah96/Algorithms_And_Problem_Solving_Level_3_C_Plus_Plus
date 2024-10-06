#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string ReadText() {
	string Text;
	cout << "Please enter your text : ";
	getline(cin, Text);
	return Text;
}

bool IsVowel(char c) {
	c = tolower(c);
	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'u') || (c == 'o'));
}

void PrintVowelsInText(string Text) {
	cout << "Vowels in text are : ";
	for (int i = 0; i < Text.length(); i++)
		if (IsVowel(Text[i]))
			cout << setw(2) << Text[i] << "  ";
}

int main() {
	PrintVowelsInText(ReadText());
	return 0;
}