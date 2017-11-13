//Вариант 1
/*В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла, без использования сортировки сформировать список этих чисел, упорядоченный по неубыванию
(каждый следующий элемент списка больше или равен предыдущему). Значения полученного списка занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
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
