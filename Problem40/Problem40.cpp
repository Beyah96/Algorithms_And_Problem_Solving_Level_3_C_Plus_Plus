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

void FillArrayWithWords(string Arr[100], int& Length) {
	bool MoreWords = 1;
	Length = 0;
	while (MoreWords) {
		Arr[Length] = ReadWord();
		Length++;
		cout << "Do you want to add more words (Yes {1} / No {0}) : ";
		cin >> MoreWords;
	}
}

string JoinWords(string Arr[100], int Length, string Delim = " ") {
	string Text = "";
	for (int i = 0; i < Length; i++) {
		if (Arr[i] != " ")
			Text += Arr[i] + Delim;
	}
	return Text.substr(0, Text.length() - Delim.length());
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
	string Arr[100];
	int Length;
	cout << "Vector after join : " << JoinWords(FillVectorWithWords(), "###") << endl << endl;// you can chose a separatior with the param delim like Delim = "###;#"
	FillArrayWithWords(Arr, Length);
	cout << "Array after join : " << JoinWords(Arr, Length, "###");// you can chose a separatior with the param delim like Delim = "###;#"
	return 0;
}