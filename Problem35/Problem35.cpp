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


void PrintOnNewLineEachWordOfTheText(string Text) {
	cout << "Your string's words are : " << endl;
	for (int i = 0; i < Text.length(); i++){
		if (Text[i] == ' ')
			cout << endl;
		else
			cout << Text[i];
	}
}

int main() {
	PrintOnNewLineEachWordOfTheText(ReadText());
	return 0;
}