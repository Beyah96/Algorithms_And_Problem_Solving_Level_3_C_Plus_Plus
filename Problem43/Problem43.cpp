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
	string sWord, Delim = " ";
	short Pos;
	vector <string> vWords;
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

string ToLowereCase( string Text) {
	for (int i = 0; i < Text.length(); i++)
		Text[i] = tolower(Text[i]);
	return Text;
}

vector <string> ReplaceWord (vector <string> vWords, string sWordToReplace, string sWordReplaced, bool match) {
	for (string& sWord : vWords){
		if (match){
			if (sWord == sWordToReplace)
				sWord = sWordReplaced;
		}
		else{
			if ((sWord == sWordToReplace) || (ToLowereCase(sWord) == ToLowereCase(sWordToReplace)))
				sWord = sWordReplaced;
		}
	}

	return vWords;
}

string GetReplacedString(string Text, string sWordToReplace, string sWordReplaced, bool match = true) {
	vector <string> vWords = ReplaceWord(TextToVector(Text), sWordToReplace, sWordReplaced, match);
	string ReplacedWord = "";
	for (string& sWord : vWords) {
		ReplacedWord += sWord + " ";
	}
	return ReplacedWord;
}

int main() {
	string Text = ReadText("Please enter your text : ");
	string sWordToReplace = ReadText("Please enter the word to replace : ");
	string sWordReplaced = ReadText("Please enter the word replaced : ");
	cout << GetReplacedString(Text, sWordToReplace, sWordReplaced);
	return 0;
}