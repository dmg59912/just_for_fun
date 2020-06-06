#include<iostream>
//#include<string>
#include<Windows.h>

std::wstring tetrimino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char* pField = nullptr;

int n_screen_width = 80;
int n_screen_height = 30;

int Rotate(int px, int py, int r);

int main(void)
{
	//creating asssets
	tetrimino[0].append(L"..X.");
	tetrimino[0].append(L"..X.");
	tetrimino[0].append(L"..X.");
	tetrimino[0].append(L"..X.");

	tetrimino[1].append(L"..X.");
	tetrimino[1].append(L".XX.");
	tetrimino[1].append(L".X..");
	tetrimino[1].append(L"....");

	tetrimino[2].append(L".X..");
	tetrimino[2].append(L".XX.");
	tetrimino[2].append(L"..X.");
	tetrimino[2].append(L"....");

	tetrimino[3].append(L"....");
	tetrimino[3].append(L".XX.");
	tetrimino[3].append(L".XX.");
	tetrimino[3].append(L"....");

	tetrimino[4].append(L"..X.");
	tetrimino[4].append(L".XX.");
	tetrimino[4].append(L"..X.");
	tetrimino[4].append(L"....");

	tetrimino[5].append(L"....");
	tetrimino[5].append(L".XX.");
	tetrimino[5].append(L"..X.");
	tetrimino[5].append(L"..X.");

	tetrimino[6].append(L"....");
	tetrimino[6].append(L".XX.");
	tetrimino[6].append(L".X..");
	tetrimino[6].append(L".X..");

	//creat play field

	pField = new unsigned char[nFieldWidth * nFieldHeight];
	for (int x = 0; x < nFieldWidth; x++)// board boundry
		for (int y = 0; y < nFieldHeight; y++)
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;

	//create screen buffer 
	wchar_t* screen = new wchar_t[n_screen_width * n_screen_height];
	for (int i = 0; i < n_screen_height * n_screen_width; i++)
		screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	bool bGameOver = false;

	while (!bGameOver)
	{
		//Draw field
		for (int x = 0; x < nFieldWidth; x++)
			for (int y = 0; y < nFieldHeight; y++)
				screen[(y + 2) * n_screen_width + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
		//displpay frame
		WriteConsoleOutputCharacter(hConsole, screen, n_screen_width * n_screen_height, { 0,0 }, &dwBytesWritten);
	}

	return 0;
}

int Rotate(int px, int py, int r)
{
	switch (r % 4)
	{
	case 0: return py * 4 + px;         //rotate 0 degrees
	case 1: return 12 + py - (px * 4);  //rotate 90 degrees
	case 2: return 15 - (py * 4) - px;  //rotate 180 degrees
	case 3: return 3 - py + (px * 4);   //rotate 270 degrees
	}
}