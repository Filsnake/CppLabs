//Решетников Д.Ю.
/* Вариант 7
Описать структуру с именем note, содержащую следующие поля:
фамилия, имя;
номер телефона;
дата рождения (массив из трех чисел).
Написать программу, выполняющую следующие действия:
ввод с клавиатуры данных в массив, состоящий из максимум 8 элементов типа note,
причем сделать возможность прервать ввод, чтобы можно было не вводить все 8 элементов;
после окончания ввода отсортировать элементы массива по алфавиту;
вывод в консоль информации о людях, чьи дни рождения приходятся на месяц, значение которого введено с клавиатуры;
если таких нет, вывести соответствующее сообщение */

#include <iostream>
#include <cstdlib>

using namespace std;

struct note
{
	char surname[30];
	char name[30];
	long int phone_number;
	int date[3];
};

void menu()
{
	int option;

	do
	{
		cout << "[1]Начать ввод" << endl;
		cout << "[2]Выход" << endl;
		cout << "Введите номер вашего выбора: ";

		while(!(cin >> option))
		{
			cout << "[Ошибка] Введите корректный номер: ";
			cin.clear();
			while(cin.get() != '\n');
		}
		if(option <1 || option >2)
			cout << endl << "[Ошибка] Введите корректный номер" << endl;
	}while(option <1 || option > 2);

	do
	{
		switch(option)
		{
			case 1:
				return;
				break;
			case 2:
				cout << "GOOD BYE!" << endl;
				exit(0);
				break;
		}
	}while(option !=2);
}

