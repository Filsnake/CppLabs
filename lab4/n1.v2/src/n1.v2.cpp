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

struct list
{
	note a;
	list* next;
};

void sort(list **begin)
{
	cout << endl << "================================================================" << endl << endl;

	list *sort = new list;

	cout << "Введите фамилию: ";
	cin >> sort->a.surname;

	cout << "Имя: ";
	cin >> sort->a.name;

	cout << "Телефон: ";
	while(!(cin >> sort->a.phone_number))
	{
		cout << "В номере не должно быть символов!" << endl;
		cout << "Телефон: ";
		cin.clear();
		while(cin.get() != '\n');
	}
	cout << "Дата рождения"<< endl;

	cout << "День: ";
	while(!(cin >> sort -> a.date[0]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "День: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << "Месяц: ";
	while(!(cin >> sort->a.date[1]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "День: ";
		cin.clear();
		while(cin.get() != '\n');
	}
	cout << "Год: ";
	while(!(cin >> sort->a.date[2]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "День: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << endl <<"================================================================" << endl << endl;

	list *p = *begin;

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
}

void search(list **begin)
{
	list *search= *begin;

	int x;

	cout << endl <<"Введите месяц рождения: ";
	cin >> x;

	bool z=false;

	while(search)
	{
		if(search->a.date[1] == x)
		{
			z = true;
			cout << "================================================================" << endl << endl;
			cout <<"Фамилия: " <<search->a.surname << endl;
			cout << "Имя: "<<search->a.name << endl;
			cout << "Телефон: "<< search->a.phone_number << endl;
			cout << "Дата рождения"<< endl;
			cout << "День: " << search -> a.date[0] << endl;
			cout << "Месяц: " << search -> a.date[1] << endl;
			cout << "Год: " << search -> a.date[2] << endl;
			cout << "================================================================" << endl << endl;
		}
		search = search->next;
	}

	if(z==false)
		cout << endl << "Не найден человек родившийся в этот месяц." << endl << endl;

}

void print(list *begin)
{
	list *print = begin;

	while(print)
	{
		cout << "Фамилия: " << print->a.surname << endl;

		cout << "Имя: " << print -> a.name << endl;

		cout << "Телефон: " << print -> a.phone_number << endl;

		cout << "Дата рождения"<< endl;
		cout << "День: " << print -> a.date[0] << endl;
		cout << "Месяц: " << print -> a.date[1] << endl;
		cout << "Год: " << print -> a.date[2] << endl;

		cout << endl;

		print = print->next;
	}
}

void free(list **begin)
{
	list *free = *begin;
	list *free2;

	while(free)
	{
		free2 = free;
		free = free->next;
		delete free2;
	}

	*begin =NULL;
}

void menu()
{
	int option;
		do
		{
			cout <<"--------------------------------------------------" << endl;
			cout << "[1] Начать ввод данных" << endl;
			cout << "[2] Выход" << endl;
			cout << "Введите номер вашего выбора: ";

			while(!(cin >> option))
			{
				cout << "Ошибка. Введите корректный номер: ";
				cin.clear();
				while(cin.get() != '\n');
			}

			if(option <1 || option >2)
				cout << endl << "Ошибка. Введите корректный номер" << endl;

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
	int option;
	do
	{
		cout << "[1] Продолжить ввод данных" << endl;
		cout << "[2] Поиск по месяцу рождения" << endl;
		cout << "[3] Показать всю информацию " << endl;
		cout << "[4] Выход" << endl;
		cout << "Введите номер вашего выбора: ";

		while(!(cin >> option))
		{
			cout << "Ошибка. Введите корректный номер выбора: ";
			cin.clear();
			while (cin.get() != '\n');
		}

		if(option <1 || option >4)
			cout << endl << "Ошибка. Введите корректный номер выбора" << endl << endl;

	}while(option <1 || option > 4);

	return option;
}

int main()
{
	setlocale(LC_ALL, "rus");

	menu();

	list* begin = NULL;
	begin = new list;

	cout << "================================================================" << endl << endl;

	cout << "Введите фамилию: ";
	cin >> begin->a.surname;

	cout << "Имя: ";
	cin >> begin -> a.name;

	cout << "Телефон: ";
	while(!(cin >> begin -> a.phone_number))
	{
		cout << "В номере не должно быть символов!" << endl;
		cout << "Телефон: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << "Дата рождения"<< endl;

	cout << "День: ";
	while(!(cin >> begin -> a.date[0]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "День: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << "Месяц: ";
	while(!(cin >> begin -> a.date[1]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "Месяц: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << "Год: ";
	while(!(cin >> begin -> a.date[2]))
	{
		cout << "В дате должны быть только цифры!" << endl;
		cout << "Год: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	cout << endl<<"================================================================" << endl << endl;

	begin->next = NULL;

	int option=menu_2();

	do
	{
		switch(option)
		{
			case 1:
				sort(&begin);
				option=menu_2();
				break;
			case 2:
				search(&begin);
				option=menu_2();
				break;
			case 3:
				cout << "================================================================" << endl << endl;
				print(begin);
				cout << "================================================================" << endl << endl;
				option=menu_2();
				break;
			case 4:
				cout << "GOOD BYE!" << endl;
				free(&begin);
				exit(0);
				break;
		}
	}while(option !=5);

	return 0;
}
