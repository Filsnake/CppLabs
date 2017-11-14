//Вариант 6
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел.
Удалить из списка первый отрицательный элемент, если таковой есть.
Полученный список занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream text("OUTPUT.txt");

	ifstream file("INPUT.txt");

	int mas[255];

		int y = 0;
		while(file >> mas[y])
		{
			if(mas[y]== ' ')
				continue;
			y++;
		}

	for(int i=0; i<y; i++)
	{
		if(mas[i]<0)
		{
			for( ;i<y; i++)
			{
				mas[i]=mas[i+1];
			}
			--y;
			break;
		}
	}

	for(int i=0;i <y; i++)
		text << mas[i] << ' ';

	text.close();
	file.close();

	return 0;
}
