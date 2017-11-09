//Вариант 9
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел.  Сформировать на основе данного списка
 два дополнительных, содержащих соответственно четные и нечетные элементы исходного списка.
 Полученные списки занести в текстовые файлы ODD.TXT и EVEN.TXT.*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <list>
using namespace std;

int main()
{
	srand(time(NULL));
	ofstream textFile("INPUT.txt");

	for(int i=0; i<2; i++)
	{
		for(int i=0; i <5; i++)
			textFile << rand() % 9 << ' ';
		textFile << endl;
	}
	textFile.close();

	ofstream filetext("EVEN.txt");

	ofstream text("ODD.txt");

	ifstream file("INPUT.txt");
	int n;
	list<int> l;
	list<int>::iterator it;

	while (file >> n)
		l.push_back(n);

	for(it = l.begin(); it != l.end(); it++)
	{
		if(*it %2 ==0)
			filetext << *it << ' ';
		if(*it % 2 !=0)
			text << *it << ' ';
	}

	text.close();
	file.close();
	filetext.close();
	return 0;
}
