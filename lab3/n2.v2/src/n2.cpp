//Вариант 2
/* 2. В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел и найти среднее арифметическое элементов списка.
Полученное значение занести в текстовый файл OUTPUT.TXT.*/
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

	 float av=0;

	 for(int i=0; i <y; i++)
		 av+=mas[i];

	 av= av/y;

	 text << av;

	 file.close();

	 text.close();
	return 0;
}
