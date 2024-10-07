#include <iostream>
#include <string>

using namespace std;

string ReadText(string Message) {
	string Text;
	cout << Message;
	getline(cin, Text);
	return Text;
}
string ReplaceWord(string Text, string sWordToReplace, string sReplacedWord) {
	
	short Pos = Text.find(sWordToReplace);
	while (Pos != string::npos) {
		Text.replace(Pos, sWordToReplace.length(), sReplacedWord);
		Pos = Text.find(sWordToReplace);
	}
	return Text;
}

int main() {
	string sText = ReadText("Please enter your text : ");
	string sFirstWord = ReadText("Please enter the word that will be replaced : ");
	string sSecondWord = ReadText("Please enter the word that will be in the place of replaced word : ");

	cout << ReplaceWord(sText, sFirstWord, sSecondWord);
	return 0;
}