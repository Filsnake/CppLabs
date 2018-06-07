#include <iostream>
#include <cstring>

using namespace std;

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
        TValue** y = new TValue*[Score];

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

};

char* Enter();

int main() {

    Collection<char, Train> coll;

    auto *x= Enter();

    auto *num = Enter();
    auto *stat = Enter();
    auto *time = Enter();


    auto *train = new Train(num,stat,time);

    coll.AddElem(x, train);

    auto *key = Enter();

    int count=0;

    auto **result = coll.Search(key, count);

    for(int i=0;i< count;i++)
        cout << *result[i];

    return 0;
}

char* Enter() {
    char buff[255];
    cin.getline(buff, 255);
    char* newChar = new char[strlen(buff)+1];
    strcpy(newChar, buff);
    return newChar;
}