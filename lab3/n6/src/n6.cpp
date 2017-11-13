//Вариант 6
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел.
Удалить из списка первый отрицательный элемент, если таковой есть.
Полученный список занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ofstream text("OUTPUT.txt");

	ifstream file("INPUT.txt");

	int n;
	vector<int> vec;
	vector<int>::iterator it;

	while(file >> n)
		vec.push_back(n);

	for(it = vec.begin(); it != vec.end(); it++)
		if(*it < 0)
		{
			vec.erase(it);
			break;
		}

	for(it = vec.begin(); it != vec.end(); it++)
		text << *it << ' ';

	text.close();
	file.close();

	return 0;
}
