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

vector <string> SplitString(string Text) {
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

string ReverseText(vector <string> vString) {
	string Text;
	vector <string>::iterator iter = vString.end();
	while (iter != vString.begin()) {
		iter--;
		Text += *iter + " ";
	}

	return Text.substr(0, Text.length() - 1);
}

int main() {
	cout << "Reversed Text : " << ReverseText(SplitString(ReadString("Please enter your Text : ")));
	return 0;
}