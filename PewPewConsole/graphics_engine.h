#pragma once
#include <chrono>
#include "console_helper.h"

using namespace std;
class graphicsEngine
{
private:
	HANDLE buffer;
	DWORD dwBytesWritten;

	chrono::system_clock::time_point t1;
	chrono::system_clock::time_point t2;

	int _width;
	int _height;
	int _totalBytes;

	bool _showfraps = true;
	float _felasped = 0;
public:
	wchar_t *screen;


	graphicsEngine();
	graphicsEngine(int width, int height, int fontw = 12, int fonth = 12);

	inline int width() { return _width; }
	inline int height() { return _height; }
	inline int totalBytes() { return _totalBytes; }
	inline float felasped() { return _felasped; }
	inline float fraps() { return 1.0f / _felasped; }

	inline void draw()
	{
		//screen[_width * _height - 1] = '\0';
		WriteConsoleOutputCharacter(buffer, screen, _totalBytes, { 0,0 }, &dwBytesWritten);
		elapsed();
	}

private:
	inline void elapsed()
	{
		t2 = chrono::system_clock::now();
		chrono::duration<float> elaspedTime = t2 - t1;
		t1 = t2;
		_felasped = elaspedTime.count();
	}
};

