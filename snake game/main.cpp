# include <iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<math.h>


using namespace std;
bool gameover = false;
int x, y;
int frx, fry;
const int width = 100, height = 30;
int score = 0;
int len = 0;;
enum dir { STOP = 0, UP, DOWN, RIGHT, LEFT };
dir di;
int tailx[100];
int taily[100];

int speed = 100;

void setting_values()
{

	gameover = false;
	frx = rand() % width;
	fry = rand() % height;
	x = width / 2;
	y = height / 2;
	tailx[0] = x;
	taily[0] = y;
}
void layout()
{
	system("CLS");
	for (int i = 0; i <= width; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{


			if (j == 0 || j == width)
			{
				cout << "#";
			}
			else if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == fry && j == frx)
			{
				cout << "f";
			}
			else
			{
				bool u = true;
				for (int h = 1; h <= len; h++)
				{
					if (i == taily[h] && j == tailx[h])
					{
						  
						   
							   cout << 'o';
					

						u = false;
					}
				}
				if(u==true)
				cout << " ";
			}

		}
		cout << endl;

	}
	for (int i = 0; i <= width; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "YOUR SCORE= " << score;

}
void funct()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case '6':
			di = RIGHT;
			break;
		case'4':
			di = LEFT;
			break;
		case '8':
			di = UP;
			break;
		case '2':
			di = DOWN;
			break;
		default:
			break;


		}
	}
}
void logic()
{
	int prevx = tailx[0];
	int prevy = taily[0];
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i <= len; i++)
	{
		int x1 = tailx[i];
		int y1=taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = x1;
		prevy = y1;

	}
	switch (di)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	case LEFT:
		x--;
		break;
	default:
		break;
	}
	
	for (int i = 1; i <= len; i++)
	{
		if (tailx[i] == x && taily[i] == y)
		{
			cout << "gameover";
			gameover = true;
		}
	}
	if (x > width || x < 0 || y > height || y < 0)
	{
		cout << "gameover";
		gameover = true;
	}
	else if (x == frx && y == fry)
	{
		score = score + 10;
		speed = speed - 5;
		len++;
		frx = rand() % width;
		fry = rand() % height;
	}
}
int main()
{
	setting_values();

	while (!gameover)
	{
		//system("CLS");
		layout();
		funct();
		logic();
		Sleep( speed );

	}




}