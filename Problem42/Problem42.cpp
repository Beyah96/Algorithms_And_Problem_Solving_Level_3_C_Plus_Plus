#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText(string Message) {
	string Text;
	cout << Message;
	getline(cin, Text);
	return Text;
}

vector <string> TextToVector(string Text) {
	vector <string> vWords;
	short Pos;
	string Delim = " ", sWord;
	while ((Pos = Text.find(Delim)) != string::npos) {
		sWord = Text.substr(0, Pos);
		if (sWord != " ")
			vWords.push_back(sWord);
		Text.erase(0, Pos + Delim.length());
	}
	if (Text != "")
		vWords.push_back(Text);
	return vWords;
}

vector <string> ReplaceWordInVector(string Text, string RemovedWord, string ReplacedWord) {
	vector <string> vWords = TextToVector(Text);
	for (string& sWord : vWords)
		if (sWord == RemovedWord)
			sWord = ReplacedWord;
	return vWords;
}

string GetStringAfterReplace(string Text, string RemovedWord, string ReplacedWord) {
	vector <string> vWords = ReplaceWordInVector(Text, RemovedWord, ReplacedWord);
	string ReplacedSring = "";
	for (string sWord : vWords)
		ReplacedSring += sWord + " ";
	return ReplacedSring;
}



int main() {
	string sText = ReadText("Please enter your text : ");
	string sFirstWord = ReadText("Please enter the word that will be replaced : ");
	string sSecondWord = ReadText("Please enter the word that will be in the place of replaced word : ");
	cout << GetStringAfterReplace(sText, sFirstWord, sSecondWord);
	return 0;
}