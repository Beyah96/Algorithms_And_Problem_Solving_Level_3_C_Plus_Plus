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

vector <string> TextToVector(string Text) {
	string ReversedText;
	short Pos;
	string sWord, Delim = " ";
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

string ReverseText(vector <string> vWords) {
	string ReversedText = "";
	vector <string>::iterator Iter = vWords.end();
	while (Iter != vWords.begin()) {
		Iter--;
		ReversedText += *Iter + " ";
	}

	return ReversedText;
}

int main() {
	string Text = ReadText();
	cout << ReverseText(TextToVector(Text)) << endl;

}