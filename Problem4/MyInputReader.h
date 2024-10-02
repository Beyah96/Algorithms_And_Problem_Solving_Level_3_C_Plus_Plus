#pragma once

#include <iostream>
#include <cstdlib>

namespace MyInputReader
{
	int GetRandomNumber(int From, int To) {
		return rand() % (To - From + 1) + From;
	}
}