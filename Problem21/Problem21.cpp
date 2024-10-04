#include <iostream>
#include <iomanip>
using namespace std;

int Fibonacci(int A) {
	if (A >= 2)
		return Fibonacci(A - 1) + Fibonacci(A - 2);
	else
		return 1;
}
int main() {
	int Number, A = 0, B = 0;
	for (int i = 0; i < 10; i++)
		cout << setw(3) << Fibonacci(i) << "   ";
}