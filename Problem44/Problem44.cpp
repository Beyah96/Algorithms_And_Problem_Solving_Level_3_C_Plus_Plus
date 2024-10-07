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

string RemovePunctuation(string Text) {
	string NewText= "";
	for (int i = 0; i < Text.length(); i++)
		if (!ispunct(Text[i]))
			NewText += Text[i];
	return NewText;
}
int main() {
	cout << RemovePunctuation(ReadText());
	return 0;
}