#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

enum SearchType { ByName = 1, BySurname, ByPatronymic, ByPhone_number, ByDate };

enum SortType { ByDay = 1, ByMonth, ByYear };

class Student
{
	char *Surname = nullptr;
	char *Name = nullptr;
	char *Patronymic = nullptr;
	char *Phone_number = nullptr;
	int Date[3];

public:
	Student(const char* surname, const char* name, const char* patronymic, const char* phone_number, const int* date)
	{
		Surname = new char[strlen(surname) + 1];
		strcpy(Surname, surname);

		Name = new char[strlen(name) + 1];
		strcpy(Name, name);

		Patronymic = new char[strlen(patronymic) + 1];
		strcpy(Patronymic, patronymic);

		Phone_number = new char[strlen(phone_number) + 1];
		strcpy(Phone_number, phone_number);

		for (int i = 0; i < 3; i++)
			Date[i] = date[i];
	}

	char* getSurname()
	{
		char* new_surname = new char[strlen(Surname) + 1];
		strcpy(new_surname, Surname);

		return new_surname;
	}
	char* getName()
	{
		char* new_name = new char[strlen(Name) + 1];
		strcpy(new_name, Name);

		return new_name;
	}
	char* getPatronymic()
	{
		char* new_patronymic = new char[strlen(Patronymic) + 1];
		strcpy(new_patronymic, Patronymic);

		return new_patronymic;
	}
	char* getPhone_number()
	{
		char* new_phone_number = new char[strlen(Phone_number) + 1];
		strcpy(new_phone_number, Phone_number);

		return new_phone_number;
	}
	int* getDate()
	{
		int* new_date = new int[3];
		for (int i = 0; i < 3; i++)
		{
			new_date[i] = Date[i];
		}
		return new_date;
	}

	~Student()
	{
		delete[] Surname;
		delete[] Name;
		delete[] Patronymic;
		delete[] Phone_number;
	};
};

class List
{
	struct ListElem
	{
		Student *a;
		ListElem *next;
	};
	ListElem *Begin = nullptr;
public:
	Student** Search_ByFIO(const SearchType By, const char *search,int &count);
	Student** Search_ByDate(const int *date, int &count);
	Student** Search_to_Delete(const char *surname,const char *name,const char *patronymic,int &count);
	friend ostream& operator << (ostream &stream, const List &All_List);
	friend ostream& operator << (ostream &stream, Student &OneStudent);
	void AddElem(const char* surname, const char* name, const char* patronymic, const char* phone_number, const int* date);
	void SortElements(SortType By);
	void DeleteElem(Student **result, int i);
	bool EmptyList();
	void FreeList();

	~List() { FreeList(); }
};

Student** List::Search_ByFIO(const SearchType By,const char *search, int &count)
{
	int Score = 0;
	ListElem *Scroll = Begin;
	while (Scroll)
	{
		Score++;
		Scroll = Scroll->next;
	}

	ListElem *Search = Begin;
	Student** y = new Student*[Score];

	char *x;

	while (Search)
	{
		if (By == SearchType::ByName) x = Search->a->getName();
		if (By == SearchType::BySurname) x = Search->a->getSurname();
		if (By == SearchType::ByPatronymic) x = Search->a->getPatronymic();
		if (By == SearchType::ByPhone_number) x = Search->a->getPhone_number();

		if (strcmp(x, search) == 0)
		{
			y[count] = Search->a;
			count++;
		}
		Search = Search->next;
	}

	delete[] x; 

	if (count == 0)
	{
		y = NULL;
		return y;
	}
	else
		return y;

}

Student** List::Search_ByDate(const int *date,int& count)
{
	int score = 0;

	ListElem *Scroll = Begin;
	while (Scroll)
	{
		score++;
		Scroll = Scroll->next;
	}

	ListElem *Search = Begin;
	Student** y = new Student*[score];
	
	bool z = false;
	int *Date;
	while (Search)
	{
		Date = Search->a->getDate();

		for (int i = 0; i < 3; i++)
		{
			if (date[i] != Date[i])
			{
				z = false;
				break;
			}
			else z = true;
		}
		if (z == true)
		{
			y[count] = Search->a;
			count++;
		}
		Search = Search->next;
	}

	delete[] Date;

	if (count == 0)
	{
		y = NULL;
		return y;
	}
	else
		return y;
}

