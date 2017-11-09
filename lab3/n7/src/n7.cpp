//Вариант 7
/*7. Дан текстовый файл INPUT.TXT. Проверить в тексте файла правильности расстановки открывающих и закрывающих скобок
 * ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘, ‘]’.Использовать стек. Результат (ПРАВИЛЬНО или НЕПРАВИЛЬНО) записать в файл OUTPUT.TXT. */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>

using namespace std;

int main()
{

	ofstream textFile("OUTPUT.txt");

	ifstream text("INPUT.txt");
	char n;
	stack<char> st;

	while(text >> n){
		st.push(n);
	}
	int res=0;
	int j=0;
	while(!st.empty())
	{
		if(st.top() == '(')
		{
			res++;
			j++;
		}
		if(st.top() == ')')
		{
			res--;
			j++;
		}
		if(st.top() == '[')
		{
			res+=2;
			j++;
		}
		if(st.top() == ']')
		{
			res-=2;
			j++;
		}
		if(st.top() == '{')
		{
			res+=3;
			j++;
		}
		if(st.top() == '}')
		{
			res-=3;
			j++;
		}
		st.pop();
	}

	if(j==0)
		textFile <<"СКОБОК В ФАЙЛЕ НЕТ";
	else
	{
	if(res != 0)
		textFile << "НЕПРАВИЛЬНО";
	else
		textFile << "ПРАВИЛЬНО";
	}

	text.close();
	textFile.close();
	return 0;
}
