#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText() {
	string Text;
	cout << "Please enter your Text : ";
	getline(cin, Text);
	return Text;
}

string TrimLeft(string Text)
{
	for (int i = 0; i < Text.length(); i++)
		if (Text[i] != ' ')
			return Text.substr(i, Text.length() - i);
	return "";
}

string TrimRight(string Text) {
	for (int i = Text.length() - 1; i >= 0; i--)
		if (Text[i] != ' ')
			return Text.substr(0, i + 1);
	return "";
}

string Trim(string Text) {
	return TrimLeft(TrimRight(Text));
}

int main() {
	string Text = ReadText();
	cout << "Text       :" << Text << endl;
	cout << "Trim left  :" << TrimLeft(Text) << endl;
	cout << "Trim Right :" << TrimRight(Text) << endl;
	cout << "Trim       :" << Trim(Text) << endl;
	return 0;
}