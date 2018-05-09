#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

class Student
{
public:
	char *surname;
	char *name;
	char *patronymic;
	char *phone_number;
	int date[3];

	/*~Student()
	{ 
		delete[] surname;
		delete[] name;
		delete[] patronymic;
		delete[] phone_number;
	};*/
};

class List 
{
private:
	struct ListElem
	{
		Student a;
		ListElem *next;
	};
	ListElem *Begin = NULL;
public:
	void Add(const Student &a);
	friend Student Search(int option, char* search);
	void Sort(int option);	
	void Free();
	void Delete(char* surname, char* name, char* patronymic);
	bool Empty();
	friend ostream& operator << (ostream &a, const List &b);
	friend ostream& operator << (ostream &a,const List::ListElem *b);
	friend istream& operator >>(istream &a, List::ListElem *b);
	~List() { Free(); };
};

char *Read();

bool choise();

void Emp(bool x);

void List::Add(const Student &a)
{
	ListElem *Add = new ListElem;

	Add->next = Begin;

	Add->a.name = a.name;
	Add->a.surname = a.surname;
	Add->a.patronymic = a.patronymic;
	Add->a.phone_number = a.phone_number;
	Add->a.date[0] = a.date[0];
	Add->a.date[1] = a.date[1];
	Add->a.date[2] = a.date[2];

	Begin = Add;
}

Student Search(int option, char* search)  /*, int& count*/
{
	bool isError = false;
	List::ListElem *Search = NULL;

	bool z = false;

	if (option >= 1 && option != 5)
	{
		char *x;

		//char *search = Read();

		while (Search)
		{
			if (option == 1) x = Search->a.name;
			if (option == 2) x = Search->a.surname;
			if (option == 3) x = Search->a.patronymic;
			if (option == 4) x = Search->a.phone_number;

			if (strlen(x) == strlen(search))
			{
				for (int i = 0; i < strlen(search); i++)
				{
					if (x[i] != search[i])
					{
						z = false;
						break;
					}
					else z = true;
				}
				if (z == true)
				{
					return Search->a;
				}
			}
			Search = Search->next;
		}
		//count = 0;
		//return Student[count];
	}

	if (option == 5)
	{
		// из search вытаскиваем дату (как хотим, это строка просто)
		/*count = 0;
		return Student[0];*/
	}
}

void List::Sort(int option) 
{
	int x,y,z;
	ListElem *New = NULL;
	while (Begin != NULL)
	{
		ListElem *Sort = Begin;

		if (option == 1) x = Sort->a.date[0];
		if (option == 2) x = Sort->a.date[1];
		if (option == 3) x = Sort->a.date[2];

		if (New != NULL)
		{
			if (option == 1) y = New->a.date[0];
			if (option == 2) y = New->a.date[1];
			if (option == 3) y = New->a.date[2];
		}

		Begin = Begin->next;
		if (New == NULL || x < y)
		{
			Sort->next = New;
			New = Sort;
		}
		else
		{
			ListElem *Current = New;

			if (Current->next != NULL)
			{
				if (option == 1) z = Current->next->a.date[0];
				if (option == 2) z = Current->next->a.date[1];
				if (option == 3) z = Current->next->a.date[2];
			}

			while (Current->next != NULL && !(x < z))
			{
				Current = Current->next;
			}
			Sort->next = Current->next;
			Current->next = Sort;
		}
	}
	Begin = New;
}

void List::Free() 
{
	while (Begin != NULL)
	{
		ListElem *Free = Begin->next;
		delete Begin;
		Begin = Free;
	}
}

void List::Delete(char* name, char* surname, char* patronymic)
{
	bool z = false;

	ListElem *Search = Begin;

	while (Search)
	{
		if (strlen(name) == strlen(Search->a.name) && strlen(surname) == strlen(Search->a.surname) && strlen(patronymic) == strlen(Search->a.patronymic))
		{
			for (int i = 0; i < strlen(Search->a.name); i++)
			{
				if (name[i] != Search->a.name[i])
				{
					z = true;
					break;
				}
			}

			for (int i = 0; i < strlen(Search->a.surname); i++)
			{
				if (surname[i] != Search->a.surname[i])
				{
					z = true;
					break;
				}
			}

			for (int i = 0; i < strlen(Search->a.patronymic); i++)
			{
				if (patronymic[i] != Search->a.patronymic[i])
				{
					z = true;
					break;
				}
			}

			if (z == false)
			{
				if (choise() == true)
				{
					if (Search == Begin)
					{
						Begin = Search->next;
						delete Search;
						return;
					}
					else
					{
						ListElem *Free2 = Begin;
						ListElem *Free3 = Free2->next;

						while (Free3)
						{
							if (Free3 == Search)
							{
								Free2->next = Free3->next;
								delete Free3;
								return;
							}
							Free2 = Free3;
							Free3 = Free3->next;
						}
					}
				}
			}
		}

		bool z = false;

		Search = Search->next;
	}
}

