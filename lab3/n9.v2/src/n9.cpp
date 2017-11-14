//Вариант 9
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел.  Сформировать на основе данного списка
два дополнительных, содержащих соответственно четные и нечетные элементы исходного списка.
Полученные списки занести в текстовые файлы ODD.TXT и EVEN.TXT.*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream filetext("EVEN.txt");

	ofstream text("ODD.txt");

	ifstream file("INPUT.txt");

	int mas[255];

	int y = 0;
	while(file >> mas[y])
	{
		if(mas[y]== ' ')
			continue;
		y++;
	}

	for(int i=0; i <y; i++)
	{
		if(mas[i]%2 ==0)
			filetext << mas[i];
		else
			text << mas[i];
	}

	file.close();
	text.close();
	filetext.close();
}
