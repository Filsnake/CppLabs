#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	srand(time(NULL));

	ofstream textFile("INPUT.txt");

	for(int i=0; i<2; i++)
	{
		for(int i=0; i<5; i++)
			textFile << rand() % 9 << ' ';
		textFile << endl;
	}
	textFile.close();

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