bool List::Empty()
{
	if (Begin == NULL)
	{
		return true;
	}
}

ostream& operator << (ostream &a,const List &b)
{
	List::ListElem *Show = b.Begin;

	if (b.Begin == NULL)
	{
		a << "================================================================" << endl << endl;
		cout << " EMPTY" << endl;
		cout << "================================================================" << endl << endl;
	}
	else
	{
		while (Show != NULL)
	
		{
			cout << "================================================================" << endl << endl;
			cout << "Name: " << Show->a.name << endl;
			cout << "Surname: " << Show->a.surname << endl;
			cout << "Patronymic: " << Show->a.patronymic << endl;
			cout << "Phone number: " << Show->a.phone_number << endl;
			cout << "Date" << endl;
			cout << "Day: " << Show->a.date[0] << endl;
			cout << "Month: " << Show->a.date[1] << endl;
			cout << "Year: " << Show->a.date[2] << endl;
			cout << "================================================================" << endl << endl;
			Show = Show->next;
		}
	}
	
	return a;
}

ostream& operator << (ostream &a,const List::ListElem *b)
{
	cout << endl << "================================================================" << endl << endl;
	cout << "Name: " << b->a.name << endl;
	cout << "Surname: " << b->a.surname << endl;
	cout << "Patronymic: " << b->a.patronymic << endl;
	cout << "Phone number: " << b->a.phone_number << endl;
	cout << "Date" << endl;
	cout << "Day: " << b->a.date[0] << endl;
	cout << "Month: " << b->a.date[1] << endl;
	cout << "Year: " << b->a.date[2] << endl;
	cout << endl << "================================================================" << endl << endl;
	return a;
}

istream& operator >>(istream &a, List::ListElem *b)
{
	int date2[3];

	cout << "Enter day:";
	a >> date2[0];
	cout << "Enter month:";
	a >> date2[1];
	cout << "Enter year:";
	a >> date2[2];

	List::ListElem *Search = b;
	bool z = false;

	while (Search)
	{
		for (int i = 0; i < 3; i++)
		{
			if (date2[i] != Search->a.date[i])
			{
				z = true;
				break;
			}
		}
		if (z == false)
		{
			cout << Search;
		}
		Search = Search->next;
	}
	return a;
}

void Del(List &clas);

void Menu();

void Menu2(List &clas, Student &a);

void Menu3(List &clas, Student &a);

void Menu4(List &clas, Student &a);

char *Read();

void Check(int &x, string &y);

bool Num(char *buf);

void Insert(List &clas, Student &a);

int main()
{
	List clas;
	Student a;

	Menu();
	Insert(clas, a);
	Menu2(clas,a);

	system("pause");
	return 0;
}

bool choise()
{
	int option;

	do {
		cout << "1.Delete" << endl
			<< "2.Continue" << endl
			<< "Your choice :";

		while (!(cin >> option))
		{
			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
			cin.clear();
			while (cin.get() != '\n');
		}

		if (option < 1 || option >2) cout << "Error. Enter the correct choice" << endl;
	} while (option < 1 || option > 2);

	cout << "================================================================" << endl << endl;

	do
	{
		switch (option)
		{
		case 1:
			return true;
		case 2:
			return false;
		}
	} while (option < 1 || option >2);
}

void Emp(bool x)
{
	if (x == false)
	{
		cout << endl << "================================================================" << endl << endl;
		cout << "Not found" << endl;
		cout << endl << "================================================================" << endl << endl;
	}
}

void Del(List &clas)
{
	char buf[255];
	cout << "Name: ";
	cin >> buf;
	char *del = new char[strlen(buf)];
	strcpy(del, buf);

	cout << "Surname: ";
	cin >> buf;
	char *del1 = new char[strlen(buf)];
	strcpy(del1, buf);

	cout << "Patronymic: ";
	cin >> buf;
	char *del2 = new char[strlen(buf)];
	strcpy(del2, buf);

	clas.Delete(del, del1, del2);
}

