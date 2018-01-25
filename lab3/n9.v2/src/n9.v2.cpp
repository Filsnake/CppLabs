//Вариант 9
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел.  Сформировать на основе данного списка
два дополнительных, содержащих соответственно четные и нечетные элементы исходного списка.
Полученные списки занести в текстовые файлы ODD.TXT и EVEN.TXT.*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	ofstream file("ODD.txt");
	ofstream filetext("EVEN.txt");
	ifstream text("INPUT.txt");

	char* buf = new char[255];
	int* mas = new int[255];

	while (!text.eof())
	{
		text.getline(buf, 255);

		char *str = buf;

		for (int y = 0, i = 0; i < 255; i++, y++)
		{
			if (str[y] == '\0')
				break;
			if (str[y] == ' ')
				continue;
			else
			{
				mas[i] = atoi(str + y);

				if (mas[i] % 2 == 0)
					filetext << mas[i] << " ";
				else
					file << mas[i] << " ";

				while (mas[i] >= 10)
				{
					y++;
					mas[i] /= 10;
				}
				if (mas[i] < 0)
				{
					while (mas[i] != 0)
					{
						y++;
						mas[i] /= 10;
					}
				}

			}

		}

	}
	delete[] mas;
	delete[] buf;

	file.close();
	text.close();
	filetext.close();

	return 0;
}
