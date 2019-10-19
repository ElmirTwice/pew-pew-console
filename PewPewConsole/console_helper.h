#pragma once
#include <Windows.h>

namespace cmd_helper
{
	void SetConsoleBuffer(PHANDLE buffer, int width, int height);
	void SetConsoleWindowSizing();
	void SetConsoleFont(PHANDLE buffer, int fontw, int fonth);
	void Error(const char* msg);
}