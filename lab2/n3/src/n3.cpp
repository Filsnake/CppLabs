//VAR 9
/*В целочисленном массиве упорядочить по убыванию элементы,
стоящие между первым максимальным и последним минимальным элементами*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout <<"Введите размер массива: ";
	cin >> n;

	int *a = new int[n];
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
	}

    int max=a[0],
    	min=a[0],
		masmax=0,
		masmin=0;

    for(int i=1;i<n;i++)
    {
        if(max < a[i])
        {
        	masmax=i;
            max=a[i];
        }
        if(min >= a[i])
        {
        	masmin=i;
            min=a[i];
        }
    }
    int x;
    for(int i=masmax+1; i <masmin; i++)
    {
        for(int j=masmin-1; j>i; j--)
        {
            if(a[j]>a[j-1])
            {
            	x=a[j];
               a[j]=a[j-1];
                a[j-1]=x;
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
    delete [] a;
	return 0;
}
