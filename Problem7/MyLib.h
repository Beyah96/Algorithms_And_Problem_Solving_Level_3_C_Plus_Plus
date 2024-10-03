#pragma once

#include <iostream>

namespace MyLib
{
	void Swap(int& A, int& B) {
		A = A + B; 
		B = A - B; 
		A = A - B; 
	}
}