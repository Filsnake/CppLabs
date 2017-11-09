//Вариант 5
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел.
Вставить новый элемент в список за каждым вхождением заданного с клавиатуры элемента.
Полученный список занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <list>

using namespace std;

int main()
{
	srand(time(NULL));

	ofstream textFile("INPUT.txt");

	for(int i=0; i<2; i++){
		for(int i=0; i<5; i++)
			textFile << rand()% 10<<' ';
		textFile << endl;
	}

	textFile.close();

	ofstream text("OUTPUT.txt");

	int n,x,y;

	list<int> vec;
	list<int>::iterator it,it2;

	ifstream file("INPUT.txt");



	while(file>> n)
		vec.push_back(n);

	cout << "Элементы в файле INPUT.txt: " << endl;

	for(it = vec.begin(); it != vec.end(); it++)
		cout << *it;
	cout << endl;

	cout << "Элемент списка после которого вставить новый элемент: " << endl;
	cin >> x;
	cout << "Новый элемент: " << endl;
	cin >> y;

	it = vec.begin();
	it2 = vec.end();
	while(it != it2)
		if (*it++ == x)
			vec.insert(it,y);

	for(it = vec.begin(); it != vec.end(); it++)
		text << *it << ' ';

	text.close();

	file.close();

	return 0;
}