Student** List::Search_to_Delete(const char *name,const char *surname,const char *patronymic,int &count)
{
	int score = 0;

	ListElem *Scroll = Begin;
	while (Scroll)
	{
		score++;
		Scroll = Scroll->next;
	}

	Student** y = new Student*[score];
	ListElem *Search = Begin;

	while (Search)
	{
		if (strcmp(name, Search->a->getName()) == 0 && strcmp(surname, Search->a->getSurname()) == 0 && strcmp(patronymic, Search->a->getPatronymic()) == 0)
		{
			y[count] = Search->a;
			count++;
		}
		Search = Search->next;
	}

	delete[] name;
	delete[] surname;
	delete[] patronymic;

	if (count == 0)
	{
		y = NULL;
		return y;
	}
	else
		return y;
}

ostream& operator << (ostream &stream, const List &All_List)
{
	List::ListElem *Show = All_List.Begin;

	if (All_List.Begin == NULL)
	{
		stream << "================================================================" << endl << endl;
		stream << " EMPTY" << endl;
		stream << "================================================================" << endl << endl;
	}
	else
	{
		int *Date;
		while (Show != NULL)
		{			
			stream << "================================================================" << endl << endl;
			stream << "Name: " << Show->a->getName() << endl;
			stream << "Surname: " << Show->a->getSurname() << endl;
			stream << "Patronymic: " << Show->a->getPatronymic() << endl;
			stream << "Phone number: " << Show->a->getPhone_number() << endl;
			stream << "Date" << endl;
			Date = Show->a->getDate();
			stream << "Day: " << Date[0] << endl;
			stream << "Month: " << Date[1] << endl;
			stream << "Year: " << Date[2] << endl;
			stream << "================================================================" << endl << endl;
			Show = Show->next;
		}
		delete[] Date;
	}

	return stream;
}

ostream& operator << (ostream &stream, Student &OneStudent)
{
	int *Date;
	stream << endl << "================================================================" << endl << endl;
	stream << "Name: " << OneStudent.getName() << endl;
	stream << "Surname: " << OneStudent.getSurname() << endl;
	stream << "Patronymic: " << OneStudent.getPatronymic() << endl;
	stream << "Phone number: " << OneStudent.getPhone_number() << endl;
	stream << "Date" << endl;
	Date = OneStudent.getDate();
	stream << "Day: " << Date[0] << endl;
	stream << "Month: " << Date[1] << endl;
	stream << "Year: " << Date[2] << endl;
	stream << endl << "================================================================" << endl << endl;
	delete[] Date;
	return stream;
}

void List::AddElem(const char* surname, const char* name, const char* patronymic, const char* phone_number, const int* date)
{
	if (Begin == NULL)
	{
		Begin = new ListElem;
		Begin->a = new Student(surname, name, patronymic, phone_number, date);
		Begin->next = NULL;
	}
	else
	{
		ListElem *Add = new ListElem;
		Add->a = new Student(surname, name, patronymic, phone_number, date);

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
}

void List::DeleteElem(Student **result, int i)
{
	ListElem *Search = Begin;

	while (Search)
	{
		if (result[i] == Search->a)
		{
			if (Search == Begin)
			{
				Begin = Search->next;
				delete Search;
				delete[] result;
				return;
			}
			else
			{
				ListElem *Free = Begin;
				ListElem *Free2 = Free->next;
				while (Free2)
				{
					if (Free2 == Search)
					{
						Free->next = Free2->next;
						delete Free2;
						delete[] result;
						return;
					}
					Free = Free2;
					Free2 = Free2->next;
				}
			}
		}
		Search = Search->next;
	}
}

void List::SortElements(SortType By)
{
	int x, y, z;
	int *Date1, *Date2, *Date3;
	ListElem *New = NULL;

	while (Begin != NULL)
	{
		ListElem *Sort = Begin;

		Date1 = Sort->a->getDate();
		if (By == SortType::ByDay) x = Date1[0];
		if (By == SortType::ByMonth) x = Date1[1];
		if (By == SortType::ByYear) x = Date1[2];
		delete[] Date1;

		if (New != NULL)
		{
			Date2 = New->a->getDate();
			if (By == SortType::ByDay) y = Date2[0];
			if (By == SortType::ByMonth) y = Date2[1];
			if (By == SortType::ByYear) y = Date2[2];
			delete[] Date2;
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
				Date3 = Current->next->a->getDate();
				if (By == SortType::ByDay) z = Date3[0];
				if (By == SortType::ByMonth) z = Date3[1];
				if (By == SortType::ByYear) z = Date3[2];
				delete[] Date3;
			}

			while (Current->next != NULL && !(x < z))
				Current = Current->next;

			Sort->next = Current->next;
			Current->next = Sort;
		}
	}
	Begin = New;
}

