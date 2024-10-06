#include <iostream>
#include <cctype>
#include <string>

using namespace std;

enum enCountLettersCases { Small, Capital, All };

int CountCapitalAndSmallLetters(string Text, enCountLettersCases CounterLettersCases = enCountLettersCases::All) {
	
	if (CounterLettersCases == enCountLettersCases::All) {
		return Text.length();
	}
	int Counter = 0;
	for (int i = 0; i < Text.length(); i++) {
		if (CounterLettersCases == enCountLettersCases::Capital && isupper(Text[i]))
			Counter++;
		else if (CounterLettersCases == enCountLettersCases::Small && islower(Text[i]))
			Counter++;
	}
	return Counter;
}

string ReadText() {
	string Message;
	cout << "Please enter a text : ";
	getline(cin, Message);
	return Message;
}

int main() {
	string Text = ReadText();

	cout << "String Length : " << CountCapitalAndSmallLetters(Text) << endl;
	cout << "Capital Letters Count : " << CountCapitalAndSmallLetters(Text, enCountLettersCases::Capital) << endl;
	cout << "Small Letters Count : " << CountCapitalAndSmallLetters(Text, enCountLettersCases::Small) << endl;

	return 0;
}