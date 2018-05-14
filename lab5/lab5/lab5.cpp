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
	int count;
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
	void Add2(const Student &a);
	Student** Search(int option, char *search, int &count, int &score);
	Student** Search2(int option, int *date, int &count, int &score);
	Student** Delete(char *surname, char *name, char *patronymic, int &count, int &score);
	void Delete2(Student **result, int i);
	void Sort(int option);	
	void Free();
	bool Empty();
	friend ostream& operator << (ostream &a, const List &b);
	friend ostream& operator << (ostream &a,const Student &b);
	~List() { Free(); };
};

char *Read();

bool choise();

void Emp(bool x);

void List::Add(const Student &a)
{
	Begin = new ListElem;

	Begin->a.name = a.name;
	Begin->a.surname = a.surname;
	Begin->a.patronymic = a.patronymic;
	Begin->a.phone_number = a.phone_number;
	Begin->a.date[0] = a.date[0];
	Begin->a.date[1] = a.date[1];
	Begin->a.date[2] = a.date[2];
	Begin->a.count = a.count;

	Begin->next = NULL;
}

void List::Add2(const Student &a)
{
	ListElem *Add = new ListElem;

	Add->a.name = a.name;
	Add->a.surname = a.surname;
	Add->a.patronymic = a.patronymic;
	Add->a.phone_number = a.phone_number;
	Add->a.date[0] = a.date[0];
	Add->a.date[1] = a.date[1];
	Add->a.date[2] = a.date[2];
	Add->a.count = a.count;

	ListElem *p = Begin;
	ListElem *p1 = p->next;

	while (p1)
	{
		p = p1;
		p1 = p1->next;
	}
	p->next = Add;
	Add->next = NULL;
}

Student** List::Search(int option, char *search, int &count, int &score)
{
	ListElem *Search = Begin;
	Student** y = new Student*[score];
	bool z = false;
	char *x;

	while (Search)
	{
		if (option == 1) x = Search->a.name;
		if (option == 2) x = Search->a.surname;
		if (option == 3) x = Search->a.patronymic;
		if (option == 4) x = Search->a.phone_number;

		// strcmp

		/*if (strcmp(x, search))
		{
			cout << "+" << endl;
			*y[count] = Search->a;
			cout << *y[count] << endl;
			count++;
		}
*/

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
				y[count] = &Search->a;
				count++;
			}
		}
		Search = Search->next;
	}
	if (count == 0)
	{
		y = NULL;
		return y;
	}
	else
		return y;

}

Student** List::Search2(int option, int *date, int& count, int &score)
{
	ListElem *Search = Begin;
	Student** y = new Student*[score];
	bool z = false;

	while (Search)
	{
		for (int i = 0; i < 3; i++)
		{
			if (date[i] != Search->a.date[i])
			{
				z = false;
				break;
			}
			else z = true;
		}
		if (z == true)
		{
			y[count] = &Search->a;
			count++;
		}
		Search = Search->next;
	}
	if (count == 0)
	{
		y = NULL;
		return y;
	}
	else
		return y;
}

Student** List::Delete(char *name, char *surname, char *patronymic, int &count, int &score)
{
	bool z = false;
	Student** y = new Student*[score];
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
				y[count] = &Search->a;
				count++;
			}
		}

		bool z = false;

		Search = Search->next;
	}

	if (count == 0)
	{
		y = NULL;
		return y;
	}
	else
		return y;
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

void List::Delete2(Student **result, int i)
{
	ListElem *Search = Begin;
	ListElem *Search2;
	for (int j = 0; j <= result[i]->count; j++)
	{
		if (j == result[i]->count)
		{
			if (Search == Begin)
			{
				Begin = Search->next;
				Search2 = Begin;
				delete Search;
				break;
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
						Search2 = Free2->next;
						delete Free3;
						break;
					}
					Free2 = Free3;
					Free3 = Free3->next;
				}
			}

		}
		Search = Search->next;
	}

	if (Search2 != NULL)
	{
		do
		{
			Search2->a.count--;
			Search2 = Search2->next;
		}while (Search2);
	}
	return;

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
		a << " EMPTY" << endl;
		a << "================================================================" << endl << endl;
	}
	else
	{
		while (Show != NULL)
	
		{
			a << "================================================================" << endl << endl;
			a << "Name: " << Show->a.name << endl;
			a << "Surname: " << Show->a.surname << endl;
			a << "Patronymic: " << Show->a.patronymic << endl;
			a << "Phone number: " << Show->a.phone_number << endl;
			a << "Date" << endl;
			a << "Day: " << Show->a.date[0] << endl;
			a << "Month: " << Show->a.date[1] << endl;
			a << "Year: " << Show->a.date[2] << endl;
			a << "count: " << Show->a.count << endl;
			a << "================================================================" << endl << endl;
			Show = Show->next;
		}
	}
	
	return a;
}

ostream& operator << (ostream &a,const Student &b)
{
	a << endl << "================================================================" << endl << endl;
	a << "Name: " << b.name << endl;
	a << "Surname: " << b.surname << endl;
	a << "Patronymic: " << b.patronymic << endl;
	a << "Phone number: " << b.phone_number << endl;
	a << "Date" << endl;
	a << "Day: " << b.date[0] << endl;
	a << "Month: " << b.date[1] << endl;
	a << "Year: " << b.date[2] << endl;
	a << "count: " << b.count << endl;
	a << endl << "================================================================" << endl << endl;
	return a;
}

