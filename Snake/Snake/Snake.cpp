#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

class Snake
{
public:
	Snake() { fruitX = rand() % width; fruitY = rand() % height; score = 0; }
	bool gameOver=false;
	const int width = 40;
	const int height = 20;
	int x, y, fruitX, fruitY, score;

	void Score(char *name);
};

class Game
{
public:
	Game() { dir = STOP; nTail = 0; }

	int tailX[100], tailY[100];
	int nTail;
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;

	void Setup(Snake &snake,int dif);
	void Draw(Snake &snake);
	void Input();
	void Logic(Snake &snake);
};

int main() 
{
	Snake snake;
	Game CSnake;
	system("mode 100, 30");
	cout << "                ..-@#######*....-####........+##-.    ....@###...     ..@##.... .:###...-###########"
		<< "           ......=##=....-=@. ..:#####-......+##-.     ..=####%...     .@##.....@##*....-##=........"
		<< "              ...##@... ....  ..:##*@##:.. ..+##-.    ..:##:*##+..     .@##...+##%......-##=.    ..."
		<< "            .....@##%.......  ..:##*.%##*....+##-......-##+..%##-.......@##.-###-.     .-##=.    ..."
		<< "            ......+####@:.... ..:##*..=##*...+##-......@#@....###.. ....@##%##*...    ..-#########%."
		<< "            .... ....*#####*. ..:##*...+##=..+##-.. ..+##-....:##=......@##*##@...     .-##@******:."
		<< "                      ...@##%...:##* ...*##=.+##-....:##%******@##*.. ..@##..@##*.......-##=.       "
		<< "               .....  ....###...:##* ....:##%+##-....###%%%%%%%%###-....@##...*##@......-##=.       "
		<< "             ...:+.......+##=...:##* . ...-#####-...%##-........:##@....@##.....###*....-##=.     .."
		<< "             ...:##########:....:##*.......-####-..*##*.... .....+##+...@##. ....*###...-###########";
             
	char *buff= new char[255];
	cout << "                                 ENTER YOUR NAME: ";
	cin.getline(buff, 255);
	char *name = new char[strlen(buff)];
	strcpy(name, buff);
	delete[] buff;

	cout << "CHOOSE DIFFICULTY: " << endl;

	int dif;

	do {
		cout << "1. HARD" << endl;
		cout << "2. NORMAL" << endl;
		cout << "3.NOOB" << endl;
		cout << "Your choise:";

		cin >> dif;

		if(dif < 1 || dif > 3)
			cout << "Wrong!" << endl;

	} while (dif < 1 || dif > 3);

	CSnake.Setup(snake, dif);
	snake.Score(name);

	system("pause");
	return 0;
}
void Game::Setup(Snake &snake, int dif)
{
	snake.x = snake.width / 2;
	snake.y = snake.height / 2;

	while (!snake.gameOver)
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

		Draw(snake);
		Input();
		Logic(snake);
	}
}
void Game::Draw(Snake &snake)
{
	system("cls");
	for (int i = 0; i < snake.width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < snake.height; i++)
	{
		for (int j = 0; j < snake.width; j++)
		{
			if (j == 0)
				cout << "#";

			if (i == snake.y && j == snake.x)
				cout << "O";

			else if (i == snake.fruitY && j == snake.fruitX)
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

			if (j == snake.width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < snake.width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "PAUSE: X" << endl;
	cout << "Score:" << snake.score << endl;
}
void Game::Input()
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
void Game::Logic(Snake &snake)
{
	if (dir != STOP)
	{
		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;

		tailX[0] = snake.x;
		tailY[0] = snake.y;

		for (int i = 1; i < nTail; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
	}
	switch (dir)
	{
	case LEFT:
		snake.x--;
		break;
	case RIGHT:
		snake.x++;
		break;
	case UP:
		snake.y--;
		break;
	case DOWN:
		snake.y++;
	}
	if (snake.x > snake.width || snake.x < 0 || snake.y > snake.height || snake.y < 0)
	{
		system("cls");
		cout << "               GAME OVER        " << endl << endl;
		cout << "               INSERT COIN    " << endl << endl;
		snake.gameOver = true;
	}
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == snake.x && tailY[i] == snake.y)
		{
			system("cls");
			cout << "               GAME OVER        " << endl << endl;
			cout << "               INSERT COIN    " << endl << endl;
			snake.gameOver = true;
		}

	if (snake.x == snake.fruitX && snake.y == snake.fruitY)
	{
		snake.score += 1;
		snake.fruitX = rand() % snake.width;
		snake.fruitY = rand() % snake.height;
		nTail++;
	}
}
void Snake::Score(char *name)
{
	ofstream board("Score_Board.txt", ios::app);
	board << name << ":" << score << endl;
	board.close();
}