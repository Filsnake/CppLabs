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
