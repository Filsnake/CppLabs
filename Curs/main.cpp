#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>

using namespace std;

enum MainM { EnterM = 1, ShowAll, showByKey, Stat,ExitM};
enum Type {Char, numbers};
Type typeOfKey;


template <typename T>
T* EnterKey(T*& key);
char* EnterKey(char*& key);
char* Enter();

template <class TKey, class TValue>
class Collection {
    struct Key_Value{
        TKey *Key;
        TValue *Value;
    };
    struct  ListElem {
        Key_Value *KeyValue;
        ListElem *Next;
        TKey* getKey();
        TValue* getValue();
    };
    ListElem *Begin = nullptr;
public:
    void AddElem(TKey*& tKey, TValue*& tValue);
    void Search(TKey**& tKey,TValue**& tValue,TKey* key, int& count);
    void Search(TKey**& tKey,TValue**& tValue, int& count);
    template <class TKey2, class TValue2>
    friend ostream& operator << (ostream& stream, Collection<TKey2,TValue2>& collection);
};

template <class TKey, class TValue>
TKey* Collection<TKey, TValue>::ListElem::getKey() {
    return KeyValue->Key;
}

template <class TKey, class TValue>
TValue* Collection<TKey, TValue>::ListElem::getValue() {
    return KeyValue->Value;
}

