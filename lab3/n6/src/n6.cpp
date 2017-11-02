#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	srand(time(NULL));

	ofstream textFile("INPUT.txt");

	for(int i=0; i<2; i++)
	{
		for(int i=0; i<5; i++)
			textFile << rand() % 10 + (-2) << ' ';
		textFile << endl;
	}

	textFile.close();
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
