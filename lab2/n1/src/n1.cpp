//VAR 9
/*Задан массив действительных чисел. Если в данной последовательности
ни одно четное число не расположено после нечетного, то получить все
отрицательные члены последовательности. Иначе – все положительные.
Порядок следования чисел в обоих случаях заменяется на обратный.*/
#include <iostream>

using namespace std;

int main()
{
int n;

cout << "Размер массива: " << endl;
cin >> n;

int *a=new int[n];

cout << "Введите значение массива: " << endl;
for (int i=0; i<n; i++)
	cin>> a[i];

for(int i=0; i<n; i++)
{
	if(a[i]%2 == 1 && a[i+1] % 2 == 0)
	{
		for(int i= n -1; i>=0; i--)
		{
			if (a[i] > 0)
				cout << a[i] << endl;
		} break;
	}
	else
	{
		for(int i = n -1; i >=0; i--)
		{
			if (a[i] < 0)
				cout << a[i] << endl;
		} break;
	}
}
	delete [] a;
	return 0;
}