template <class TKey, class TValue>
void Collection<TKey, TValue>::AddElem(TKey*& tKey, TValue*& tValue) {
    if(Begin == nullptr) {
        Begin = new ListElem;
        Begin->KeyValue= new Key_Value{tKey, tValue};
        Begin->Next = nullptr;
    }
    else {
        auto *Add = new ListElem;
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

template <class TKey, class TValue>
void Collection<TKey, TValue>::Search(TKey**& tKey,TValue**& tValue,TKey* key, int& count) {
    int Score = 0;
    ListElem *Scroll = Begin;
    while (Scroll)
    {
        Score++;
        Scroll = Scroll->Next;
    }
    
    ListElem *Search = Begin;
    tValue = new TValue*[Score];
    tKey = new TKey*[Score];
    
    while (Search)
    {
        if(*Search->getKey() == *key) {
            tKey[count] = Search->KeyValue->Key;
            tValue[count++] = Search->KeyValue->Value;
        }
        Search = Search->Next;
    }
    
    if (count == 0)
    {
        delete[] tValue;
        delete[] tKey;
    }
};

template <class TKey, class TValue>
void Collection<TKey, TValue>::Search(TKey**& tKey,TValue**& tValue,int& count) {
    int Score = 0;
    ListElem *Scroll = Begin;
    while (Scroll)
    {
        Score++;
        Scroll = Scroll->Next;
    }
    
    ListElem *Search = Begin;
    tValue = new TValue*[Score];
    tKey = new TKey*[Score];
    
    while (Search)
    {
        tKey[count] = Search->KeyValue->Key;
        tValue[count++] = Search->KeyValue->Value;
        Search = Search->Next;
    }
    
    if (count == 0)
    {
        delete[] tValue;
        delete[] tKey;
    }
};

template <class TKey, class TValue>
ostream& operator << (ostream& stream, Collection<TKey,TValue>& collection) {
    typename Collection<TKey,TValue>::ListElem *Show = collection.Begin;
    if (collection.Begin == nullptr)
    {
        stream << "================================================================" << endl << endl;
        stream << " EMPTY" << endl;
        stream << "================================================================" << endl << endl;
    }
    else
        while(Show) {
            switch (typeOfKey) {
                case Type::numbers: {
                    stream << "Number:" << *Show->getKey() << endl;
                    break;
                }
                case Type::Char: {
                    stream << "Number:" << Show->getKey() << endl;
                    break;
                }
            }
            stream << *Show->getValue() << endl;
            Show = Show->Next;
        }
    return stream;
}
////////////////////////////////////////////////////////////////////////////

class Train{
    char* Number;
    char* Station;
    char* Time;
public:
    Train();
    Train(char* number, char* station, char* time);
    char* getNumber();
    char* getStation();
    char *getTime();
    
    template <typename T>
    void SaveFile(T* numb,char* buff, int &i);
    
    friend Train& operator >> (istream& stream, Train& train);
    friend ostream& operator << (ostream &stream, Train &train);
    friend ifstream& operator >> (ifstream& stream, Train*& train);
    ~Train();
};

Train::Train() {
    Station = nullptr;
    Time = nullptr;
}

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

template <typename T>
void Train::SaveFile(T* numb,char* buff, int &i){
    auto* newBuff = new char[255];
    string str;
    
    switch (typeOfKey) {
        case Type::numbers: {
            str = to_string(*numb);
            break;
        }
        case Type::Char: {
            str = (char*)numb;
            break;
        }
    }
    stpcpy(newBuff, str.c_str());
    for(int j=0;j < strlen(newBuff);i++, j++)
        buff[i] = newBuff[j];
    buff[i++] = ',';
    
    strcpy(newBuff, this->getStation());
    for(int j=0;j < strlen(newBuff);i++, j++)
        buff[i] = newBuff[j];
    buff[i++] = ',';
    
    strcpy(newBuff, this->getTime());
    for(int j=0;j < strlen(newBuff);i++, j++)
        buff[i] = newBuff[j];
    delete[] newBuff;
    buff[i++] = '\n';
}

Train& operator >> (istream& stream, Train& train) {
    cout << "Enter stat:";
    char *stat = Enter();
    cout << "Enter time:";
    char *time = Enter();
    
    train.Station = stat;
    train.Time = time;
    
    return train;
}

ostream& operator << (ostream &stream, Train &train) {
    stream << "Station:" << train.getStation() << endl;
    stream << "Time:" << train.getTime() << endl;
    stream << "\n";
    return stream;
}

ifstream& operator >> (ifstream& stream, Train*& train) {
    
    auto *num= new char[255];
    auto *stat= new char[255];
    auto *time= new char[255];
    auto* newBuff = new char[255];
    stream.getline(newBuff, 255);
    if(stream.eof())
        return stream;
    int i=0;
    
    int k = 0;
    while (newBuff[i] != ',')
    {
        num[k++] = newBuff[i++];
    }
    num[k] = '\0';
    i++;
    
    int l = 0;
    while (newBuff[i] != ',')
    {
        stat[l++] = newBuff[i++];
    }
    stat[l] = '\0';
    i++;
    
    int y = 0;
    while (newBuff[i] != '\0')
    {
        time[y++] = newBuff[i++];
    }
    time[y] = '\0';
    
    train = new Train(num, stat,time);
    
    return stream;
}

Train::~Train() {
    delete Station;
    delete Time;
}
/////////////////////////////////////////////////////////////////////////////

template <class Key, class Value>
void MainMenu(Collection<Key,Value>& Main);

template <typename Key, class Value>
void ShowByKey(Collection<Key,Value>& Main);

template <typename Key, class Value>
void SearchByStation(Collection<Key,Value>& Main);

template <typename Key, class Value>
void LoadF(Collection<Key,Value>& Main);

template <typename Key, class Value>
void LoadFileNumb(Collection<Key,Value>& Main, Train* train);

template <typename Key, class Value>
void LoadFileChar(Collection<Key,Value>& Main, Train* train);

template <typename Key, class Value>
void SaveF(Collection<Key,Value>& Main);

void ResultOutput(char *buff, int i);
void NotF();

int main() {
    Collection <char, Train> Main;
    
    LoadF(Main);
    MainMenu(Main);
    return 0;
};

template <class Key, class Value>
void MainMenu(Collection<Key,Value>& Main) {
    bool run = true;
    int option = EnterM;
    
    while(run) {
        do {
            cout << "1.Enter\n"
                    << "2.Show All\n"
                       << "3.Show by key\n"
                          << "4.Show by station\n"
                             << "5.Save and Exit\n";
            while (!(cin >> option))
            {
                cout << "Error. Enter the correct choice\n" << "Your choice: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            if (option <1 || option >5) cout << "Error. Enter the correct choice\n";
        } while(option < 1 | option > 5);
        
        switch (option) {
            case EnterM: {
                cin.ignore();
                cout << "Enter key:";
                Key *key;
                EnterKey(key);
                Value *value = new Value;
                cin >> *value;
                Main.AddElem(key, value);
                break;
            }
            case ShowAll: {
                cout << Main;
                break;
            }
            case showByKey: {
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

template <typename Key, class Value>
void ShowByKey(Collection<Key,Value>& Main) {
    cin.ignore();
    cout << "Enter number of train:";
    Key* newKey;
    EnterKey(newKey);
    
    int count =0;
    Key** key;
    Train** value;
    Main.Search(key, value, newKey, count);
    if (count > 0)
        for (int i = 0; i < count; i++) {
            cout << "Number:" << *key[i] << endl;
            cout << *(value[i]);
        }
    else
        NotF();
}

template <typename Key, class Value>
void SearchByStation(Collection<Key,Value>& Main) {
    cin.ignore();
    cout << "Enter station:";
    char* Stat = Enter();
    
    int count =0;
    Key** key;
    Train** value;
    Main.Search(key, value, count);
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            if (strcmp(value[i]->getStation(), Stat) == 0) {
                cout << "Number:" << *key[i] << endl;
                cout << *value[i];
            }
        }
    }
    delete[] key;
    delete[] value;
}

template <typename Key, class Value>
void LoadF(Collection<Key,Value>& Main) {
    ifstream file("result.txt");
    if(file.is_open()) {
        while(true)
        {
            Train *train;
            file >> train;
            if(file.eof())
                break;
            
            Key* key = train->getNumber();
            Main.AddElem(key, train);
        }
        
    }
    
}


template <typename Key, class Value>
void SaveF(Collection<Key,Value>& Main) {
    auto *buff = new char[255];
    int i = 0;
    int count = 0;
    
    Key **key;
    Train **value;
    Main.Search(key, value, count);
    for (int j = 0; j < count; j++) {
        value[j]->SaveFile(key[j], buff, i);
    }
    ResultOutput(buff, i);
}

void ResultOutput(char *buff, int i) {
    ofstream file("result.txt");
    for (int j = 0; j < i; j++)
    {
        file << buff[j];
    }
    file.close();
}

void NotF() {
    cout << "================================================================" << endl << endl;
    cout << " NOT FOUND" << endl;
    cout << "================================================================" << endl << endl;
}

char* EnterKey(char*& key) {
    char buff[255];
    cin.getline(buff, 255);
    key = new char[strlen(buff)+1];
    strcpy(key, buff);
    typeOfKey = Char;
    return key;
}

template <typename T>
T* EnterKey(T*& key) {
    key = new T;
    cin >> *key;
    typeOfKey = numbers;
    cin.ignore();
    return key;
}

char* Enter() {
    char buff[255];
    cin.getline(buff, 255);
    char *newBuff = new char[strlen(buff)+1];
    strcpy(newBuff, buff);
    return newBuff;
}