#include <windows.h>
void SetConsoleWindowSize(int width, int height)
{
	// Link to original code
	//https://social.msdn.microsoft.com/Forums/vstudio/en-US/0de248af-3497-4537-bb41-6d129b04fb27/console-how-change-window-size?forum=vclanguage

	CONSOLE_SCREEN_BUFFER_INFOEX consolesize;

	consolesize.cbSize = sizeof(consolesize);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfoEx(hConsole, &consolesize);

	COORD c;
	c.X = width;
	c.Y = height;
	consolesize.dwSize = c;

	consolesize.srWindow.Left = 0;
	consolesize.srWindow.Right = width;
	consolesize.srWindow.Top = 0;
	consolesize.srWindow.Bottom = height;

	SetConsoleScreenBufferInfoEx(hConsole, &consolesize);

}

void RestrictWindowSizing()
{

	HWND console = GetConsoleWindow();
	long dwStyle = GetWindowLong(console, GWL_STYLE);
	dwStyle ^= WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_VSCROLL;
	SetWindowLong(console, GWL_STYLE, dwStyle);
}