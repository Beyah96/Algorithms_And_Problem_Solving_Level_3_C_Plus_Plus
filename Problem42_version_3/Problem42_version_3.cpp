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

string ReplaceString(string Text, string StringToReplace, string ReplacedString) {
	short Pos;
	while ((Pos = Text.find(StringToReplace)) != string::npos) {
		Text = Text.replace(Pos, StringToReplace.length(), ReplacedString);
	}
	return Text;
}

int main() {
	string Text = ReadString("Please enter your text : "), StringToReplace = ReadString("Witch word do you want to replace : "), ReplacedString = ReadString("With what? :");
	cout << ReplaceString(Text, StringToReplace, ReplacedString);
	return 0;
}