#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Введите длинну массива: ";
	cin >> n;

	int* a = new int[n];
	for (int i=0; i<n; i++)
		cin >> a[i];

	int x;
	for (int i=0; i<n; i++)
	{
		for (int i=0; i<n; i++)
		{
			if(a[i] < a[i+1] && a[i] ==0)
			{
				x = a[i];
				a[i] = a[i+1];
				a[i+1] = x;
			}
			if (a[i] < a[i+1] && a[i]<0 && a[i+1] >0)
			{
				x = a[i];
				a[i] = a[i+1];
				a[i+1] = x;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] <<endl;
	}
	delete [] a;
	return 0;
}
