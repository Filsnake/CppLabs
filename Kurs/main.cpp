#include <iostream>
#include <cstring>

using namespace std;

enum MainM { EnterM = 1, ShowAll, Show, Stat, ExitM};

class Train {
    char* Number;
    char* Station;
    char* Time;
public:
    Train(char* number, char* station, char* time);
    Train(Train& train);
    char* getNumber();
    char* getStation();
    char* getTime();
    friend ostream& operator << (ostream &stream, Train &train);
    ~Train();
};

Train::Train(char* number, char* station, char* time) {
    Number = new char[strlen(number)+1];
    strcpy(Number, number);

    Station = new char[strlen(station)+1];
    strcpy(Station, station);

    Time = new char[strlen(time)+1];
    strcpy(Time, time);
}
Train::Train(Train &train) {
    cout << "+\n";
    this->Number = new char[strlen(train.getNumber())+1];
    strcpy(this->Number, train.getNumber());
    this->Station = new char[strlen(train.getStation())+1];
    strcpy(this->Station, train.getStation());
    this->Time = new char[strlen(train.getTime())+1];
    strcpy(this->Time, train.getTime());
}
char* Train::getNumber() {
    auto* newNumber = new char[strlen(Number)+1];
    strcpy(newNumber, Number);
    return newNumber;
}
char* Train::getStation() {
    auto* newStation = new char[strlen(Station)+1];
    strcpy(newStation, Station);
    return newStation;
}
char* Train::getTime() {
    auto* newTime = new char[strlen(Time)+1];
    strcpy(newTime, Time);
    return newTime;
}
ostream& operator << (ostream &stream, Train &train) {
    stream << "\n";
    stream << "Number: "<<train.getNumber() << endl;
    stream << "Station:" << train.getStation() << endl;
    stream << "Time:" << train.getTime() << endl;
    stream << "\n";
    return stream;
}
Train::~Train() {
    delete Number;
    delete Station;
    delete Time;
}

template <class TKey, class TValue>
class Collection{
    struct Key_Value {
        TKey Key;
        TValue Value;
    };
    struct ListElem {
        Key_Value *KeyValue;
        ListElem *Next;
        TKey getKey() {
            TKey newKey = KeyValue->Key;
            return newKey;
        }
    };
    ListElem *Begin = nullptr;
public:
    void AddEl(TKey& tKey, TValue& tValue) {
        if(Begin == nullptr) {
            Begin = new ListElem;
            Begin->KeyValue= new Key_Value{tKey, tValue};
            Begin->Next = nullptr;
        }
        else {
            ListElem *Add = new ListElem;
            Add->KeyValue= new Key_Value{tKey, tValue};

            ListElem *p = Begin;
            ListElem *p1 = p->Next;

            while (p1) {
                p = p1;
                p1 = p1->Next;
            }
            p->Next = Add;
            Add->Next = nullptr;
        }
    }
    Train** ShowByKey(TKey& tKey, int& count) {
        int Score = 0;
        ListElem *Scroll = Begin;
        while (Scroll)
        {
            Score++;
            Scroll = Scroll->Next;
        }

        ListElem *Search = Begin;
        Train** y = new Train*[Score];

        while(Search) {
            if(strcmp(Search->getKey(), tKey)==0) {
                y[count] = Search->KeyValue->Value;
                count++;
            }
            Search = Search->Next;
        }
        if (count == 0)
        {
            y = nullptr;
            return y;
        }
        else
            return y;
    }
    Train** SearchByStation(char* stat, int& count) {
        int Score = 0;
        ListElem *Scroll = Begin;
        while (Scroll)
        {
            Score++;
            Scroll = Scroll->Next;
        }

        ListElem *Search = Begin;
        Train** y = new Train*[Score];

        while (Search) {
            Train train = *Search->KeyValue->Value;
            if(strcmp(train.getStation(), stat)==0) {
                y[count] = Search->KeyValue->Value;
                count++;
            }
            Search =Search->Next;
        }
        if (count == 0)
        {
            y = nullptr;
            return y;
        }
        else
            return y;
    }
};

void MainMenu(Collection<char*,Train*>& Main);
void EnterKV(Collection<char*, Train*>& Main);
void ShowByKey(Collection<char*, Train*>& Main);
void SearchByStation(Collection<char*, Train*>& Main);
void NotF();
char* Enter();


int main() {
    Collection<char*,Train*> Main;
    MainMenu(Main);
    return 0;
}

void MainMenu(Collection<char*,Train*>& Main){
    bool run = true;
    int option = EnterM;
    while(run) {
        do {
            cout << "1.Enter\n"
                 << "2.ShowAll\n"
                 << "3.Show\n"
                 << "4.Station\n"
                 << "5.Exit\n";
            while (!(cin >> option))
            {
                cout << "Error. Enter the correct choice" << endl << "Your choice: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            if (option <1 || option >5) cout << "Error. Enter the correct choice" << endl;

        }while(option < 1 |option > 5);

        switch (option) {
            case EnterM: {
                EnterKV(Main);
                break;
            }
            case ShowAll: {
                break;
            }
            case Show: {
                ShowByKey(Main);
                break;
            }
            case Stat: {
                SearchByStation(Main);
                break;
            }
            case ExitM: {
                cout << "Bye!\n";
                cin.ignore().get();
                exit(0);
            }
        }
    }
}

void EnterKV(Collection<char*, Train*>& Main) {
    cin.ignore();
    cout << "Enter number of train:";
    char* Num = Enter();

    cout << "Enter station:";
    char* Station = Enter();

    cout << "Enter time:";
    char* Time = Enter();

    Train *train = new Train(Num, Station, Time);


    Main.AddEl(Num, train);
}

void ShowByKey(Collection<char*, Train*>& Main) {
    cin.ignore();
    cout << "Enter number of train:";
    char* newKey = Enter();

    Train** result;
    int count =0;
    result = Main.ShowByKey(newKey, count);
    if (result != nullptr)
        for (int i = 0; i < count; i++)
            cout << *(result[i]);
    else
        NotF();
}

void SearchByStation(Collection<char*, Train*>& Main) {
    cin.ignore();
    cout << "Enter station:";
    char* Stat = Enter();

    Train** result;
    int count =0;
    result = Main.SearchByStation(Stat, count);
    if (result != nullptr)
        for (int i = 0; i < count; i++)
            cout << *(result[i]);
    else
        NotF();
}

void NotF()
{
    cout << "================================================================" << endl << endl;
    cout << " NOT FOUND" << endl;
    cout << "================================================================" << endl << endl;
}

char* Enter()
{
    char buff[255];
    cin.getline(buff, 255);
    char* newChar = new char[strlen(buff)+1];
    strcpy(newChar, buff);
    return newChar;
}