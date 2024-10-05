#include <iostream>
#include <string>

using namespace std;

void PrintFirstLetters(string Message) {
	cout << "First letters of this string : " << endl << Message[0] << endl;
	for (int i = 0; i < Message.length(); i++)
		if (Message[i] == ' ')
			cout << Message[i + 1] << endl;
}

int main() {
	PrintFirstLetters("Mohamed Said BEYAH A Software engineer");
	return 0;
}