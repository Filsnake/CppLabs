#include <iostream>

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

void init(list **begin)
{
	*begin = new list;

	cout << endl;
	cout << "Введите фамилию: ";

	cin >> (*begin) -> a.surname;

	//cout << "Имя: ";
	//cin >> (*begin) -> a.name;

	//cout << "Телефон: ";
	//cin >> (*begin) -> a.phone_number;

	//cout << "Дата рождения"<< endl;
	//cout << "День: ";
	//cin >> (*begin) -> a.date[0];
	//cout << "Месяц: ";
	//cin >> (*begin) -> a.date[1];
	//cout << "Год: ";
	//cin >> (*begin) -> a.date[2];

	(*begin) -> next= NULL;

	list *end= *begin;

	for(int i=0; ;i++)
	{

		cout << "Чтобы прекратить ввод введите 'n', иначе, любой символ: " << endl;

		char x;
		cin >> x;

		if(x == 'n')
		{
			break;
		}
		end -> next= NULL;
		end->next= new list;
		end=end ->next;
		cout << "Введите фамилию: ";
		cin >> end->a.surname;

		//cout << "Имя: ";
		//cin >> end->a.name;

		//cout << "Телефон: ";
		//cin >> end->a.phone_number;

		//cout << "Дата рождения"<< endl;
		//cout << "День: ";
		//cin >> end->a.date[0];
		//cout << "Месяц: ";
		//cin >> end->a.date[1];
		//cout << "Год: ";
		//cin >> end->a.date[2];

		if((*begin)->a.surname > end->a.surname)
		{
			end->next=(*begin);
			(*begin)=end;
		}
		cout << (*begin)->a.surname << ' ' << (*begin)->next->a.surname  << endl;
		(*begin)=(*begin)->next;
		end=end->next;

		/*while((*begin)->next)
		{
			if((*begin)->a.surname < end->a.surname && end->a.surname <= (*begin)->next->a.surname)
			{
				cout << "+" << endl;
				(*begin)->next = end;
				end->next = (*begin)->next;
			}
			(*begin)=(*begin)->next;
			(*begin)->next=(*begin)->next->next;
			(*begin)->next=NULL;
		}*/
	}
}

void print(list **begin)
{
	int i=0;
	while((*begin))
	{
	i++;
	cout << i <<(*begin)->a.surname << endl;
	//cout << (*begin)->a.name<< endl;
	//cout << (*begin)->a.phone_number<< endl;
	//cout << (*begin)->a.date[0]<< endl;
	//cout << (*begin)->a.date[1]<< endl;
	//cout << (*begin)->a.date[2]<< endl;
	//cout << (*begin)->a.surname << ' ' << (*begin)->next->a.surname  << endl;
	(*begin)=(*begin)->next;

	cout << endl;

	}
}
int main()
{

	list* begin=NULL;

	init(&begin);
	print(&begin);
	return 0;
}
