#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool KEY[256];
const char name[] = "Counter Death.txt";


void GetKEY()
{
	int i = 0;
	while (i < 256)
	{
		if (GetAsyncKeyState(i)) KEY[i] = 1; else KEY[i] = 0;
		i++;
	}
}

string GetDeath() {
	ifstream in(name);
	string Value = "";
	if (in.is_open()) {
		string line;
		while (getline(in, line)) {
			for (int i = 7; i < size(line); i++)
				Value += line[i];
		}
		in.close();
		return Value;
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
	int death = atoi(GetDeath().c_str());
	while (true) {
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