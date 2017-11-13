//Вариант 3
/*3. В текстовом файле INPUT.TXT записаны целые числа через пробел, возможно, в несколько строк.
За один просмотр файла сформировать список этих чисел. Проверить наличие в списке заданного числа.
Результат (ЕСТЬ или НЕТ) занести в текстовый файл OUTPUT.TXT.*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ofstream text("OUTPUT.txt");

	int n;
	vector<int> vec;

	ifstream file("INPUT.txt");

	while(file >>n)
		vec.push_back(n);

	int x;
	cout << "Введите число: ";
	cin >> x;

	if(find(vec.begin(), vec.end(), x)!=vec.end())
		text << "ЕСТЬ";
	else
		text<< "НЕТ";

	cout << "Узнать результат можно в OUTPUT.txt :)";

	text.close();
	file.close();

	return 0;
}
