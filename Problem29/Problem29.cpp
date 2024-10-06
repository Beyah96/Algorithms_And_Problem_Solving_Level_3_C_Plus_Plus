#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void CountCapitalAndSmallLetters(string Text, int& CounterSmallLetters, int& CounterCapitalLetters) {
	for (int i = 0; i < Text.length(); i++){
		if (isupper(Text[i]))
			CounterCapitalLetters++;
		else if (islower(Text[i]))
			CounterSmallLetters++;
	}
}

string ReadText() {
	string Message;
	cout << "Please enter a text : ";
	getline(cin, Message);
	return Message;
}

int main() {
	int CountCapital = 0, CountSmall = 0;
	string Text = ReadText();
	CountCapitalAndSmallLetters(Text, CountCapital, CountSmall);

	cout << "String Length : " << Text.length() << endl;
	cout << "Capital Letters Count : " << CountCapital << endl;
	cout << "Small Letters Count : " << CountSmall << endl;
	
	return 0;
}