#include <iostream>
#include <iomanip>
using namespace std;

int Fibonacci(int A) {
	if (A >= 2)
		return Fibonacci(A - 1) + Fibonacci(A - 2);
	return 1;
}
int main() {
	for (int i = 0; i < 10; i++)
		cout << setw(3) << Fibonacci(i) << "   ";
}