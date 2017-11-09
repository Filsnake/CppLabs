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
	list<int>::iterator it,it2;
	while (file >> n)
		l.push_back(n);

	it=l.begin();
	it2 = l.end();

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
