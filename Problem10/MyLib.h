#pragma once

#include <iostream>
#include <cstdlib>

namespace MyLib
{
	int GetRandomNumber(int From, int To) {
		return rand() % (To - From + 1) + From;
	}
}