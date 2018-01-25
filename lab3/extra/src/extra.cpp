/*Вариант 2.
//======================
Дан файл INPUT.txt. В нем записаны показания счетчиков электроэнергии граждан.
Необходимо найти ФИО и среднее потребление граждан, у которых среднее значение потребления больше,
 чем у остальных. Ответ выведите в файл OUTPUT.txt

Файл INPUT.txt:
Иванов;Иван;Иванович;60;120;150;170
Сидоров;Сидр;Сидорович;15;18;20;23
Богатырев;Богатырь;Богатырович;110;160;190;210;250
*/

//P.S. скорее всего есть костыли (я с радостью выслушаю варианты кода с отсутствием этих костылей);

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

struct note
{
	char surname[30];
	char name[30];
	char fam[30];
	float av;
};

int main()
{
	ofstream out("OUTPUT.txt");
	ifstream inp("INPUT.txt");

	note* mas= new note[255];

	char* mass = new char[255]; //массив для записи чисел из файла

	int r =0; // счетчик

	while(!inp.eof())
	{
		int* ms = new int[255];
		int* m= new int[255];

		inp.getline(mas[r].surname, 30, ';');

		inp.getline(mas[r].name, 30, ';');

		inp.getline(mas[r].fam, 30, ';');

		inp.getline(mass, 255);

//в этой части производится перевод символов в числа и вычисление среднего значения

		int z=0;
		float q=0;
		int x=0;

		for (int y = 0, i = 0; ; i++, y++)
		{
			if(mass[y]=='\0')
				break;
			if (mass[y] == ';')
			{
				i--;
			}
			else
			{
				ms[i] = atoi(mass + y);

				m[i]= ms[i];
				z++;

				while (ms[i] >= 10)
				{
					y++;
					ms[i] /= 10;
				}
			}
		}

		for(int i=0;i<(z-1);i++)
		{
			x=m[i+1]-m[i];
			q+=x;
		}

		mas[r].av=floor(q/(z-1)*10)/10;

		r++;

		delete[] m;
		delete[] ms;
	}
//==================================================

//Поиск самого большого среднего значения

	for(int i=0; i<r-1; i++)
	{
		for(int i=0; i<r-1; i++)
		{
			if(mas[i].av < mas[i+1].av)
			{
				swap(mas[i], mas[i+1]);
			}
		}
	}
//Запись его в файл
	out << mas->surname << ' ';
	out << mas->name << ' ';
	out << mas->fam<< ' ';
	out << mas->av<< ' ';

	delete[] mas;
	delete[] mass;

	inp.close();
	out.close();
	return 0;
}
