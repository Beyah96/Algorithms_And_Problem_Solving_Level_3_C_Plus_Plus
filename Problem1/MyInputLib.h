#pragma once
#include <iostream>
#include <cstdlib>

namespace MyInputLib
{
	int RandomNumber(int From, int To) {
		return rand() % (To - From + 1) + From;
	}

}
