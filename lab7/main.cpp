#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

union Union
{
    int Int;
    float Float;
    bool Bool;
};

enum UnionChoise { AddInt = 1, AddFloat, AddBool};

class BaseClass
{
public:
    virtual bool Equals(BaseClass *BASE) = 0;
    virtual void ToString(char* buffer, int &i) = 0;
    virtual int getType()=0;
    virtual ~BaseClass()
    {
        delete this;
    }
};

class ELement :public BaseClass
{
    struct ElemUn {
        UnionChoise Chiose;
        Union DATA_Union;
    };
    ElemUn elemUn;
public:
    void setInt(Union i)
    {
        elemUn.DATA_Union = i;
        elemUn.Chiose = UnionChoise ::AddInt;
    }
    void setFloat(Union i)
    {
        elemUn.DATA_Union =i;
        elemUn.Chiose = UnionChoise ::AddFloat;
    }
    void setBool(Union i)
    {
        elemUn.DATA_Union =i;
        elemUn.Chiose = UnionChoise ::AddBool;
    }

    bool Equals(BaseClass *BASE)
    {
        cout << "Equal" << endl;
    }
    void ToString(char* buffer, int &i)
    {
        if(elemUn.Chiose == UnionChoise::AddInt)
        {
            char* newbuff = new char[255];
            sprintf(newbuff, "%d", elemUn.DATA_Union.Int);
            for(int j=0;j< strlen(newbuff);j++,i++)
            {
                buffer[i] =newbuff[j];
            }
            delete[] newbuff;
            return;
        }
        if(elemUn.Chiose == UnionChoise::AddFloat)
        {
            char* newbuff = new char[255];
            sprintf(newbuff, "%0.1f", elemUn.DATA_Union.Float);

            for(int j=0;j< strlen(newbuff);j++,i++)
            {
                buffer[i] =newbuff[j];
            }
            delete[] newbuff;
            return;
        }
        if(elemUn.Chiose == UnionChoise::AddBool)
        {
            if(elemUn.DATA_Union.Bool == true)
            {
                buffer[i] = 'T';
                i++;
                buffer[i] = 'R';
                i++;
                buffer[i] = 'U';
                i++;
                buffer[i] = 'E';
                i++;
            }
            else
            {
                buffer[i] = 'F';
                i++;
                buffer[i] = 'A';
                i++;
                buffer[i] = 'L';
                i++;
                buffer[i] = 'S';
                i++;
                buffer[i] = 'E';
                i++;
            }
            return;
        }
    }

    int getType() { return 1; }
};

class Container : public BaseClass
{
    int Score =0;
    int MaxLen =10;
    BaseClass** Array = new BaseClass*[MaxLen];
    Container *parrent = nullptr;
public:
    void AddContainer()
    {
        Container *NewContainer = new Container;
        if(Score != MaxLen)
        {
            Array[Score] = NewContainer;
            Score++;
        }
    }
    void AddElement(UnionChoise x, Union i)
    {
        ELement *NewElement = new ELement;
        if(Score != MaxLen)
        {
            if(x == UnionChoise::AddInt)
                NewElement->setInt(i);
            if(x == UnionChoise::AddFloat)
                NewElement->setFloat(i);
            if(x == UnionChoise::AddBool)
                NewElement->setBool(i);
            Array[Score] = NewElement;
            Score++;
        }
    }

    Container* MoveIn()
    {
        for(int i=0;i<Score;i++) {
            if(Array[i]->getType() == 0) {
                Container *MoveIn = (Container*)Array[i];
                MoveIn->parrent = this;
                return  MoveIn;
            }
        }
    }

    Container* MoveOUT()
    {
        if(this->parrent == nullptr)
            return nullptr;
        return this->parrent;
    }

    bool Equals(BaseClass *BASE)
    {
        cout << "Equal" << endl;
    }
    void ToString(char* buffer, int &i)
    {
        buffer[i] = '[';
        i++;
        for(int j=0;j<Score;j++)
        {
            if(j!=0) {
                buffer[i] = ',';
                i++;
            }
            if(Array[j]->getType())
            {
                Array[j]->ToString(buffer, i);
            }
            else
            {
                Array[j]->ToString(buffer, i);
            }
        }

        buffer[i] = ']';
        i++;
    }

    int getType() { return 0; }
};

void Menu(Container *Main);
void MenuElement(Container *Main);
int EnterInt();
float EnterFloat();
bool EnterBool();
void fileOutput(char* buffer, int i);


int main()
{
    Container *Main = new Container;
    Menu(Main);
}


void Menu(Container *Main)
{
    int option =0;

    do{
        cout << "1.Add container" << endl
             << "2.Add ELement" << endl
             << "3.ToString" << endl
             << "4.MoveIn" << endl
             << "5.MoveOUT" << endl
             << "6.Exit" << endl
             << "Your choise: " << endl;

        while (!(cin >> option)) {
            cout << "Error. Enter the correct choice" << endl << "Your choice: ";
            cin.clear();
            while (cin.get() != '\n');
        }
    }while(option <1 || option > 6);

    do {
        switch (option) {
            case 1: {
                Main->AddContainer();
                Menu(Main);
                break;
            }
            case 2: {
                MenuElement(Main);
                Menu(Main);
                break;
            }
            case 3: {
                char *buffer = new char[255];
                int i = 0;
                Main->ToString(buffer, i);
                fileOutput(buffer, i);
                Menu(Main);
                break;
            }
            case 4: {
                Container *MoveIn = Main->MoveIn();
                Menu(MoveIn);
                break;
            }
            case 5: {
                Container *MoveOut = Main->MoveOUT();
                if(MoveOut != nullptr)
                    Menu(MoveOut);
                else {
                    cout << "Above only heaven!" << endl << endl;
                    Menu(Main);
                }
                break;
            }
            case 6: {
                cout << "Bye!" << endl;
                delete[] Main;
                cin.ignore().get();
                exit(0);
            }
        }
    }while(option!=6);

}

void fileOutput(char* buffer, int length)
{
    ofstream ofile("result.txt");
    for (int i = 0; i < (length); i++)
    {
        ofile << buffer[i];
    }
    ofile.close();
}

void MenuElement(Container *Main)
{
    UnionChoise Un;
    int option =AddInt;
    do{
        cout << "1.Add Int" << endl
             << "2.Add Float" << endl
             << "3.Add Bool" << endl
             << "4.Exit" << endl
             << "Your choise: " << endl;

        while (!(cin >> option)) {
            cout << "Error. Enter the correct choice" << endl << "Your choice: ";
            cin.clear();
            while (cin.get() != '\n');
        }
    }while(option <1 || option > 4);

        switch (option) {
            case AddInt:
                Un = UnionChoise ::AddInt;
                break;
            case AddFloat:
                Un= UnionChoise ::AddFloat;
                break;
            case AddBool:
                Un= UnionChoise ::AddBool;
                break;
            case 4:
                return;
        }

    Union i;

    if(Un == UnionChoise::AddInt)
    {
        i.Int = EnterInt();
        Main->AddElement(Un,i);
        return;
    }
    if(Un == UnionChoise::AddFloat)
    {
        i.Float=EnterFloat();
        Main->AddElement(Un,i);
        return;
    }
    if(Un == UnionChoise::AddBool)
    {
        i.Bool=EnterBool();
        Main->AddElement(Un,i);
        return;
    }
}

int EnterInt()
{
    int Int;
    cin >> Int;
    return Int;
}

float EnterFloat()
{
    float Float;
    cin >> Float;
    return Float;
}

bool EnterBool()
{
    bool Bool;
    Bool = true;
    return Bool;
}