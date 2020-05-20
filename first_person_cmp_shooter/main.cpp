#include<iostream>
#include<Windows.h>

//using namespace std;


int n_screen_width = 120;
int n_screen_height = 40;


//this is to locate the player position 
float player_x_position = 8;
float player_y_position = 8;
float playerA = 0;


// i think this will be to have a mini map
int map_height = 16;
int map_width = 16;


// to detect if we are near a wall or far 
float ffo_view = 3.14156/4;
float fDepth = 16;
int main(void)
{

	//create screen buffer 
	wchar_t* screen = new wchar_t[n_screen_width * n_screen_height];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	std::wstring map;

	map +=L"################";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"#..............#";
	map += L"################";

	while (true)
	{
		for (int x = 0; x < n_screen_width; x++)
		{
			//for each column, calculate the projected ray angle into world space
			float fray_angle = (playerA - ffo_view / 2.0f) + ((float)x / (float)n_screen_width) * ffo_view;
			float f_distance_to_wall = 0;
			bool hit_wall = false;

			//need unit vector for ray in player space
			float f_eye_x = sinf(fray_angle);
			float f_eye_y = cosf(fray_angle);


			while (!hit_wall && f_distance_to_wall < fDepth  )
			{
				f_distance_to_wall += 0.1f;

				int n_testx = (int)(player_x_position + f_eye_x * f_distance_to_wall);
				int n_testy = (int)(player_y_position + f_eye_y * f_distance_to_wall);

				//test if ray is out of bounds
				if (n_testx < 0 || n_testx >= map_width || n_testy < 0 || n_testy >= map_height)
				{
					hit_wall = true;
					f_distance_to_wall = fDepth;
				}
				else
				{
					//ray is inbounds so test to see if the ray cell is a wall block 
					if (map[n_testy * map_width + n_testx] == '#')
						hit_wall = true;
			
				}

			}
			//calculate distance to ceiling and floor
			int ceiling = (float)(n_screen_height / 2.0) - n_screen_height / ((float)f_distance_to_wall);
			int floor = n_screen_height - ceiling;

			for (int y = 0; y < n_screen_height; y++)
			{
				if (y < ceiling)
					screen[y * n_screen_width + x] = ' ';
				else if (y> ceiling && y <= floor)
					screen[y * n_screen_width + x] = '#';
				else
				screen[y * n_screen_width + x] = ' ';
			}
		}
		//set last value in our array with the escape character to know when to stop 
		screen[n_screen_width * n_screen_height - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, n_screen_width * n_screen_height, { 0,0 }, &dwBytesWritten);
	}
	//system("pause");
	return 0;
}