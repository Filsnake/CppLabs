//Решетников Д.Ю.
/* Вариант 7
реализовать вторую версию программы, вместо массива использовать односвязный список; элементы добавлять таким образом,
чтобы сохранялась упорядоченность списка по алфавиту (вставка нового элемента после элемента,
который меньше нового элемента и перед большим элементом)*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct note // сама структура
{
	char *surname;
	char *name;
	char *phone_number;
	int date[3];
};

struct list
{
	note a;
	list* next;
};

bool phone(const char *buff) // проверка номера телефона на отсутствие символов
{
	const char *temp = "0123456789";

	for (int i = 0; i<strlen(buff); i++)
	{
		if (!strchr(temp, buff[i]))
			return false;
	}
	return true;
}

void sort(list **begin) //сортировка по алфавиту
{
	char *buff = new char[255]; //выделение памяти в буфер

	cout << endl << "================================================================" << endl << endl;

	list *sort = new list;
	//____________________________Ввод данных_________________________________
	cout << "Введите фамилию: ";
	cin >> buff;
	sort->a.surname = new char[strlen(buff)];
	strcpy(sort->a.surname, buff);

	cout << "Имя: ";
	cin >> buff;
	sort->a.name = new char[strlen(buff)];
	strcpy(sort->a.name, buff);

	cout << "Телефон: ";
	cin >> buff;
	while (!phone(buff)) {
		cout << "[Ошибка] В номере должны быть только цифры !" << endl;
		cout << "Телефон: ";
		cin >> buff;
	}
	sort->a.phone_number = new char[strlen(buff)];
	strcpy(sort->a.phone_number, buff);

	cout << "Дата рождения" << endl;
	cout << "День: ";
	while (!(cin >> sort->a.date[0]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "День: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	cout << "Месяц: ";
	while (!(cin >> sort->a.date[1]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "День: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	cout << "Год: ";
	while (!(cin >> sort->a.date[2]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "День: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	cout << endl << "================================================================" << endl << endl;

	list *p = *begin;

	//____________________________Сортировка_________________________________
	if (p->a.surname[0] >= sort->a.surname[0])
	{
		sort->next = p;
		*begin = sort;
		return;
	}

	list *p1 = p->next;

	while (p1)
	{
		if (p->a.surname[0] < sort->a.surname[0] && sort->a.surname[0] <= p1->a.surname[0])
		{
			p->next = sort;
			sort->next = p1;
			return;
		}
		p = p1;
		p1 = p1->next;
	}
	p->next = sort;
	sort->next = NULL;
	delete[] buff;
}

void search(list **begin)//Поиск по месяцу рождения
{
	list *search = *begin;
	int x;

	cout << endl << "Введите месяц рождения: ";
	cin >> x;

	bool z = false;

	while (search)
	{
		if (search->a.date[1] == x)
		{
			z = true;
			cout << "================================================================" << endl << endl;
			cout << "Фамилия: " << search->a.surname << endl;
			cout << "Имя: " << search->a.name << endl;
			cout << "Телефон: " << search->a.phone_number << endl;
			cout << "Дата рождения" << endl;
			cout << "День: " << search->a.date[0] << endl;
			cout << "Месяц: " << search->a.date[1] << endl;
			cout << "Год: " << search->a.date[2] << endl;
			cout << "================================================================" << endl << endl;
		}
		search = search->next;
	}

	if (z == false)
		cout << endl << "Не найден человек родившийся в этот месяц." << endl << endl;

}

void print(list *begin)//Вывод введенных данных
{
	list *print = begin;

	while (print)
	{
		cout << "Фамилия: " << print->a.surname << endl;

		cout << "Имя: " << print->a.name << endl;

		cout << "Телефон: " << print->a.phone_number << endl;

		cout << "Дата рождения" << endl;
		cout << "День: " << print->a.date[0] << endl;
		cout << "Месяц: " << print->a.date[1] << endl;
		cout << "Год: " << print->a.date[2] << endl;

		cout << endl;

		print = print->next;
	}
}

void free(list **begin)//Удаление элементов
{
	list *free = *begin;
	list *free2;

	while (free)
	{
		free2 = free;
		free = free->next;
		delete free2;
	}

	*begin = NULL;
}

void menu() //Меню №1
{
	int option;
	do
	{
		cout << "================================================" << endl;
		cout << "[1] Начать ввод данных" << endl;
		cout << "[2] Выход" << endl;
		cout << "Введите номер вашего выбора: ";

		while (!(cin >> option))
		{
			cout << "Ошибка. Введите корректный номер: ";
			cin.clear();
			while (cin.get() != '\n');
		}

		if (option <1 || option >2)
			cout << endl << "Ошибка. Введите корректный номер" << endl;

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

int menu_2()//Меню №2
{
	int option;
	do
	{
		cout << "[1] Продолжить ввод данных" << endl;
		cout << "[2] Поиск по месяцу рождения" << endl;
		cout << "[3] Показать всю информацию " << endl;
		cout << "[4] Выход" << endl;
		cout << "Введите номер вашего выбора: ";

		while (!(cin >> option))
		{
			cout << "Ошибка. Введите корректный номер выбора: ";
			cin.clear();
			while (cin.get() != '\n');
		}

		if (option <1 || option >4)
			cout << endl << "Ошибка. Введите корректный номер выбора" << endl << endl;

	} while (option <1 || option > 4);

	return option;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	menu();

	list* begin = NULL;
	begin = new list;

	cout << "================================================================" << endl << endl;

	char *buff = new char[255];
//____________________________________________
	cout << "Введите фамилию: ";
	cin >> buff;
	begin->a.surname = new char[strlen(buff)];
	strcpy(begin->a.surname, buff);
//____________________________________________
	cout << "Имя: ";
	cin >> buff;
	begin->a.name = new char[strlen(buff)];
	strcpy(begin->a.name, buff);
//____________________________________________

	cout << "Телефон: ";
	cin >> buff;
	while (!phone(buff)) {
		cout << "[Ошибка] В номере должны быть только цифры !" << endl;
		cout << "Телефон: ";
		cin >> buff;
	}
	begin->a.phone_number = new char[strlen(buff)];
	strcpy(begin->a.phone_number, buff);
//______________________________________________
	cout << "Дата рождения" << endl;

	cout << "День: ";
	while (!(cin >> begin->a.date[0]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "День: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	cout << "Месяц: ";
	while (!(cin >> begin->a.date[1]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "Месяц: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	cout << "Год: ";
	while (!(cin >> begin->a.date[2]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "Год: ";
		cin.clear();
		while (cin.get() != '\n');
	}

	cout << endl << "================================================================" << endl << endl;

	begin->next = NULL;

	int option = menu_2();
	do
	{
		switch (option)
		{
		case 1:
			sort(&begin);
			option = menu_2();
			break;
		case 2:
			search(&begin);
			option = menu_2();
			break;
		case 3:
			cout << "================================================================" << endl << endl;
			print(begin);
			cout << "================================================================" << endl << endl;
			option = menu_2();
			break;
		}
		if (option == 4)
		{
			cout << "GOOD BYE!" << endl;
			delete[] buff;
			free(&begin);
			exit(0);
		}
	} while (option != 4);

	return 0;
}
