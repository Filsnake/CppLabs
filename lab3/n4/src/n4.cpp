//Вариант 4
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел.
Вставить новый элемент в список перед каждым вхождением заданного с клавиатуры элемента.
Полученный список занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main()
{
	ofstream text("OUTPUT.txt");

	int n,x,y;

	list<int> vec;
	list<int>::iterator it;

	ifstream file("INPUT.txt");

	while(file>> n)
		vec.push_back(n);

	cout << "Элементы в файле INPUT.txt: " << endl;

	for(it = vec.begin(); it != vec.end(); it++)
		cout << *it;

	cout << endl;

	cout << "Элемент списка перед которым вставить новый элемент: " << endl;
	cin >> x;
	cout << "Новый элемент: " << endl;
	cin >> y;

	for(it = vec.begin(); it != vec.end(); it++)
		if (*it == x)
			vec.insert(it,y);

	for(it = vec.begin(); it != vec.end(); it++)
		text << *it << ' ';

	text.close();

	file.close();

	return 0;
}
