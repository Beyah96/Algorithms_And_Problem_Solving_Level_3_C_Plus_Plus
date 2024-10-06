#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <vector>

using namespace std;

char ReadLetter() {
	char Letter;
	cout << "Please enter a Letter : ";
	cin >> Letter;
	return Letter;
}

bool IsVowel(char c) {
	c = tolower(c);
	return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

void PrintIsVowel(char c) {
	if (IsVowel(c))
		printf("Yes letter '%c' is a vowel", c);
	else
		printf("No letter '%c' is not a vowel", c);

}

int main() {
	
	PrintIsVowel(ReadLetter());
	return 0;
}