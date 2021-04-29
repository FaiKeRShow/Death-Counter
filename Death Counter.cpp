#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool KEY[256];
const char name[] = "Death Counter.txt";


void GetKEY()
{
	int i = 0;
	while (i < 256)
	{
		if (GetAsyncKeyState(i)) KEY[i] = 1; else KEY[i] = 0;
		i++;
	}
}

int GetDeath() {
	ifstream in(name);
	if (in.is_open()) {
		string line;
		while (getline(in, line)) {
			return line[7];
		}
		in.close();
	}
	else {
		in.close();
		return 0;
	}

}


int main() {
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	ofstream out;
	while (true) {
		int death = GetDeath() - 48;
		GetKEY();
		if (KEY[107]) {
			death++;
			out.open(name);
			out << "Death: " << death;
			out.close();
		}
		if (KEY[105]) {
			return 0;
		}
		Sleep(100);

	}
}