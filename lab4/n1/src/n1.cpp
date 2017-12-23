//Решетников Д.Ю.
/* Вариант 7(небольшая предыстория, 4 лабораторную я начал делать раньше остальных,но в ней не оказалось 9 варианта, но по новому вашему списку я был 7
именно по этому я его и сделал)
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
#include <cstring>

using namespace std;

struct note //Структура
{
	char *surname;
	char *name;
	char *phone_number;
	int date[3];
};

void menu() //Меню №1
{
	int option;
	do
	{
		cout << "[1]Начать ввод" << endl;
		cout << "[2]Выход" << endl;
		cout << "Введите номер вашего выбора: ";

		while (!(cin >> option))
		{
			cout << "[Ошибка] Введите корректный номер: ";
			cin.clear();
			while (cin.get() != '\n');
		}
		if (option <1 || option >2)
			cout << endl << "[Ошибка] Введите корректный номер" << endl;
	} while (option <1 || option > 2);

	do
	{
		switch (option)
		{
		case 1:
			return;
			break;
		case 2:
			cout << "GOOD BYE!" << endl;
			exit(0);
			break;
		}
	} while (option != 2);
}

int menu_2() //Меню №2
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

		while (!(cin >> opt))
		{
			cout << "[Ошибка] Введите корректный номер: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	} while (opt <1 || opt >5);

	cout << endl;
	return opt;
}

int menu_3(int *op2) //Меню №3
{
	do
	{
		cout << "[1]Добавить строки" << endl;
		cout << "[2]Поиск по месяцу" << endl;
		cout << "[3]Вывод введенных данных" << endl;
		cout << "[4]Выход" << endl;
		cout << "Введите номер вашего выбора: ";

		while (!(cin >> *op2))
		{
			cout << "[Ошибка] Введите корректный номер: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	} while (*op2 <1 || *op2 >4);
	cout << endl;
	return *op2;
}

bool phone(const char *X) //Проверка номера телефона на наличие посторонних символов
{
	const char *temp = "0123456789";

	for (int i = 0; i<strlen(X); i++)
	{
		if (!strchr(temp, X[i]))
			return false;
	}
	return true;
}

void ins(int *N, note *mas, int *count) //Вставка элементов
{
	char *buff = new char[255];

	cout << endl;
//_________________________________________________
	cout << "Введите фамилию: ";
	cin >> buff;
	mas[*count].surname = new char[strlen(buff)];
	for (int i = 0; i <= strlen(buff); i++)
		mas[*count].surname[i] = buff[i];
//_________________________________________________
	cout << "Имя: ";
	cin >> buff;
	mas[*count].name = new char[strlen(buff)];
	for (int i = 0; i <= strlen(buff); i++)
		mas[*count].name[i] = buff[i];
//_________________________________________________
	char *X = new char[255];

	cout << "Телефон: ";
	cin >> X;
	while (!phone(X)) {
		cout << "[Ошибка] В номере должны быть только цифры !" << endl;
		cout << "Телефон: ";
		cin >> X;
	}
	mas[*count].phone_number = X;
//__________________________________________________
	cout << "Дата рождения" << endl;
	cout << "День: ";
	while (!(cin >> mas[*count].date[0]))
	{
		cout << "[В дате должны быть только цифры!]" << endl;
		cout << "День: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	cout << "Месяц: ";
	while (!(cin >> mas[*count].date[1]))
	{
		cout << "[В дате должны быть только цифры!]" << endl;
		cout << "Месяц: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	cout << "Год: ";
	while (!(cin >> mas[*count].date[2]))
	{
		cout << "[В дате должны быть только цифры!]" << endl;
		cout << "Год: ";
		cin.clear();
		while (cin.get() != '\n');
	}
	cout << endl;
//_______________________________________________________________________
	cout << "Осталось строк: " << '[' << *N - *count - 1 << ']' << endl;

	delete[] buff;
	cout << endl;
	cin.ignore();
}

void sort(int *N, note *mas) //Сортировка
{
	for (int j = 0; j<*N - 1; j++)
	{
		for (int i = 0; i<*N - 1; i++)
		{
			if (mas[i].surname[0] > mas[i + 1].surname[0])
				swap(mas[i], mas[i + 1]);
		}
	}
	cout << "==================================" << endl;
}

void print(int *N, note *mas) //Вывод элементов
{
	for (int i = 0; i<*N; i++)
	{
		cout << endl;
		cout << "Фамилия: " << mas[i].surname << endl;
		cout << "Имя: " << mas[i].name << endl;
		cout << "Телефон: " << mas[i].phone_number << endl;
		cout << "Дата рождения" << endl;
		cout << "День: " << mas[i].date[0] << endl;
		cout << "Месяц: " << mas[i].date[1] << endl;
		cout << "Год: " << mas[i].date[2] << endl;
	}
	cout << endl << "==================================" << endl << endl;
}

void search(int *N, note *mas) //Поиск по месяцу рождения
{
	int x;
	cout << endl << "Введите месяц рождения: ";
	cin >> x;

	cout << endl << "==================================" << endl << endl;

	bool z = false;

	for (int i = 0; i<*N; i++)
	{
		if (mas[i].date[1] == x)
		{
			z = true;
			cout << "Фамилия: " << mas[i].surname << endl;
			cout << "Имя: " << mas[i].name << endl;
			cout << "Телефон: " << mas[i].phone_number << endl;
			cout << "Дата рождения" << endl;
			cout << "День: " << mas[i].date[0] << endl;
			cout << "Месяц: " << mas[i].date[1] << endl;
			cout << "Год: " << mas[i].date[2] << endl;
		}
		cout << endl;
	}
	if (z == false)
		cout << "[Not found]" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	menu();

	int N;
	cout << endl << "Введите колличество строк: ";
	while (!(cin >> N))
	{
		cout << "[Ошибка] Введите число: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	note *mas = new note[N];

	int count = 0; //Счетчик введенных элементов
	cout << "==================================" << endl;

	ins(&N, mas, &count);
	count++;

	int opt = menu_2();
	do
	{
		switch (opt)
		{
		case 1:
			ins(&N, mas, &count);
			count++;
			if (count == N)
			{
				cout << "Строчки закончилсь! Выберите действие в меню +" << endl;
				int op2 = menu_3(&op2);
				do
				{
					switch (op2)
					{
						if (op2 == 1)
						{
							int x;
							cout << "Введите колличество строк: ";
							while (!(cin >> x))
							{
								cout << "[Ошибка] Введите число: ";
								cin.clear();
								while (cin.get() != '\n');
							}
							cout << endl;
							N += x;
							cout << "Строк теперь: " << '[' << N - count << ']' << endl;
							break;
						}
					case 2:
						search(&count, mas);
						cout << endl << "==================================" << endl << endl;
						opt = menu_3(&op2);
						break;
					case 3:
						sort(&count, mas);
						print(&count, mas);
						opt = menu_3(&op2);
						break;
					}
					if (op2 == 4)
					{
						cout << "GOOD BYE!" << endl;
						delete[] mas;
						exit(0);
						break;
					}
				} while (op2 != 1 || op2 != 4);
			}
			opt = menu_2();
			break;
		case 2:
			int x;
			cout << "Введите колличество строк: ";
			while (!(cin >> x))
			{
				cout << "[Ошибка] Введите число: ";
				cin.clear();
				while (cin.get() != '\n');
			}

			cout << endl;
			N += x;
			cout << "Строк теперь: " << '[' << N - count << ']' << endl << endl;
			opt = menu_2();
			break;
		case 3:
			search(&count, mas);
			opt = menu_2();
			break;
		case 4:
			sort(&count, mas);
			print(&count, mas);
			opt = menu_2();
			break;
		}
		if (count == N)//Если строчки закончились
		{
			cout << "Строчки закончилсь! Выберите действие в меню -" << endl;
			int op2 = menu_3(&op2);
			do
			{
				switch (op2)
				{
				case 2:
					search(&count, mas);
					cout << endl << "==================================" << endl << endl;
					opt = menu_3(&op2);
					break;
				case 3:
					sort(&count, mas);
					print(&count, mas);
					opt = menu_3(&op2);
					break;
				}
				if (op2 == 1)
				{
					int x;
					cout << "Введите колличество строк: ";
					while (!(cin >> x))
					{
						cout << "[Ошибка] Введите число: ";
						cin.clear();
						while (cin.get() != '\n');
					}
					cout << endl;
					N += x;
					cout << "Строк теперь: " << '[' << N - count << ']' << endl;
					opt = menu_2();
					break;
				}
				if (op2 == 4)
				{
					cout << "GOOD BYE!" << endl;
					delete[] mas;
					exit(0);
					break;
				}
			} while (op2 != 1 || op2 != 4);
		}
		if (opt == 5)
		{
			cout << "GOOD BYE!" << endl;
			delete[] mas;
			exit(0);
			break;
		}
	} while (opt != 5);

	return 0;
}
