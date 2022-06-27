#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyCLL
{
public:
    struct node<T> *Head;
    struct node<T> *Tail;
    int CountNode = 0;

public:
    DoublyCLL();
    // Declaration of function
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(T);
    int Count();
    void Display();
};

// Defination of Function
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    CountNode = 0;
}
template <class T>
void DoublyCLL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (CountNode == 0) // we can write (if(Head == Null)||(Tail == Null))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    CountNode++;
}
template <class T>
void DoublyCLL<T>::InsertLast(T iNo)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (CountNode == 0) // we can write (if(Head == Null)||(Tail == Null))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;

        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    CountNode++;
}
template <class T>
void DoublyCLL<T>::InsertAtPos(T iNo, T iPos)
{
    if ((iPos < 1) || (iPos > CountNode + 1))
    {
        cout << "Invalid position\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == CountNode + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node<T> *newn = NULL;
        newn = new node<T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        struct node<T> *temp = Head;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        CountNode++;
    }
}
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if (CountNode == 0)
    {
        return;
    }
    else if (CountNode == 1)
    {
        delete Head; // we can also write tail as head and tail contain same 100
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next; // we can also write delete Head->prev;
    }
    Tail->next = Head;
    Head->prev = Tail;
    CountNode--;
}
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if (CountNode == 0)
    {
        return;
    }
    else if (CountNode == 1)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Tail->next; //// we can also write delete Head->prev;
    }
    Tail->next = Head;
    Head->prev = Tail;
    CountNode--;
}
template <class T>
void DoublyCLL<T>::DeleteAtPos(T iPos)
{
    if ((iPos < 1) || (iPos > CountNode))
    {
        cout << "Invalid position\n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == CountNode)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = Head;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        CountNode--;
    }
}
template <class T>
void DoublyCLL<T>::Display()
{
    int i = 0;
    struct node<T> *temp = Head;

    for (i = 1; i <= CountNode; i++)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "\n";
}
template <class T>
int DoublyCLL<T>::Count()
{
    return CountNode;
}
int main()
{
    DoublyCLL<int> obj1;
    DoublyCLL<char> obj2;
    DoublyCLL<float> obj3;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertAtPos(75, 3);
    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.DeleteAtPos(3);
    obj1.Display();
    int iRet = obj1.Count();
    cout << "Number of nodes are : " << iRet << endl;

    obj2.InsertFirst('A');
    obj2.InsertFirst('B');
    obj2.InsertFirst('C');
    obj2.InsertLast('D');
    obj2.InsertAtPos('E',3);
    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.DeleteAtPos(3);
    obj2.Display();
    char cRet = obj2.Count();
    cout << "Number of nodes are : " << iRet << endl;

    obj3.InsertFirst(10.11);
    obj3.InsertFirst(21.21);
    obj3.InsertFirst(31.31);
    obj3.InsertLast(51.11);
    obj3.InsertAtPos(75.15,3);
    obj3.DeleteFirst();
    obj3.DeleteLast();
    obj3.DeleteAtPos(3);
    obj3.Display();
    float fRet = obj3.Count();
    cout << "Number of nodes are : " << iRet << endl;
    return 0;
}