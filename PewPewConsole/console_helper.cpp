#include <iostream>
#include <windows.h>

namespace cmd_helper
{
	void Error(const char* msg)
	{
		std::cout << msg << std::endl;
	}

	void SetConsoleBuffer(PHANDLE buffer, int width, int height)
	{
		CONSOLE_SCREEN_BUFFER_INFOEX consolesize;
		consolesize.cbSize = sizeof(consolesize);
		GetConsoleScreenBufferInfoEx(*buffer, &consolesize);

		COORD c;
		c.X = width;
		c.Y = height;
		consolesize.dwSize = c;

		consolesize.srWindow.Left = 0;
		consolesize.srWindow.Right = width;
		consolesize.srWindow.Top = 0;
		consolesize.srWindow.Bottom = height;

		if (!SetConsoleScreenBufferInfoEx(*buffer, &consolesize))
			Error("SetConsoleCurrentBufferInfoEx failed.");

	}

	void SetConsoleWindowSizing()
	{

		HWND console = GetConsoleWindow();
		long dwStyle = GetWindowLong(console, GWL_STYLE);
		dwStyle ^= WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_VSCROLL;
		SetWindowLong(console, GWL_STYLE, dwStyle);
	}

	// Some functions of code are from help of this projet: 
	// https://github.com/OneLoneCoder/videos/blob/master/olcConsoleGameEngine.h

	void SetConsoleFont(PHANDLE buffer, int fontw, int fonth)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = fontw;
		cfi.dwFontSize.Y = fonth;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;

		wcscpy_s(cfi.FaceName, L"Consolas");

		if (!SetCurrentConsoleFontEx(*buffer, false, &cfi))
			return Error("SetCurrentConsoleFontEx failed.");
	}

	inline void DisableMouse(PHANDLE buffer)
	{
		//SetConsoleMode(*buffer, ENABLE_LINE)
	}
}

