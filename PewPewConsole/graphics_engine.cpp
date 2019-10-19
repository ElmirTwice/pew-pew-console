#include "graphics_engine.h"

#include <windows.h>
#include <chrono>

#include "console_helper.h"

graphicsEngine::graphicsEngine(int width, int height, int fontw, int fonth): 
	_width(width), _height(height), _totalBytes(width*height), dwBytesWritten(0)
{
	t1 = chrono::system_clock::now();
	t2 = chrono::system_clock::now();

	screen = new wchar_t[_width * _height];

	buffer = GetStdHandle(STD_OUTPUT_HANDLE);
	cmd_helper::SetConsoleBuffer(&buffer, _width, _height);
	cmd_helper::SetConsoleFont(&buffer, fontw, fonth);
	cmd_helper::SetConsoleWindowSizing();
}

// Default values. Would only be used for testing.
graphicsEngine::graphicsEngine(): graphicsEngine(100,70)
{}
