#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

bool gameOver;

const int width = 40;
const int height = 20;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

eDirection dir;

void Setup() 
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw() 
{
	system("cls");
	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";

			if (i == y && j == x)
				cout << "O";

			else if (i == fruitY && j == fruitX)
				cout << "*";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << 'o';
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width+2; i++)
		cout << "#";
	cout << endl;
	cout << "PAUSE: X" << endl;
	cout << "Score:" << score << endl;
}
void Input() 
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			dir = STOP;
			break;
		}
	}
}
void Logic() 
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
	{
		system("cls");
			cout << "    .###########+     .#######      +####-     :####* =###############*" << endl;
			cout << "  .%=##%++++++++-   -@@##%+%##%%-   =####%%: *%@####* =####+++++++++++-" << endl;
			cout << "-*%##@%:          :+%##@%: +%@##++- =######=+@######* =####.           " << endl;
			cout << "*####-   -:::---- +####-     :####* =###############* =####:--------.  " << endl;
			cout << "+####-   =######+ +####-.....:####* =###############* =#############.  " << endl;
			cout << "+####-     :####+ +###############* =####- @#= :####* =####.           " << endl;
			cout << " :####+   :####+ +####-     :####* +####-     :####* =####.           " << endl;
			cout << "   .###########+ +####-     *####* +####.     :####* =###############*" << endl;
			cout << endl; 
			cout << "  :###########-   +####-     :####* =###############* =#############.  " << endl;
			cout << "+####-     :####+ +####-     :####* =####.            =####.     :####*" << endl;
			cout << "+####-     :####+ +####-     :####* +####.            =####.     :####*" << endl;
			cout << "+####-     :####+ +####-     :####* +#############-   =####.   =######*" << endl;
			cout << "+####-     :####+ ..:####+ =####:.. +####-.........   =###########....." << endl;
			cout << "+####-     :####+   .**###@###**.   +####.            =####**#####@@.  " << endl;
			cout << ":%%##=+++++=##%%:     .%%###%=      +####+++++++++++- +####. +%@####++-" << endl;
			cout << " -###########-          %#=        +###############* +####.   *######:" << endl;
		gameOver = true;
	}
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
		{
			system("cls");
			cout << "    .###########+     .#######      +####-     :####* =###############*";
			cout << "  .%=##%++++++++-   -@@##%+%##%%-   =####%%: *%@####* =####+++++++++++-";
			cout << "-*%##@%:          :+%##@%: +%@##++- =######=+@######* =####.           ";
			cout << "*####-   -:::---- +####-     :####* =###############* =####:--------.  ";
			cout << "+####-   =######+ +####-.....:####* =###############* =#############.  ";
			cout << "+####-     :####+ +###############* =####- @#= :####* =####.           ";
			cout << " :####+   :####+ +####-     :####* +####-     :####* =####.           ";
			cout << "   .###########+ +####-     *####* +####.     :####* =###############*";
			cout << endl;
			cout << "  :###########-   +####-     :####* =###############* =#############.  ";
			cout << "+####-     :####+ +####-     :####* =####.            =####.     :####*";
			cout << "+####-     :####+ +####-     :####* +####.            =####.     :####*";
			cout << "+####-     :####+ +####-     :####* +#############-   =####.   =######*";
			cout << "+####-     :####+ ..:####+ =####:.. +####-.........   =###########.....";
			cout << "+####-     :####+   .**###@###**.   +####.            =####**#####@@.  ";
			cout << ":%%##=+++++=##%%:     .%%###%=      +####+++++++++++- +####. +%@####++-";
			cout << " -###########-          %#=        +###############* +####.   *######:";
			gameOver = true;
		}

	if (x == fruitX && y == fruitY)
	{
		score += 1;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

void difficulty()
{



}

int main() 
{
	system("mode 100, 30");
	cout << "                ..-@#######*....-####........+##-.    ....@###...     ..@##.... .:###...-###########";
	cout << "           ......=##=....-=@. ..:#####-......+##-.     ..=####%...     .@##.....@##*....-##=........";
	cout << "              ...##@... ....  ..:##*@##:.. ..+##-.    ..:##:*##+..     .@##...+##%......-##=.    ...";
	cout << "            .....@##%.......  ..:##*.%##*....+##-......-##+..%##-.......@##.-###-.     .-##=.    ...";
	cout << "            ......+####@:.... ..:##*..=##*...+##-......@#@....###.. ....@##%##*...    ..-#########%.";
	cout << "            .... ....*#####*. ..:##*...+##=..+##-.. ..+##-....:##=......@##*##@...     .-##@******:.";
	cout << "                      ...@##%...:##* ...*##=.+##-....:##%******@##*.. ..@##..@##*.......-##=.       ";
	cout << "               .....  ....###...:##* ....:##%+##-....###%%%%%%%%###-....@##...*##@......-##=.       ";
	cout << "             ...:+.......+##=...:##* . ...-#####-...%##-........:##@....@##.....###*....-##=.     ..";
	cout << "             ...:##########:....:##*.......-####-..*##*.... .....+##+...@##. ....*###...-###########";
             
	char *buff= new char[255];
	cout << "                                 ENTER YOUR NAME: ";
	cin.getline(buff, 255);
	char *name = new char[strlen(buff)];
	strcpy(name, buff);
	delete[] buff;

	cout << "CHOOSE DIFFICULTY: " << endl;

	int dif = 0;

	do {
		cout << "1. HARD" << endl;
		cout << "2. NORMAL" << endl;
		cout << "3.NOOB" << endl;
		cout << "Your choise:";

		cin >> dif;

		if(dif < 1 || dif > 3)
			cout << "Wrong!" << endl;

	} while (dif < 1 || dif > 3);

	Setup();
	while (!gameOver)
	{
		switch (dif)
		{
		case 1:
			Sleep(0);
			break;
		case 2:
			Sleep(40);
			break;
		case 3:

			Sleep(80);
			break;
		}
		
		Draw();
		Input();
		Logic();
	}

	ofstream board("Score_Board.txt", ios::app);

	board << name << ":" << score << endl;
	board.close();
	return 0;
}