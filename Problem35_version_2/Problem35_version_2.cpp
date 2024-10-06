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

void PrintOneNewLineEachWordOfTheText(string Text) {
	string sWord, Delim = " ";
	short Pos;
	while ((Pos = Text.find(Delim)) != string::npos) {
		sWord = Text.substr(0, Pos);
		if (sWord != " ")
			cout << sWord << endl;
		Text.erase(0, Pos + Delim.length());
	}
	if (Text != "")
		cout << Text << endl;

}

int main() {
	PrintOneNewLineEachWordOfTheText(ReadText());
	return 0;
}