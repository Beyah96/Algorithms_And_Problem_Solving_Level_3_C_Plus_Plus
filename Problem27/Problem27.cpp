#include <iostream>
#include <string>
#include <cctype>

using namespace std;


char ReadChar() {
	char c;
	cout << "Please enter a char : ";
	cin >> c;
	return c;
}

char InvertCharacterCase(char c) {
	return (isupper(c))? tolower(c) : toupper(c);
}

int main() {
	cout << InvertCharacterCase(ReadChar());
	return 0;
}