# Problem 21: Fibonacci Sequence Generation

## Description
This C++ program generates and prints the first 10 numbers in the Fibonacci sequence using a recursive function. The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, starting from 1.

## Code Breakdown

### 1. **Fibonacci Function**
The Fibonacci sequence is calculated recursively.

```cpp
int Fibonacci(int A) {
	if (A >= 2)
		return Fibonacci(A - 1) + Fibonacci(A - 2);
	return 1;
}
```
* `int Fibonacci(int A)`: This function computes the Fibonacci number at position A.
  * `If A >= 2`, the function calls itself recursively to calculate the sum of the two previous Fibonacci numbers `(Fibonacci(A - 1)` and `Fibonacci(A - 2))`.
  * `If A < 2`, the function returns `1`, as the first two Fibonacci numbers are defined as `1`.

### 2. **Main Function**
The main function prints the first `10` Fibonacci numbers.
```cpp
int main() {
	for (int i = 0; i < 10; i++)
		cout << setw(3) << Fibonacci(i) << "   ";
}
```
* `for (int i = 0; i < 10; i++)`: This loop runs `10` times to print the first `10` Fibonacci numbers.
* `cout << setw(3)`: The `setw(3)` function is used to set a width of `3` characters for each Fibonacci number, ensuring neat alignment in the output.

## Key Expression Explanation
* `Fibonacci(A - 1) + Fibonacci(A - 2)`: this is the recursive part of the Fibonacci function, which adds the Fibonacci number at position `A-1` and `A-2` to calculate the Fibonacci number at position `A`.
* `setw(3)`: this ensures that each number in the output is printed with at least `3` spaces for formatting, which helps align the numbers for easier readability.

## How to Run the Program
1. Compile: Use a C++ compiler to compile the program. For example:
```
g++ -o Problem21 Problem21.cpp
```
2. Execute: Run the compiled program:
```
./Problem21
```
## Example Output:
```
  1   1   2   3   5   8  13  21  34  55   
```
## Requirements
* A C++ compiler (e.g., g++)
* Basic understanding of recursion and control structures in C++
## Conclusion
This program generates the first 10 numbers in the Fibonacci sequence using a recursive approach. The recursive function effectively demonstrates the elegance of recursion in calculating Fibonacci numbers, though it can be inefficient for large values due to repeated calculations of the same subproblems.