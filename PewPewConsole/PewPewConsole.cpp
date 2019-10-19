// PewPewConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>	
#include <iostream>
#include <chrono>
#include <string>
#include "graphics_engine.h"

const int console_width = 100;
const int console_height = 20;
int main()
{
	graphicsEngine gr(console_width, console_height,8,8);
	//// Clear screen
	for (int i = 0; i < gr.totalBytes(); ++i) // totalBytes = width*height
		gr.screen[i] = ' ';

	char a = 'a';
	chrono::system_clock::time_point t1;
	chrono::system_clock::time_point t2;
	while (true)
	{
		t2 = chrono::system_clock::now();
		chrono::duration<float> elaspedTime = t2 - t1;
		t1 = t2;
		float _felasped = elaspedTime.count();

		gr.draw();
		std::cout << 1.f / _felasped << "\n";
		// Show framerate in title
		//char buff[30];
		////sprintf(buff, "title FPS: %f", _felasped);
		//printf(_felasped);

		//gr.draw();
	}

	//	float x = 0;
	//swprintf_s((wchar_t*)(gr.screen + (int)x), 20, L"%s", msg);
	//x += 150 *gr.felasped();
	//if (x >= gr.totalBytes()) x = 0;

	system("PAUSE");
}