void Menu()
{
	int option;

	do
	{
		cout << "1.Enter" << endl
			<< "2.Exit" << endl
			<< "Your choice: ";

		while (!(cin >> option))
		{
			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
			cin.clear();
			while (cin.get() != '\n');
		}
		if (option <1 || option >2) cout << "Error. Enter the correct choice" << endl;
	} while (option < 1 || option >2);

	cout << "================================================================" << endl << endl;

	do
	{
		switch (option)
		{
		case 1:
			return;
		case 2:
			cout << "Bye! ";
			system("pause");
			exit(0);
		}
	} while (option != 2);
}

void Menu2(List &clas, Student &a)
{
	int option;
	bool e = false;
	do
	{
		cout << "1.Continue" << endl
			<< "2.Show all" << endl
			<< "3.Sort" << endl
			<< "4.Search" << endl
			<< "5.Delete elem" << endl
			<< "6.Exit" << endl;

		while (!(cin >> option))
		{
			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
			cin.clear();
			while (cin.get() != '\n');
		}

		if (option < 1 || option > 6) cout << "Error. Enter the correct choice" << endl;
	} while (option < 1 || option > 6);

	cout << "================================================================" << endl << endl;

	do
	{
		switch (option)
		{
		case 1:
			Insert(clas, a);
			Menu2(clas,a);
			break;
		case 2:
			if(clas.Empty() == true)
			{	
				cout << clas;
				Menu2(clas, a);
				break;
			}
			cout << clas;
			Menu2(clas,a);
			break;
		case 3:
			if (clas.Empty() == true)
			{
				cout << clas;
				Menu2(clas, a);
				break;
			}
			Menu4(clas, a);
			Menu2(clas, a);
			break;
		case  4:
			if (clas.Empty() == true)
			{
				cout << clas;
				Menu2(clas, a);
				break;
			}
			Menu3(clas, a);
			Menu2(clas, a);
			break;
		case 5:
			if (clas.Empty() == true)
			{
				cout << clas;
				Menu2(clas, a);
				break;
			}
			Del(clas);
			Menu2(clas, a);
		case 6:
			cout << "Bye! ";
			clas.Free();
			system("pause");
			exit(0);
		}
	} while (option != 5);
}

void Menu3(List &clas, Student &a)
{
	int option;

	do {
		cout << "1.Search by name" << endl
			<< "2.Search by surname" << endl
			<< "3.Search by patronymic" << endl
			<< "4.Search by phone number" << endl
			<< "5.Search by date" << endl
			<< "6.Exit" << endl
			<< "Your choice :";

		while (!(cin >> option))
		{
			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
			cin.clear();
			while (cin.get() != '\n');
		}

		if (option < 1 || option >6) cout << "Error. Enter the correct choice" << endl;
	} while (option < 1|| option > 6);

	cout << "================================================================" << endl << endl;

	char *search = Read();
	do
	{
		switch (option)
		{
		case 1:
			Search(option, search);
			Menu2(clas, a);
			break;
		case 2:
			Search(option, search);
			Menu2(clas, a);
			break;
		case 3:
			Search(option, search);
			Menu2(clas, a);
			break;
		case 4:
			Search(option, search);
			Menu2(clas, a);
			break;
		case 5:
			Search(option, search);
			Menu2(clas, a);
			break;
		case 6:
			Menu2(clas, a);
			break;
		}

	} while (option != 6);
}

void Menu4(List &clas, Student &a)
{
	int option;

	do {
		cout << "1.Sort by day" << endl
			<< "2.Sort by month" << endl
			<< "3.Sort by year" << endl
			<< "4.Exit" << endl
			<< "Your choice :";
		 
		while (!(cin >> option))
		{
			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
			cin.clear();
			while (cin.get() != '\n');
		}

		if (option < 1 || option >4) cout << "Error. Enter the correct choice" << endl;
	} while (option < 1 || option > 4);

	cout << "================================================================" << endl << endl;

	do
	{
		switch (option)
		{
		case 1:
			clas.Sort(option);
			Menu2(clas, a);
			break;
		case 2:
			clas.Sort(option);
			Menu2(clas, a);
			break;
		case 3:
			clas.Sort(option);
			Menu2(clas, a);
			break;
		case 4:
			Menu2(clas, a);
			break;
		}

	} while (option != 4);
}

