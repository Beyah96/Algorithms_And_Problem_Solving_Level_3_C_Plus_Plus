
#pragma once

#include <iostream>
#include <cstdlib>

namespace MyInputLib
{
	int GetRandomNumbers(int From, int To) {
		return rand() % (To - From + 1) + From;
	}
}