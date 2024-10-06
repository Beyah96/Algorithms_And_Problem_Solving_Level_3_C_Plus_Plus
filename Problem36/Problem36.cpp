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

int CountNumberOfWordInText(string Text) {
	short Number = 0, Pos;
	string sWord, Delim = " ";
	while ((Pos = Text.find(Delim))!= string::npos) {
		sWord = Text.substr(0, Pos);
		if (sWord != " ")
			Number++;
		Text.erase(0, Pos + Delim.length());
	}
	if (Text != "")
		Number++;
	return Number;
}

int main() {
	cout << "The number of word in your string is : " << CountNumberOfWordInText(ReadText());
	return 0;
}