void List::FreeList()
{
	while (Begin != NULL)
	{
		ListElem *Free = Begin->next;
		delete Begin->a;
		delete Begin;
		Begin = Free;
	}
}

bool List::EmptyList()
{
	if (Begin == NULL)
	{
		return true;
	}
}

void Start_Menu();
void Main_Menu(List &clas);
void Menu_For_SearchBy(List &clas);
void Menu_For_SortElemens(List &clas);
void Menu_Of_Choise_For_DeleteElem(List &clas, Student **result, int i);
bool Menu_for_DeleteElem();
void InsertNewElem(List &clas);
void DeleteFunc(List &clas);
void Search_By(List &clas, SearchType By);
void NotF();
int *Date();
void NumbersCheck(int &x, string &y);
bool OnlyNumbers(char *buf);
char *readString();
void EmptyCheck(bool x);


int main()
{
	List clas;

	Start_Menu();
	InsertNewElem(clas);
	Main_Menu(clas);

	system("pause");
	return 0;
}


void Start_Menu()
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
			system("cls");
			return;
		case 2:
			cout << "Bye! ";
			system("pause");
			exit(0);
		}
	} while (option != 2);
}

void Main_Menu(List &clas)
{
	int option;
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
			InsertNewElem(clas);
			Main_Menu(clas);
			break;
		case 2:
			if (clas.EmptyList() == true)
			{
				cout << clas;
				Main_Menu(clas);
				break;
			}
			cout << clas;
			Main_Menu(clas);
			break;
		case 3:
			if (clas.EmptyList() == true)
			{
				cout << clas;
				Main_Menu(clas);
				break;
			}
			Menu_For_SortElemens(clas);
			Main_Menu(clas);
			break;
		case  4:
			if (clas.EmptyList() == true)
			{
				cout << clas;
				Main_Menu(clas);
				break;
			}
			Menu_For_SearchBy(clas);
			Main_Menu(clas);
			break;
		case 5:
			if (clas.EmptyList() == true)
			{
				cout << clas;
				Main_Menu(clas);
				break;
			}
			DeleteFunc(clas);
			Main_Menu(clas);
		case 6:
			cout << "Bye! ";
			clas.FreeList();
			system("pause");
			exit(0);
		}
	} while (option != 6);
}

void Menu_For_SearchBy(List &clas)
{
	int option = ByName;
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
	} while (option < 1 || option > 6);

	cout << "================================================================" << endl << endl;

	do
	{
		switch (option)
		{
		case (ByName):
			Search_By(clas, ByName);
			Main_Menu(clas);
			break;
		case (BySurname):
			Search_By(clas, BySurname);
			Main_Menu(clas);
			break;
		case (ByPatronymic):
			Search_By(clas, ByPatronymic);
			Main_Menu(clas);
			break;
		case (ByPhone_number):
			Search_By(clas, ByPhone_number);
			Main_Menu(clas);
			break;
		case (ByDate):
			Search_By(clas, ByDate);
			Main_Menu(clas);
			break;
		case 6:
			Main_Menu(clas);
			break;
		}

	} while (option != 6);
}

void Menu_For_SortElemens(List &clas)
{
	int option = ByDay;
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
		case ByDay:
			clas.SortElements(ByDay);
			Main_Menu(clas);
			break;
		case ByMonth:
			clas.SortElements(ByMonth);
			Main_Menu(clas);
			break;
		case ByYear:
			clas.SortElements(ByYear);
			Main_Menu(clas);
			break;
		case 4:
			Main_Menu(clas);
			break;
		}

	} while (option != 4);
}

