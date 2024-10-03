# Problem 7: Matrix Transposition

## Description
This C++ program demonstrates the process of transposing a 3x3 matrix. The program consists of a main function that utilizes several helper functions defined in a separate header file. The matrix is filled with ordered numbers, printed, transposed, and then printed again to show the result of the transposition.

## Code Breakdown

### 1. **Main Function**
The entry point of the program where the matrix operations are orchestrated.
```cpp
int main() {
	int Arr[3][3];
	MyMatrixMethods::FillMatrixWithOrderedNumbers(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr, "The following is a 3x3 ordered matrix : ");
	MyMatrixMethods::TransposeMatrix(Arr);
	MyMatrixMethods::PrintMatrixContent(Arr, "\n\nThe following is the 3x3 transposed matrix : ");
	return 0;
}
```
* `int Arr[3][3]`: Declares a 3x3 integer array to represent the matrix.
* `MyMatrixMethods::FillMatrixWithOrderedNumbers(Arr)`: Fills the matrix with ordered numbers from `1` to `9`.
* `MyMatrixMethods::PrintMatrixContent(Arr, "The following is a 3x3 ordered matrix : ")`: Prints the content of the matrix before transposition.
* `MyMatrixMethods::TransposeMatrix(Arr)`: Transposes the matrix by swapping elements.
* `MyMatrixMethods::PrintMatrixContent(Arr, "\n\nThe following is the 3x3 transposed matrix : ")`: Prints the content of the transposed matrix.

### 2. **Matrix Methods Header File (MyMatrixMethods.h)**
This file contains the definitions of matrix operations.

a. Filling the Matrix
```cpp
void FillMatrixWithOrderedNumbers(int Arr[3][3]) {
	int Counter = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Arr[i][j] = ++Counter;
}
```
* This function fills the 3x3 matrix with ordered numbers from 1 to 9 using nested loops. The Counter variable is incremented with each assignment.

b. Transposing the Matrix
```cpp
void TransposeMatrix(int Arr[3][3]) {
	for (int i = 0; i < (3 - floor(3 / 2)); i++)
		for (int j = i + 1; j < 3; j++)
			MyLib::Swap(Arr[i][j], Arr[j][i]);
}
```
* This function transposes the matrix by swapping the elements across the diagonal.
* The outer loop runs only through the upper triangle of the matrix `(i < (3 - floor(3 / 2)))`, ensuring each element is swapped only once. The inner loop starts from `i + 1` to avoid swapping elements back to their original positions.

c. Printing the Matrix
```cpp
void PrintMatrixContent(int Arr[3][3], string Message) {
	cout << Message << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(3) << Arr[i][j] << "   ";
		cout << endl;
	}
}
```

* This function prints the contents of the matrix with a formatted output, making use of setw for consistent spacing.
### 3. **Utility Functions (MyLib.h)**
This header file contains utility functions used for swapping elements.

a. Swapping Function
```cpp
void Swap(int& A, int& B) {
	A = A + B; 
	B = A - B; 
	A = A - B; 
}	
```
* This function swaps two integers using arithmetic operations without the need for a temporary variable. This method avoids additional memory usage but may lead to overflow in some edge cases.

## Key Expressions Explained 

`MyLib::Swap(Arr[i][j], Arr[j][i]);` : this line calls the Swap function to interchange the values of the elements at positions `(i, j)` and `(j, i)`, effectively performing the transposition.
`for (int i = 0; i < (3 - floor(3 / 2)); i++)` : the loop condition ensures that the outer loop only iterates through half the rows, optimizing the transposition by only processing the upper triangular part of the matrix.


## How to Run the Program
### 1. Compile: 
- Use a C++ compiler to compile the program. For example:
```
g++ -o Problem7 Problem7.cpp MyMatrixMethods.h MyLib.h
```
### 2. Execute: 
- Run the compiled program:
```
./Problem7
```
Example Output
```
The following is a 3x3 ordered matrix : 
  1   2   3   
  4   5   6   
  7   8   9   

The following is the 3x3 transposed matrix : 
  1   4   7   
  2   5   8   
  3   6   9   
```

## Requirements
 * A C++ compiler (e.g., g++)
 * Basic understanding of arrays, functions, and loops in C++
## Conclusion
This program effectively demonstrates matrix transposition and basic matrix operations in C++. The approach taken ensures clarity in the code and efficiency in the matrix manipulation process.