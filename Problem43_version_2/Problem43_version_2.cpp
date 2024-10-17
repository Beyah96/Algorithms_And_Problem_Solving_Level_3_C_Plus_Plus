#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString(string Message) {
	string Text;
	cout << Message;
	getline(cin, Text);
	return Text;
}

vector <string> SplitString(string Text, string Delim) {
	short Pos;
	vector <string> vString;
	string sWord;
	while ((Pos = Text.find(Delim)) != string::npos) {
		sWord = Text.substr(0, Pos);
		if (sWord != "")
			vString.push_back(sWord);
		Text.erase(0, Pos + Delim.length());
	}
	if (Text != "")
		vString.push_back(Text);
	return vString;
}

string ToLowerString(string sWord) {
	for (int i = 0; i < sWord.length(); i++) {
		sWord[i] = tolower(sWord[i]);
	}
	return sWord;
}

string ReplaceString(vector <string> vString, string StringToReplace, string ReplacedString, bool MatchCase) {
	string Text;
	for (string& sWord : vString){
		if (MatchCase && (sWord == StringToReplace))
			sWord = ReplacedString;
		else if (!MatchCase && (ToLowerString(sWord) == ToLowerString(StringToReplace)))
			sWord = ReplacedString;
		Text += sWord + " ";
	}
	return Text.substr(0, Text.length() - 1);
}

int main() {
	string Text = ReadString("Please enter your text : "), Delim = " ", StringToReplace = ReadString("Witch word do you want to replace : "), ReplacedString = ReadString("With what? :");
	cout << ReplaceString(SplitString(Text, Delim), StringToReplace, ReplacedString, false);
	return 0;
}