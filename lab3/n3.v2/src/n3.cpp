//Вариант 3
/*3. В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел. Проверить наличие в списке заданного числа.
Результат (ЕСТЬ или НЕТ) занести в текстовый файл OUTPUT.TXT.*/
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

	int x;
	cout << "Введите число: ";
	cin >> x;

	bool z=false;
	for(int i=0; i<y; i++)
	{
		if(mas[i] == x)
		{
			z = true;
			break;
		}
	}
	if(z==true)
		text << "ЕСТЬ";
	else
		text << "НЕТ";
	cout << "Узнать результат можно в OUTPUT.txt :)";

	text.close();
	file.close();

	return 0;
}