void Menu_Of_Choise_For_DeleteElem(List &clas, Student **result, int i)
{
	int option = 0;
	do
	{
		cout << "Enter a number of your choice or enter 0 to exit:";
		cout << "Enter:";
		while (!(cin >> option))
		{
			cout << "Error. Enter the correct choice" << endl << "Your choice: ";
			cin.clear();
			while (cin.get() != '\n');
		}

	} while (option < 0 || option > i);

	do
	{
		switch (option)
		{
		case 0:
			Main_Menu(clas);
			break;
		default:
			--option;
			clas.DeleteElem(result, option);
			Main_Menu(clas);
			break;
		}
	} while (option != 0);
}

bool Menu_for_DeleteElem()
{
	int option;

	do {
		cout << "================================================================" << endl << endl
			<< "1.Delete" << endl
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

void InsertNewElem(List &clas)
{
	cin.ignore();
	cout << "Enter name: ";
	char *name = readString();

	cout << "Enter surname: ";
	char *surname = readString();

	cout << "Enter patronymic: ";
	char *patronymic = readString();

	cout << "Enter phone number: ";
	char buf[255];
	cin.getline(buf, 255);
	while (!OnlyNumbers(buf)) {
		cout << "[Error] Only numbers" << endl;
		cout << "Enter phone number: ";
		cin.getline(buf, 255);
	}
	char *phone_number = new char[strlen(buf) + 1];
	strcpy(phone_number, buf);

	int date[3];

	cout << "Date" << endl;
	string d("Day: ");
	NumbersCheck(date[0], d);

	string m("Month: ");
	NumbersCheck(date[1], m);

	string g("Year: ");
	NumbersCheck(date[2], g);

	clas.AddElem(surname, name, patronymic, phone_number, date);
	cout << endl << "================================================================" << endl << endl;
}

void DeleteFunc(List &clas)
{
	cin.ignore();

	int count = 0;
	char buf[255];

	cout << "Name: ";
	cin.getline(buf, 255);
	char *del = new char[strlen(buf) + 1];
	strcpy(del, buf);

	cout << "Surname: ";
	cin.getline(buf, 255);
	char *del1 = new char[strlen(buf) + 1];
	strcpy(del1, buf);

	cout << "Patronymic: ";
	cin.getline(buf, 255);
	char *del2 = new char[strlen(buf) + 1];
	strcpy(del2, buf);

	Student **result;

	result = clas.Search_to_Delete(del, del1, del2, count);

	int i = 0;

	if (result != NULL)
	{
		if (count == 1)
		{
			if (Menu_for_DeleteElem() == true)
			{
				clas.DeleteElem(result, i);
				Main_Menu(clas);
			}
			else
				Main_Menu(clas);
		}
		else
		{
			for (; i < count; i++)
				cout << endl << *result[i];
			Menu_Of_Choise_For_DeleteElem(clas, result, i);
		}
	}
	else
		NotF();
}

void Search_By(List &clas, SearchType By)
{
	cin.ignore();

	Student **result;
	int count = 0;

	if (By == SearchType::ByDate)
	{
		int *date = Date();

		result = clas.Search_ByDate(date, count);

		if (result != NULL)
			for (int i = 0; i < count; i++)
				cout << *(result[i]);
		else
			NotF();
		delete[] result;
		delete[] date;
	}
	else
	{
		char *search = readString();

		result = clas.Search_ByFIO(By, search, count);
		if (result != NULL)
			for (int i = 0; i < count; i++)
				cout << *(result[i]);
		else
			NotF();
		delete[] result;
		delete[] search;
	}
}

void NotF()
{
	cout << "================================================================" << endl << endl;
	cout << " NOT FOUND" << endl;
	cout << "================================================================" << endl << endl;
}

int *Date()
{
	int *date = new int[3];

	cout << "Enter day:";
	cin >> date[0];
	cout << "Enter month:";
	cin >> date[1];
	cout << "Enter year:";
	cin >> date[2];

	return date;
}

void NumbersCheck(int &x, string &y)
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

bool OnlyNumbers(char *buf)
{
	const char *temp = "0123456789";

	for (int i = 0; i<strlen(buf); i++)
	{
		if (!strchr(temp, buf[i]))
			return false;
	}
	return true;
}

char *readString()
{
	char buf[255];
	cin.getline(buf, 255);
	char* str = new char[strlen(buf) + 1];
	strcpy(str, buf);
	return str;
}

void EmptyCheck(bool x)
{
	if (x == false)
	{
		cout << endl << "================================================================" << endl << endl;
		cout << "Not found" << endl;
		cout << endl << "================================================================" << endl << endl;
	}
}
