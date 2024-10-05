#include <iostream>
using namespace std;

int Fibonacci(int Number) {
	int A = 1, B = 1, R = 0;
	for (int i = 2; i < Number; i++) {
		R = A + B;
		B = A;
		A = R;
		

	}
	return R;
}

int main() {
	cout << Fibonacci(10);
	return 0;
}


