#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

enum MainM { EnterM = 1, ShowAll, Show, Stat,ExitM};

char* Enter();

template <class TKey, class TValue>
class Collection{
    struct Key_Value {
        TKey* Key;
        TValue* Value;
    };
    struct ListElem {
        Key_Value *KeyValue;
        ListElem *Next;
        TKey* getKey() {
            TKey* newKey = KeyValue->Key;
            return newKey;
        }
        TValue* getValue() {
            TValue* newValue = KeyValue->Value;
            return newValue;
        }
    };
    ListElem *Begin = nullptr;
public:
    void AddElem(TKey*& tKey, TValue*& tValue) {
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
    template <typename T>
    TValue** Search(T tKey,int& count) {
        int Score = 0;
        ListElem *Scroll = Begin;
        while (Scroll)
        {
            Score++;
            Scroll = Scroll->Next;
        }

        ListElem *Search = Begin;
        TValue** y = new TValue*[Score];

        while (Search)
        {
            if(*Search->getKey() == *tKey) {
                y[count++] = Search->KeyValue->Value;
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
    TValue** Search(char* tKey,int& count) {
        int Score = 0;
        ListElem *Scroll = Begin;
        while (Scroll)
        {
            Score++;
            Scroll = Scroll->Next;
        }

        ListElem *Search = Begin;
        auto** y = new TValue*[Score];

        while (Search)
        {
            if(strcmp(Search->getKey(),tKey) == 0 ) {
                y[count++] = Search->KeyValue->Value;
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
    TValue** Search(int& count) {
        int Score = 0;
        ListElem *Scroll = Begin;
        while (Scroll)
        {
            Score++;
            Scroll = Scroll->Next;
        }

        ListElem *Search = Begin;
        auto** y = new TValue*[Score];

        while (Search)
        {
            y[count++] = Search->KeyValue->Value;
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
    friend istream& operator >> (istream& stream, Collection& collection) {
        cin.ignore();
        cout <<"Enter key:";
        auto *tKey= Enter();

        TValue *tValue;
        stream >> tValue;

        collection.AddElem(tKey, tValue);

        return stream;
    }
    friend ostream& operator << (ostream& stream, Collection& collection) {
        ListElem *Show = collection.Begin;
        while (Show) {
            stream  << *Show->getValue() << endl;
            Show = Show->Next;
        }
        return stream;
    }
};

class Train {
    char* Number;
    char* Station;
    char* Time;
public:
    Train(char* number, char* station, char* time);
    char* getNumber();
    char* getStation();
    char* getTime();
    void SaveFile(char* buff, int &i) {
        char* newBuff = new char[255];
        strcpy(newBuff,this->getNumber());
        for(int j=0;j < strlen(newBuff);i++, j++)
            buff[i] = newBuff[j];
        delete[] newBuff;
        buff[i++] = ' ';
    }
    friend ostream& operator << (ostream &stream, Train &train);
    friend Train& operator >> (istream& stream, Train*& train) {
        cout << "Enter num:";
        auto *num = Enter();
        cout << "Enter stat:";
        auto *stat = Enter();
        cout << "Enter time:";
        auto *time = Enter();

        train = new Train(num,stat,time);
        return *train;
    }
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

void MainMenu(Collection<char,Train>& Main);
void ShowByKey(Collection<char, Train>& Main);
void SearchByStation(Collection<char, Train>& Main);
void SaveF(Collection<char, Train>& Main);
void ResultOutput(char *buffer, int length);
void NotF();

int main() {

    Collection<char, Train> coll;
    MainMenu(coll);

    return 0;
}

void MainMenu(Collection<char,Train>& Main){
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
                cin >> Main;
                break;
            }
            case ShowAll: {
                cout << Main;
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
                SaveF(Main);
                cin.ignore().get();
                exit(0);
            }
        }
    }
}

void ShowByKey(Collection<char, Train>& Main) {
    cin.ignore();
    cout << "Enter number of train:";
    auto* newKey = Enter();

    int count =0;
    auto** result = Main.Search(newKey, count);
    if (result != nullptr)
        for (int i = 0; i < count; i++)
            cout << *(result[i]);
    else
        NotF();
}

void SearchByStation(Collection<char, Train>& Main) {
    cin.ignore();
    cout << "Enter station:";
    char* Stat = Enter();

    int count =0;
    auto** result = Main.Search(count);

    if (result != nullptr)
        for (int i = 0; i < count; i++)
            if(strcmp(result[i]->getStation(), Stat)==0)
                cout << *(result[i]);
    delete[] result;
}

void SaveF(Collection<char, Train>& Main) {
    char* buff= new char[255];
    int i=0;
    int count =0;
    auto** result = Main.Search(count);
    for(int j=0;j<count;j++)
        result[j]->SaveFile(buff, i);
    cout << buff;
    ResultOutput(buff, i);
}

void ResultOutput(char *buff, int i)
{
    ofstream ofile("result.txt", ios::app);
    for (int j = 0; j < i; j++)
    {
        ofile << buffer[j];
    }
    ofile.close();
}

void NotF() {
    cout << "================================================================" << endl << endl;
    cout << " NOT FOUND" << endl;
    cout << "================================================================" << endl << endl;
}

char* Enter() {
    char buff[255];
    cin.getline(buff, 255);
    auto* newChar = new char[strlen(buff)+1];
    strcpy(newChar, buff);
    return newChar;
}