#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadWord() {
	string Word;
	cout << "Please enter a word: ";
	cin >> Word;
	return Word;
}

vector <string> FillVectorWithWords() {
	bool MoreWords = 1;
	vector <string> vWords;
	while (MoreWords) {
		vWords.push_back(ReadWord());
		cout << "Do you want to add more words (Yes {1} / No {0}) : ";
		cin >> MoreWords;
	}
	return vWords;
}

string JoinWords(vector <string> vWords, string Delim = " ") {
	string Text = "";
	for (string Word : vWords) {
		if (Word != " ")
			Text += Word + Delim;
	}
	return Text.substr(0, Text.length() - Delim.length());
}
int main() {
	cout << "Vector after join : " << JoinWords(FillVectorWithWords(), "###");// you can chose a separatior with the param delim like Delim = "###;#"
	return 0;
}