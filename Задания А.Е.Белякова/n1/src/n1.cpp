#include <iostream>
using namespace std;

int main()
{
	int x=0;
	cin >> x;

	for(int i=0; i < sizeof(x)*8; i++)
	{
		if(x & 0x80000000)
			cout << '1';
		else
			cout << '0';
		x =x << 1;
	}

	return 0;
}