void Del(List &clas, Student &a, int &score);
void NotF();
void Case1(List &clas, int option, int &score);
void Case2(List &clas, int option, int &score);
void Menu();
void Menu2(List &clas, Student &a, int &score);
void Menu3(List &clas, Student &a, int &score);
void Menu4(List &clas, Student &a, int &score);
void Menu5(List &clas, Student &a, Student **result, int &score, int i);
void Check(int &x, string &y);
bool Num(char *buf);
Student Insert(Student &a, int &score);


int main()
{
	int score = 0;

	List clas;
	Student a;
	Student b;
	Menu();

	b= Insert(a, score);
	clas.Add(b);
	Menu2(clas,a, score);

	system("pause");
	return 0;
}


void NotF()
{
	cout << "================================================================" << endl << endl;
	cout << " NOT FOUND" << endl;
	cout << "================================================================" << endl << endl;
}

int *Date()
{
	int *date= new int[3];

	cout << "Enter day:";
	cin >> date[0];
	cout << "Enter month:";
	cin >> date[1];
	cout << "Enter year:";
	cin >> date[2];

	return date;
}

void Case1(List &clas, int option, int &score) 
{
	Student **result;
	int count = 0;

	char *search = Read();

	result = clas.Search(option, search, count, score);
	if (result != NULL)
		for (int i = 0; i < count; i++)
			cout << *(result[i]);
	else
		NotF();
}

void Case2(List &clas, int option, int &score)
{
	Student **result;
	int count = 0;

	int *date = Date();

	for (int i = 0; i < 3; i++)
		cout << date[i] << endl;

	result = clas.Search2(option, date, count, score);
	if (result != NULL)
		for (int i = 0; i < count; i++)
			cout << *(result[i]);
	else
		NotF();
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

void Del(List &clas,Student &a , int &score)
{
	int count = 0;

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

	Student **result;

	result = clas.Delete(del, del1, del2, count, score);

	int i = 0;

	if (result != NULL)
	{
		for (; i < count; i++)
		{
			cout << endl << i+1 << ":" << *result[i];
		}
		Menu5(clas, a, result, score, i);
	}
	else
		NotF();
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

void Menu2(List &clas, Student &a,int &score)
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

	Student b;

	do
	{
		switch (option)
		{
		case 1:
			 b = Insert(a,score);
			 clas.Add2(b);
			Menu2(clas,a, score);
			break;
		case 2:
			if(clas.Empty() == true)
			{	
				cout << clas;
				Menu2(clas, a, score);
				break;
			}
			cout << clas;
			Menu2(clas, a, score);
			break;
		case 3:
			if (clas.Empty() == true)
			{
				cout << clas;
				Menu2(clas, a, score);
				break;
			}
			Menu4(clas, a, score);
			Menu2(clas, a, score);
			break;
		case  4:
			if (clas.Empty() == true)
			{
				cout << clas;
				Menu2(clas, a, score);
				break;
			}
			Menu3(clas, a, score);
			Menu2(clas, a, score);
			break;
		case 5:
			if (clas.Empty() == true)
			{
				cout << clas;
				Menu2(clas, a, score);
				break;
			}
			Del(clas, a, score);
			Menu2(clas, a, score);
		case 6:
			cout << "Bye! ";
			clas.Free();
			system("pause");
			exit(0);
		}
	} while (option != 5);
}

void Menu3(List &clas, Student &a, int &score)
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
			Case1(clas, option, score);
			Menu2(clas, a, score);
			break;
		case 2:
			Case1(clas, option, score);
			Menu2(clas, a, score);
			break;
		case 3:
			Case1(clas, option, score);
			Menu2(clas, a, score);
			break;
		case 4:
			Case1(clas, option, score);
			Menu2(clas, a, score);
			break;
		case 5:
			Case2(clas, option, score);
			Menu2(clas, a, score);
			break;
		case 6:
			Menu2(clas, a, score);
			break;
		}

	} while (option != 6);
}

void Menu4(List &clas, Student &a, int &score)
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
			Menu2(clas, a, score);
			break;
		case 2:
			clas.Sort(option);
			Menu2(clas, a, score);
			break;
		case 3:
			clas.Sort(option);
			Menu2(clas, a, score);
			break;
		case 4:
			Menu2(clas, a, score);
			break;
		}

	} while (option != 4);
}

void Menu5(List &clas, Student &a,Student **result, int &score, int i)
{
	int option = 0;
	do
	{
		cout << "Enter a number of your choice or enter 0 to exit:";

		while (!(cin >> option))
		{
			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
			cin.clear();
			while (cin.get() != '\n');
		}

	} while (option < 0 || option > i + 1);

	do
	{
		switch (option)
		{
		case 0:
			Menu2(clas, a, score);
			break;
		default:
			option--;
			clas.Delete2(result, option);
			Menu2(clas, a, score);
			break;
		}
	} while (option != 0);

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

Student Insert(Student &a, int &score)
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

	a.count = score;
	score++;

	cout << endl << "================================================================" << endl << endl;
	return a;
}