int menu_2()
{
	int opt;
	do
	{
		cout << "[1]Продолжить ввод" << endl;
		cout << "[2]Добавить строки" << endl;
		cout << "[3]Поиск по месяцу" << endl;
		cout << "[4]Вывод введенных данных" << endl;
		cout << "[5]Выход" << endl;
		cout << "Введите номер вашего выбора: ";

		while(!(cin >> opt))
		{
			cout << "[Ошибка] Введите корректный номер: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}while (opt <1 || opt >5);

	cout << endl;
	return opt;
}

int menu_3(int *op2)
{
	do
	{
		cout << "[1]Добавить строки" << endl;
		cout << "[2]Поиск по месяцу" << endl;
		cout << "[3]Вывод введенных данных" << endl;
		cout << "[4]Выход" << endl;
		cout << "Введите номер вашего выбора: ";

		while(!(cin >> *op2))
		{
			cout << "[Ошибка] Введите корректный номер: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}while (*op2 <1 || *op2 >4);
	cout << endl;
	return *op2;
}

void ins(int *N,note *mas, int *count)
{
	cout << endl;
	cout << "Введите фамилию: ";
	cin >> mas[*count].surname;

	cout << "Имя: ";
	cin >>mas[*count].name;

	cout << "Телефон: ";
	while(!(cin >> mas[*count].phone_number))
	{
		cout << "[В номере не должно быть символов!]" << endl;
		cout << "Телефон: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << "Дата рождения"<< endl;

	cout << "День: ";
	while(!(cin >> mas[*count].date[0]))
	{
		cout << "[В дате должны быть только цифры!]" << endl;
		cout << "День: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << "Месяц: ";
	while(!(cin >> mas[*count].date[1]))
	{
		cout << "[В дате должны быть только цифры!]" << endl;
		cout << "Месяц: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << "Год: ";
	while(!(cin >> mas[*count].date[2]))
	{
		cout << "[В дате должны быть только цифры!]" << endl;
		cout << "Год: ";
		cin.clear();
		while(cin.get() != '\n');
	}
	cout << endl;

	cout << "Осталось строк: " << '[' << *N-*count-1 << ']' << endl;

	cout << endl;
	cin.ignore();

}

void sort(int *N, note *mas)
{
	for(int j=0; j<*N-1; j++)
			{
			for(int i=0; i<*N-1; i++)
				{
					if(mas[i].surname[0] > mas[i+1].surname[0])
						swap(mas[i], mas[i+1]);
				}
			}
		cout << "==================================" << endl;
}

void print(int *N, note *mas)
{
	for(int i=0; i<*N; i++)
		{
			cout << endl;
			cout <<"Фамилия: " <<mas[i].surname << endl;
			cout << "Имя: "<<mas[i].name << endl;
			cout << "Телефон: "<< mas[i].phone_number << endl;
			cout << "Дата рождения"<< endl;
			cout << "День: " << mas[i].date[0] << endl;
			cout << "Месяц: " << mas[i].date[1] << endl;
			cout << "Год: " << mas[i].date[2] << endl;
		}
cout << endl <<"==================================" << endl << endl;
}

void search(int *N, note *mas)
{
	int x;
	cout << endl <<"Введите месяц рождения: ";
	cin >> x;

	cout << endl <<"==================================" << endl << endl;

	bool z=false;

	for(int i=0; i<*N; i++)
	{
		if(mas[i].date[1] == x)
		{
			z = true;
			cout <<"Фамилия: " <<mas[i].surname << endl;
			cout << "Имя: "<<mas[i].name << endl;
			cout << "Телефон: "<< mas[i].phone_number << endl;
			cout << "Дата рождения"<< endl;
			cout << "День: " << mas[i].date[0] << endl;
			cout << "Месяц: " << mas[i].date[1] << endl;
			cout << "Год: " << mas[i].date[2] << endl;
		}
		cout << endl;
	}
	if(z==false)
		cout << "[Not found]" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	menu();

	int N;
	cout << endl <<"Введите колличество строк: ";
	while(!(cin >> N))
	{
		cout <<"[Ошибка] Введите число: ";
		cin.clear();
		while(cin.get() !='\n');
	}

	note *mas = new note[N];

	int count =0;
	cout << "==================================" << endl;

	ins(&N,mas, &count);
	int opt=menu_2();
	count++;

	do
	{
		switch(opt)
		{
			case 1:
				ins(&N,mas, &count);
				count++;
				if(count == N)
				{
					cout << "Строчки закончилсь! Выберите действие в меню" << endl;
					int op2=menu_3(&op2);
					do
					{
						switch(op2)
						{
							case 2:
								search(&count, mas);
								cout << endl <<"==================================" << endl << endl;
								opt=menu_3(&op2);
								break;
							case 3:
								sort(&count, mas);
								print(&count, mas);
								opt=menu_3(&op2);
								break;
						}

						if (op2 == 1)
						{
							int x;
							cout << "Введите колличество строк: ";
							while(!(cin >> x))
							{
								cout <<"[Ошибка] Введите число: ";
								cin.clear();
								while(cin.get() !='\n');
							}
							cout << endl;
							N+=x;
							cout << "Строк теперь: " << '[' << N-count << ']' << endl;
							break;
						}

						if(op2 == 4)
						{
							cout << "GOOD BYE!" << endl;
							delete[] mas;
							break;
						}
					}while(op2 !=1 || op2 > 4);
				}
				opt=menu_2();
				break;
			case 2:
				int x;
				cout << "Введите колличество строк: ";
				while(!(cin >> x))
				{
					cout <<"[Ошибка] Введите число: ";
					cin.clear();
					while(cin.get() !='\n');
				}

				cout << endl;
				N+=x;
				cout << "Строк теперь: " << '[' << N-count << ']' << endl << endl;
				opt=menu_2();
				break;
			case 3:
				search(&count, mas);
				opt=menu_2();
				break;
			case 4:
				sort(&count, mas);
				print(&count, mas);
				opt=menu_2();
				break;
		}
		if(count == N)
		{
			cout << "Строчки закончилсь! Выберите действие в меню" << endl;
			int op2=menu_3(&op2);
			do
			{
				switch(op2)
				{
					case 2:
						search(&count, mas);
						cout << endl <<"==================================" << endl << endl;
						opt=menu_3(&op2);
						break;
					case 3:
						sort(&count, mas);
						print(&count, mas);
						opt=menu_3(&op2);
						break;
				}
				if (op2 == 1)
				{
					int x;
					cout << "Введите колличество строк: ";
					while(!(cin >> x))
					{
						cout <<"[Ошибка] Введите число: ";
						cin.clear();
						while(cin.get() !='\n');
					}
					cout << endl;
					N+=x;
					cout << "Строк теперь: " << '[' << N-count << ']' << endl;
					opt=menu_2();
					break;
				}
				if(op2 == 4)
				{
					cout << "GOOD BYE!" << endl;
					delete[] mas;
					break;
				}
			}while(op2 !=1 || op2 > 4);
		}
		if(opt == 5)
		{
			cout << "GOOD BYE!" << endl;
			delete[] mas;
			break;
		}
	}while(opt != 5);

	return 0;
}
