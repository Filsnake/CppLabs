#include <iostream>

using namespace std;

struct note
{
	char surname[30];
	char name[30];
	long int phone_number;
	int date[3];
};

int main()
{
	int N;
	cout << "кол-во строк: ";
	cin >> N;
	note *mas = new note[N];

	cout << "==================================";
//Ввод данных
	for(int i=0; i< N; i++)
	{
		cout << endl;
		cout << "Введите фамилию: ";
		cin >> mas[i].surname;

		cout << "Имя: ";
		cin >>mas[i].name;

		cout << "Телефон: ";
		cin >> mas[i].phone_number;

		cout << "Дата рождения"<< endl;
		cout << "День: ";
		cin >> mas[i].date[0];
		cout << "Месяц: ";
		cin >> mas[i].date[1];
		cout << "Год: ";
		cin >> mas[i].date[2];

		cin.ignore();
//Выход из цикла
		if(i!= N-1)
		{
			cout << "Чтобы прекратить ввод введите 'n', иначе, любой символ: ";

			char x = cin.get();

			if(x == 'n')
			{
				N=i+1;
				break;
			}
		}
	}

//Сортировка по алфавиту
	for(int j=0; j<N-1; j++)
		{

		for(int i=0; i<N-1; i++)
			{
				if(mas[i].surname[0] > mas[i+1].surname[0])
					swap(mas[i], mas[i+1]);
			}
		}
	cout << "==================================";
//Вывод отсортированных данных
	for(int i=0; i<N; i++)
		{
			cout << endl;
			cout <<"Фамилия: " <<mas[i].surname << endl;
			cout << "Имя: "<<mas[i].name << endl;
			cout << "Телефон: "<< mas[i].phone_number << endl;
			cout <<"Дата рождения: " << mas[i].date[0] << '.' << mas[i].date[1] << '.' << mas[i].date[2] << endl;
		}
	cout << "==================================";
//Поиск по месяцу
	int x;
	cout << endl <<"Введите месяц рождения: ";
	cin >> x;

	bool z=false;

	for(int i=0; i<N; i++)
	{
		if(mas[i].date[1] == x)
		{
			z = true;
			cout << endl;
			cout <<"Фамилия: " <<mas[i].surname << endl;
			cout << "Имя: "<<mas[i].name << endl;
			cout << "Телефон: "<< mas[i].phone_number << endl;
			cout <<"Дата рождения: " << mas[i].date[0] << '.' << mas[i].date[1] << '.' << mas[i].date[2] << endl;
		}
	}
	if(z==false)
		cout << "Not found";

	delete[] mas;
	return 0;
}
