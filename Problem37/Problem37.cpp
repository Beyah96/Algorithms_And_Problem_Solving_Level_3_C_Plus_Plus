#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText() {
	string Text;
	cout << "Please enter your text : ";
	getline(cin, Text);
	return Text;
}

vector <string> SplitText(string Text, string Delim = " ") {
	short Pos;
	string sWord;
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

void PrintWordsVectorContentAndLength(string Text) {
	vector <string> vWords = SplitText(Text);
	cout << "Tokens : " << vWords.size() << endl;
	for (string& Word : vWords)
		cout << Word << endl;
}

int main() {
	PrintWordsVectorContentAndLength(ReadText());
	return 0;
}