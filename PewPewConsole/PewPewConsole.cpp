// PewPewConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>	
#include <iostream>
#include "console_helper.h"

//#include "console_helper.h"

int main()
{
	SetConsoleWindowSize(100, 30);
	RestrictWindowSizing();

	char letter = 'A';
	for (int i = 1; i <= 3000;++i)
	{
		std::cout << letter;
		if (i % 100 == 0)
			++letter;
	}
	system("PAUSE");
}
