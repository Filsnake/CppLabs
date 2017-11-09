//Вариант 1
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла, без использования сортировки сформировать список этих чисел, упорядоченный по неубыванию
 (каждый следующий элемент списка больше или равен предыдущему). Значения полученного списка занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));

	ofstream textFile("INPUT.txt");

	for(int i=0; i< 2; i++)
	{
		for(int i=0; i<5; i++)
				textFile << rand() % 9 << ' ';
		textFile << endl;
	}
	textFile.close();

	ofstream text("OUTPUT.txt");

	int n;
	multiset<int> s;

	ifstream file("INPUT.txt");

	while(file>>n)
		s.insert(n);

	for(multiset<int>::iterator x=s.begin(); x!=s.end(); x++)
		text << *x <<' ';

	file.close();

	text.close();

	     return 0;
	}
