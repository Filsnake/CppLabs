#include <iostream>

using namespace std;

class Student
{
public:
	int number;
};

class List 
{
private:
	struct  ListElem
	{
		Student a;
		ListElem *next;
	};
public:
	ListElem *Begin = NULL;
	void Add(Student &a);
	void Show();
	void Free();
};

void List::Add(Student &a)
{
	ListElem *Add = new ListElem;

	Add->next = Begin;

	Add->a.number = a.number;
	Begin = Add;
}

void List::Show()
{
	ListElem *Show = Begin;
	while (Show != NULL)
	{
		cout << Show->a.number << endl;
		Show = Show->next;
	}
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

int main() 
{
	List clas;
	Student a;

	for (int i = 0; i < 5; i++) 
	{
		cin >> a.number;
		clas.Add(a);
	}
	clas.Show();
	clas.Free();
	clas.Show();
	system("pause");
	return 0;
}