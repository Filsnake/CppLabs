//VAR 9
/*Задан массив действительных чисел. Переставить члены последовательности так,
чтобы сначала расположились все ее неотрицательные члены, а потом – все отрицательные.
 Порядок следования, как среди неотрицательных членов, так и среди отрицательных должен быть сохранен прежним.*/
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout <<"Ent num: ";
	cin >> n;

	int *a= new int[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	int x;
	for(int i=0; i<n; i++){
		for(int i=0; i<n; i++)
		{
			if(a[i - 1] < a[i] && a[i] == 0)
			{
				x= a[i-1];
				a[i-1] = a[i];
				a[i] = x;
			}
			if(a[i-1] < a[i] && a[i-1] <0 && a[i] > 0)
			{
				x=a[i-1];
				a[i-1] = a[i];
				a[i] = x;
			}
		}
	}
	for (int i=0; i<n; i++)
	 cout << a[i] << endl;

	delete [] a;
	return 0;
}
