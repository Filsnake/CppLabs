#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

union Union
{
    int Int;
    float Float;
    bool Bool;
};

enum UnionChoice { AddInt = 1, AddFloat, AddBool};
enum MainMChoice { AddStr = 1, ShowStr ,ChooseStr, ToString, Exit};
enum StrMenu { AddCont =1 , AddElem, MoveIn, MoveOut, StrExit};

class BaseClass
{
public:
    virtual bool Equals(BaseClass *BASE) = 0;
    virtual void ToString(char* buffer, int &i) = 0;
    virtual int getType() = 0;
    virtual ~BaseClass() {}
};

class Element : public BaseClass
{
    struct ElemUn
    {
        UnionChoice Choice;
        Union DATA_Union;
    };
    ElemUn elemUn;
public:
    void setInt(Union i)
    {
        elemUn.DATA_Union = i;
        elemUn.Choice = UnionChoice ::AddInt;
    }
    void setFloat(Union i)
    {
        elemUn.DATA_Union =i;
        elemUn.Choice = UnionChoice ::AddFloat;
    }
    void setBool(Union i)
    {
        elemUn.DATA_Union =i;
        elemUn.Choice = UnionChoice ::AddBool;
    }
    bool Equals(BaseClass *Base)
    {
        Element *New = (Element*)Base;
        if(this->elemUn.Choice != New->elemUn.Choice) {
            return false;
        }
        else
        {
            if(this->elemUn.Choice == AddInt)
            {
                if(this->elemUn.DATA_Union.Int != New->elemUn.DATA_Union.Int)
                    return false;
                else
                    return true;
            }
            if(this->elemUn.Choice == AddFloat)
            {
                if(this->elemUn.DATA_Union.Float != New->elemUn.DATA_Union.Float)
                    return false;
                else
                    return true;
            }
            if(this->elemUn.Choice == AddBool)
            {
                if(this->elemUn.DATA_Union.Bool != New->elemUn.DATA_Union.Bool) {
                    return false;
                }
                else
                    return true;
            }
        }
    }
    void ToString(char* buffer, int &i)
    {
        if(elemUn.Choice == UnionChoice::AddInt)
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
        if(elemUn.Choice == UnionChoice::AddFloat)
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
        if(elemUn.Choice == UnionChoice::AddBool)
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

class Queue : public BaseClass
{
    int maxLen = 10;
    BaseClass** Arr = new BaseClass*[maxLen];
    int Beg, End;
    Queue *Parent = nullptr;
public:
    Queue()
    {
        Beg = End = 0;
    }
    void AddQueue(Queue*& queue)
    {
        if(End == maxLen)
        {
            int newmax = maxLen *2;
            BaseClass** NewArr = new BaseClass*[newmax];
            for(int i=0;i < maxLen;i++)
                NewArr[i] = Arr[i];
            delete Arr;
            Arr = NewArr;
            maxLen = newmax;
        }
        Arr[End++] = queue;
    }
    void AddElem(Element*& element)
    {
        if(End == maxLen)
        {
            int newmax = maxLen *2;
            BaseClass** NewArr = new BaseClass*[newmax];
            for(int i=0;i < maxLen;i++)
                NewArr[i] = Arr[i];
            delete Arr;
            Arr = NewArr;
            maxLen = newmax;
        }
        Arr[End++] = element;
    }

    Queue** Search(int &count)
    {
        Queue** MoveIn = new Queue*[End];
        for(int i=Beg;i<End;i++){
            if(Arr[i]->getType() == 0) {
                MoveIn[count] = (Queue*)Arr[i];
                count++;
            }
        }
        if(count != 0)
            return MoveIn;
        else
            return nullptr;
    }
    Queue* MoveIN(Queue **MoveIn, int option)
    {
        MoveIn[option]->Parent = this;
        return MoveIn[option];
    }

    Queue* MoveOUT()
    {
        if(this->Parent == nullptr)
            return nullptr;
        return this->Parent;
    }

    bool Equals(BaseClass * BASE)
    {
        Queue *New = (Queue*)BASE;
        if(this->End != New->End)
        {
            return false;
        }
        else {
            for (int x = 0; x < this->End; x++)
            {
                if (this->Arr[x]->getType() == New->Arr[x]->getType()) {
                    if (this->Arr[x]->getType() == 0)
                    {
                        if(this->Arr[x]->Equals(New->Arr[x]) == false) {
                            return false;
                        }
                    }
                    else {
                        if(this->Arr[x]->Equals(New->Arr[x])==false) {
                            return false;
                        }
                    }
                }
                else
                    return false;
            }
            return true;
        }

    }
    void ToString(char* buffer, int& i)
    {
        buffer[i] = '[';
        i++;
        for(int j=Beg;j < End;j++)
        {
            if(j!=Beg) {
                buffer[i] = ',';
                i++;
            }
            if(Arr[j]->getType())
            {
                Arr[j]->ToString(buffer, i);
            }
            else
            {
                Arr[j]->ToString(buffer, i);
            }
        }
        buffer[i] = ']';
        i++;
    }
    int getType() { return 0; }
    ~Queue()
    {
        delete[] Arr;
        delete Parent;
    }
};

struct Root
{
    int countR =0;
    int maxR =2;
    BaseClass** Root = new BaseClass*[maxR];
    ~Root()
    {
        delete[] Root;
    }
};

void Main_Menu(Root &Root);
void Menu(Queue* Main, Root &ROOT);
void MenuTypeOfElem(Queue*& Main);
void ChooseToMoveIn(Queue*& Main, Root &ROOT);
void MenuOfChoice(Queue*& Main, Queue **Container, int count, Root &ROOT);
void ShowStructure(Root &ROOT);
void ChooseOfStr(Root &ROOT);
void ToStringFunc(Root &ROOT);
void CheckOutPut();
void ResultOutput(char *buffer, int length);;
int EnterInt();
float EnterFloat();
bool EnterBool();


int main()
{
    Root ROOT;
    Main_Menu(ROOT);
}

void Main_Menu(Root &ROOT)
{
    bool Run = true;
    while (Run)
    {
        int Option = AddStr;
        do {
            cout << "1.Add new structure" << endl
                 << "2.Show structures" << endl
                 << "3.Choose structure" << endl
                 << "4.ToString" << endl
                 << "5.Exit" << endl
                 << "Your choice: " << endl;
            while (!(cin >> Option))
            {
                cout << "Error. Enter the correct choice" << endl << "Your choice: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            if (Option <0 || Option >5) cout << "Error. Enter the correct choice" << endl;

        } while (Option < 0 || Option >5);

        switch (Option) {
            case AddStr: {
                Queue *NewQ = new Queue;
                if(ROOT.countR == ROOT.maxR)
                {
                    int newmax= ROOT.maxR * 2;
                    BaseClass** NewRoot = new BaseClass*[newmax];
                    for(int i=0;i<ROOT.maxR;i++)
                        NewRoot[i]=ROOT.Root[i];
                    delete[] ROOT.Root;
                    ROOT.maxR = newmax;
                    ROOT.Root = NewRoot;
                }
                ROOT.Root[ROOT.countR++] = NewQ;
                Menu(NewQ, ROOT);
                break;
            }
            case ShowStr:
            {
                if (ROOT.countR != 0) {
                    ShowStructure(ROOT);
                } else {
                    cout << "No1Str\n\n";
                    Main_Menu(ROOT);
                }
                break;
            }
            case ChooseStr: {
                if (ROOT.countR != 0) {
                    ChooseOfStr(ROOT);
                } else {
                    cout << "No1Str\n\n";
                    Main_Menu(ROOT);
                }
                break;
            }
            case ToString:
            {
                ToStringFunc(ROOT);
                Main_Menu(ROOT);
                break;
            }
            case Exit: {
                cout << "Bye!\n";
                cin.ignore().get();
                exit(0);
            }
        }

    }
}

void Menu(Queue* Main, Root &ROOT)
{
    int Option = AddCont;
    bool Run =true;
    while(Run)
    {
        do
        {
            cout << "1.Add container" << endl
                 << "2.Add Element" << endl
                 << "3.MoveIn" << endl
                 << "4.MoveOUT" << endl
                 << "5.Exit" << endl
                 << "Your choice: " << endl;
            while (!(cin >> Option))
            {
                cout << "Error. Enter the correct choice" << endl << "Your choice: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            if (Option <0 || Option >5) cout << "Error. Enter the correct choice" << endl;
        } while (Option < 0 || Option >5);

        switch (Option) {
            case AddCont: {
                Queue *NewQ = new Queue;
                Main->AddQueue(NewQ);
                break;
            }
            case AddElem: {
                MenuTypeOfElem(Main);
                break;
            }
            case MoveIn: {
                ChooseToMoveIn(Main, ROOT);
                break;
            }
            case MoveOut: {
                Queue *MoveOut = Main->MoveOUT();
                if (MoveOut != nullptr)
                    Menu(MoveOut, ROOT);
                else {
                    cout << "Now u in the main container!\n\n";
                }
                break;
            }
            case StrExit: {
                Main_Menu(ROOT);
            }
        }
    }
}

void ShowStructure(Root &ROOT)
{
    int i = 0;
    char *buffer = new char[255];
    for (; i < ROOT.countR; i++) {
        int score = 0;
        cout << i << ": ";
        ROOT.Root[i]->ToString(buffer, score);
        for (int j = 0; j < score; j++)
            cout << buffer[j];
        cout << endl << endl;
    }
    delete[] buffer;
}

void ChooseOfStr(Root &ROOT)
{
    int i = 0;
    char *buffer = new char[255];
    for (; i < ROOT.countR; i++) {
        int score = 0;
        cout << i << ": ";
        ROOT.Root[i]->ToString(buffer, score);
        for (int j = 0; j < score; j++)
            cout << buffer[j];
        cout << endl << endl;
    }
    delete[] buffer;

    bool run= true;
    while(run)
    {
        int option;
        do {
            cout << "Your Choice:";
            while (!(cin >> option))
            {
                cout << "Error. Enter the correct choice" << endl << "Your choice: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            if (option <0 || option >i) cout << "Error. Enter the correct choice" << endl;

        } while (option < 0 || option >i);

        switch (option)
        {
            default:
                Menu((Queue*)ROOT.Root[option], ROOT);
                break;
        }
    }
}

void ToStringFunc(Root &ROOT)
{
    CheckOutPut();
    char *buffer = new char[255];
    int score;
    for(int j=0;j<ROOT.countR;j++) {
        score =0;
        score=sprintf(buffer, "%d", j);
        buffer[score++] = ':';
        ROOT.Root[j]->ToString(buffer, score);
        buffer[score++] = '\n';
        buffer[score++] = '\n';
        ResultOutput(buffer, score);
    }
    if(ROOT.countR >= 2) {
        for (int i = 0; i < ROOT.countR -1 ; i++)
        {
            for(int j=i+1;j< ROOT.countR;j++) {
                if (ROOT.Root[i]->Equals(ROOT.Root[j]) == true)
                {
                    int cn;
                    char* buff = new char[255];

                    score=0;
                    score=sprintf(buffer, "%d", i);
                    buffer[score++] = '=';

                    cn = sprintf(buff, "%d", j);

                    for(int i=0;i<cn;i++)
                        buffer[score++]=buff[i];

                    buffer[score++] = '\n';
                    ResultOutput(buffer, score);
                    delete[] buff;
                }
                else
                {
                    int cn;
                    char* buff = new char[255];

                    score=0;
                    score=sprintf(buffer, "%d", i);
                    buffer[score++] = '!';
                    buffer[score++] = '=';

                    cn = sprintf(buff, "%d", j);

                    for(int i=0;i<cn;i++)
                        buffer[score++]=buff[i];

                    buffer[score++] = '\n';
                    ResultOutput(buffer, score);
                    delete[] buff;
                }
            }
        }
    }
}

void MenuTypeOfElem(Queue*& Main)
{
    UnionChoice Un;
    int option =AddInt;
    do{
        cout << "1.Add Int" << endl
             << "2.Add Float" << endl
             << "3.Add Bool" << endl
             << "4.Exit" << endl
             << "Your choice: " << endl;

        while (!(cin >> option)) {
            cout << "Error. Enter the correct choice" << endl << "Your choice: ";
            cin.clear();
            while (cin.get() != '\n');
        }
    }while(option <1 || option > 4);

    switch (option) {
        case AddInt:
            Un = UnionChoice ::AddInt;
            break;
        case AddFloat:
            Un= UnionChoice ::AddFloat;
            break;
        case AddBool:
            Un= UnionChoice ::AddBool;
            break;
        case 4:
            return;
    }

    Union i;
    Element *NewElement = new Element;
    if(Un == UnionChoice::AddInt)
    {
        i.Int = EnterInt();
        NewElement->setInt(i);
        Main->AddElem(NewElement);
        return;
    }
    if(Un == UnionChoice::AddFloat)
    {
        i.Float=EnterFloat();
        NewElement->setFloat(i);
        Main->AddElem(NewElement);
        return;
    }
    if(Un == UnionChoice::AddBool)
    {
        i.Bool=EnterBool();
        NewElement->setBool(i);
        Main->AddElem(NewElement);
        return;
    }
}

void ChooseToMoveIn(Queue*& Main, Root &ROOT)
{
    int count=0;
    Queue **MoveIn = Main->Search(count);
    if(MoveIn != nullptr) {
        if (count == 1)
            Menu(Main->MoveIN(MoveIn, 0), ROOT);
        else
        {
            int secondCount;
            char* show = new char[255];
            for(int i=0;i < count;i++)
            {
                secondCount = 0;
                MoveIn[i]->ToString(show, secondCount);
                cout << i+1 << ":";
                for(int j=0;j < secondCount;j++)
                    cout << show[j];
                cout << "\n\n";
            }
            delete[] show;
            MenuOfChoice(Main, MoveIn, count, ROOT);
        }
    }
    else
        cout << "Not Found\n";
    Menu(Main, ROOT);
}

void MenuOfChoice(Queue*& Main, Queue **Container, int count, Root &ROOT)
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

    } while (option < 0 || option > count);

    do
    {
        switch (option)
        {
            case 0:
                Menu(Main, ROOT);
                break;
            default:
                --option;
                Menu(Main->MoveIN(Container, option), ROOT);
                break;
        }
    } while (option != 0);
}

void CheckOutPut()
{
    ofstream ofile("result.txt");
    if(ofile.is_open())
        ofile.close();
    remove("result.txt");
}

void ResultOutput(char *buffer, int length)
{
    ofstream ofile("result.txt", ios::app);
    for (int i = 0; i < (length); i++)
    {
        ofile << buffer[i];
    }
    ofile.close();
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
    int option =0;
    do{
        cout << "1: T\n";
        cout << "2: F\n";
        cin >> option;
    }while(option< 1|| option > 2);
    switch (option)
    {
        case 1:
        {
            Bool= true;
            break;
        }
        case 2:
        {
            Bool= false;
            break;
        }
    }
    return Bool;
}