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
	void Show2(ListElem *x);
	void Free2(ListElem *x);
	void Menu(ListElem *x);
public:
	void Add(Student &a);
	void Search(int option);
	void Show();	
	void Sort(int option);	
	void Free();	
	bool Empty();
};

void List::Add(Student &a)
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

void List::Search(int option)
{
	ListElem *Search = Begin;

	bool z = false;

	if (option >= 1 && option != 5)
	{
		char *x;

		char buf[255];
		cout << "Enter:";
		cin >> buf;
		char *search = new char[strlen(buf)];
		strcpy(search, buf);

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
					Show2(Search);
					Menu(Search);
					break;
				}
			}
			Search = Search->next;
		}
		if (z == false)
		{
			cout << endl << "================================================================" << endl << endl;
			cout << "Not found" << endl;
			cout << endl << "================================================================" << endl << endl;
		}
	}

	if (option == 5)
	{
		int date2[3];

		cout << "Enter day:";
		cin >> date2[0];
		cout << "Enter month:";
		cin >> date2[1];
		cout << "Enter year:";
		cin >> date2[2];

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
				Show2(Search);
				break;
			}
			Search = Search->next;
		}
		if (z == true)
		{
			cout << endl << "================================================================" << endl << endl;
			cout << "Not found" << endl;
			cout << endl << "================================================================" << endl << endl;
		}
	}
}

void List::Show()
{
	ListElem *Show = Begin;

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

void List::Show2(ListElem *x)
{
	ListElem *Show = x;
	cout << endl << "================================================================" << endl << endl;
	cout << "Name: " << Show->a.name << endl;
	cout << "Surname: " << Show->a.surname << endl;
	cout << "Patronymic: " << Show->a.patronymic << endl;
	cout << "Phone number: " << Show->a.phone_number << endl;
	cout << "Date" << endl;
	cout << "Day: " << Show->a.date[0] << endl;
	cout << "Month: " << Show->a.date[1] << endl;
	cout << "Year: " << Show->a.date[2] << endl;
	cout << endl << "================================================================" << endl << endl;

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

void List::Menu(ListElem *x)
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

		if (option <1 || option >2) cout << "Error. Enter the correct choice" << endl;
	} while (option < 1 || option>2);

	cout << "================================================================" << endl << endl;

	do
	{
		switch (option)
		{
		case 1:
			Free2(x);
			return;
		case 2:
			return;
		}
	} while (option != 2);
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

void List::Free2(ListElem *x)
{
	ListElem *Free2 = Begin;

	if (x == Free2)
	{
		Begin = Free2->next;
		delete Free2;
		return;
	}
	ListElem *Free3 = Free2->next;

	while (Free3)
	{
		if (Free3 == x)
		{
			Free2->next = Free3->next;
			delete Free3;
			return;
		}
		Free2 = Free3;
		Free3 = Free3->next;
	}
}

bool List::Empty()
{
	if (Begin == NULL)
	{
		cout << "================================================================" << endl << endl;
		cout << " EMPTY" << endl;
		cout << "================================================================" << endl << endl;
		return true;
	}
}

char* Read();

void Menu();

void Menu2(List &clas, Student &a);

void Menu3(List &clas, Student &a);

void Menu4(List &clas, Student &a);

char *Read();

void Check(int &x, string &y);

bool Num(const char *buf);

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
			 << "5.Exit" << endl;

		while (!(cin >> option))
		{
			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
			cin.clear();
			while (cin.get() != '\n');
		}

		if (option < 1 || option > 5) cout << "Error. Enter the correct choice" << endl;
	} while (option < 1 || option > 5);

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
				Menu2(clas, a);
				break;
			}
			clas.Show();
			Menu2(clas,a);
			break;
		case 3:
			if (clas.Empty() == true)
			{
				Menu2(clas, a);
				break;
			}
			Menu4(clas, a);
			Menu2(clas, a);
			break;
		case  4:
			if (clas.Empty() == true)
			{
				Menu2(clas, a);
				break;
			}
			Menu3(clas, a);
			Menu2(clas, a);
			break;
		case 5:
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

	do
	{
		switch (option)
		{
		case 1:
			clas.Search(option);
			Menu2(clas, a);
			break;
		case 2:
			clas.Search(option);
			Menu2(clas, a);
			break;
		case 3:
			clas.Search(option);
			Menu2(clas, a);
			break;
		case 4:
			clas.Search(option);
			Menu2(clas, a);
			break;
		case 5:
			clas.Search(option);
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
		cout << "Day: ";
		cin.clear();
		while (cin.get() != '\n');
	}
}

bool Num(const char *buf)
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