char *Read()
{
	char buf[255];
	cin >> buf;
	char* str = new char[strlen(buf)];
	strcpy(str, buf);
	return str;
}

void Check(int &x, string &y)
{
	cout << y;
	while (!(cin >> x))
	{
		cout << "[Error] Only numbers" << endl;
		cout << y;
		cin.clear();
		while (cin.get() != '\n');
	}
}

bool Num(char *buf)
{
	const char *temp = "0123456789";

	for (int i = 0; i<strlen(buf); i++)
	{
		if (!strchr(temp, buf[i]))
			return false;
	}
	return true;
}

void Insert(List &clas, Student &a)
{
	char buf[255];
	cout << "Enter name: ";
	a.name = Read();

	cout << "Enter surname: ";
	a.surname = Read();

	cout << "Enter patronymic: ";
	a.patronymic = Read();

	cout << "Enter phone number: ";
	cin >> buf;
	while (!Num(buf)) {
		cout << "[Error] Only numbers" << endl;
		cout << "Enter phone number: ";
		cin >> buf;
	}
	a.phone_number = new char[strlen(buf)];
	strcpy(a.phone_number, buf);

	cout << "Date" << endl;
	string d("Day: ");
	int x = a.date[0];
	Check(x,d);
	a.date[0]= x;

	string m("Month: ");
	int y = a.date[1];
	Check(y, m); 
	a.date[1] = y;

	string g("Year: ");
	int z = a.date[2];
	Check(z, g);
	a.date[2] = z;

	clas.Add(a);

	cout << endl << "================================================================" << endl << endl;
}

//void List::Free2(ListElem *x)
//{
//	ListElem *Free2 = Begin;
//
//	if (x == Free2)
//	{
//		Begin = Free2->next;
//		delete Free2;
//		return;
//	}
//	ListElem *Free3 = Free2->next;
//
//	while (Free3)
//	{
//		if (Free3 == x)
//		{
//			Free2->next = Free3->next;
//			delete Free3;
//			return;
//		}
//		Free2 = Free3;
//		Free3 = Free3->next;
//	}
//}

//void Menu5(List &clas)
//{
//	int option;
//	do {
//		cout << "1.Delete" << endl
//			<< "2.Continue" << endl
//			<< "Your choice :";
//
//		while (!(cin >> option))
//		{
//			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
//			cin.clear();
//			while (cin.get() != '\n');
//		}
//
//		if (option <1 || option >2) cout << "Error. Enter the correct choice" << endl;
//	} while (option < 1 || option>2);
//
//	cout << "================================================================" << endl << endl;
//
//	do
//	{
//		switch (option)
//		{
//		case 1:
//			Del(clas);
//			return;
//		case 2:
//			return;
//		}
//	} while (option != 2);
//}

//void List::Show2(ListElem *x)
//{
//	ListElem *Show = x;
//	cout << endl << "================================================================" << endl << endl;
//	cout << "Name: " << Show->a.name << endl;
//	cout << "Surname: " << Show->a.surname << endl;
//	cout << "Patronymic: " << Show->a.patronymic << endl;
//	cout << "Phone number: " << Show->a.phone_number << endl;
//	cout << "Date" << endl;
//	cout << "Day: " << Show->a.date[0] << endl;
//	cout << "Month: " << Show->a.date[1] << endl;
//	cout << "Year: " << Show->a.date[2] << endl;
//	cout << endl << "================================================================" << endl << endl;
//
//}

//void List::Show()
//{
//	ListElem *Show = Begin;
//
//	while (Show != NULL)
//	{
//		cout << "================================================================" << endl << endl;
//		cout << "Name: " << Show->a.name << endl;
//		cout << "Surname: " << Show->a.surname << endl;
//		cout << "Patronymic: " << Show->a.patronymic << endl;
//		cout << "Phone number: " << Show->a.phone_number << endl;
//		cout << "Date" << endl;
//		cout << "Day: " << Show->a.date[0] << endl;
//		cout << "Month: " << Show->a.date[1] << endl;
//		cout << "Year: " << Show->a.date[2] << endl;
//		cout << "================================================================" << endl << endl;
//		Show = Show->next;
//	}
//}