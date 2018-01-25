//VAR 9
/*Дана действительная квадратная матрица порядка 2n.
Получить новую матрицу, переставляя ее блоки размера
в порядке, указанном на рисунке.
 []-→[]
 ↑	  |
 |	  ↓
 []←-[] */

#include <iostream>
using namespace std;

int main() {
	int x,y;
	cout << "Количество строк: ";
	cin >> x;
	cout << "Количество столбцов: ";
	cin >> y;
	 int **matrix = new int *[x];

	 for(int i=0; i <x; i++)
		 matrix[i] =new int[y];

	 for(int i=0; i<x; i++)
		 for(int j=0; j<y; j++)
		 {
			 cout << "matrix[" << i+1 << "][" << j+1 << "]" << endl;
			 cin >> matrix[i][j];
		 }
	 cout <<"Было: " << endl;
	 for(int i=0; i<x; i++)
	 {
		 for(int j=0; j<y; j++)
		 {
			 cout << "[" << matrix[i][j] << "]";
			 if(j== y-1)
				 cout << endl;
		 }
	 }
	 cout << endl;
	 int n;
	 for (int i = 0; i < x-1; i++)
	 {
		 for (int j = 0; j < y -1; j++)
		 {
			 n = matrix[i][j + x -1];
			 matrix[i][j + x -1] = matrix[i][j];
			 matrix[i][j] = n;

			 n = matrix[i + x -1][j + x -1];
			 matrix[i + x -1][j + x -1] = matrix[i + x -1][j];
			 matrix[i + x -1][j] = n;

			 n = matrix[i + x -1][j + x -1];
			 matrix[i + x -1][j + x -1] = matrix[i][j];
			 matrix[i][j] = n;
		 }
	}
	 cout <<"Стало: " << endl;
	 for(int i=0; i<x; i++)
	 {
		 for(int j=0; j<y; j++)
		 {
			 cout << "[" << matrix[i][j] << "]";
			 if(j== y-1)
				 cout << endl;
		 }
	 }


	return 0;
}
