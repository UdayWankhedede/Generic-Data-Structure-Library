#include <iostream>
using namespace std;

// Generic SinglyCLL
template <class T>
struct node
{
    T data;
    struct node *next;
};
template <class T>
class SinglyCLL
{
public:
    struct node<T> *Head;
    struct node<T> *Tail;
    int Count = 0;

public:          // Behaviour
    SinglyCLL(); // Default constructor //Declaration
    // Function Declaration
    void InsertFirst(T); // here we declare function in class
    void InsertLast(T);  // as industrial way alway declare  function in class
    void InsertAtPos(T, T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(T);
    void Display();
    int CountNode();
};

// Function Defination
// to know this is class function we add class name and ::

template <class T>
SinglyCLL<T>::SinglyCLL() // Default constructor //Defination
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = Head;
    newn = new node<T>; // Memory allocation
    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) // if LL is Empty
    {
        Head = newn;
        Tail = newn;
    }
    else // if LL contain atleast one node
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head; // always write this
    Count++;
}
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>; // Memory allocation

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) // if LL is Empty
    {
        Head = newn;
        Tail = newn;
    }
    else // if LL contain atleast one node
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head; // always write this

    Count++;
}
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, T Pos)
{
    int size = Count;

    if ((Pos < 1) || Pos > (size + 1))
    {
        return;
    }
    else if (Pos == 1)
    {
        InsertFirst(no);
    }
    else if (Pos == (size))
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn = NULL;
        struct node<T> *temp = Head;
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < Pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
        Tail->next = Head;
    }
    Count--;
}
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if (Head == NULL && Tail == NULL) // LL contain 0 node
    {
        return;
    }
    else if (Head == Tail) // LL contain 1 node
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else // LL contain more than 1 Node
    {
        struct node<T> *temp = Head;
        while ((temp->next) != Tail )
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = Head;
    }
    Count--;
}
template <class T>
void SinglyCLL<T>::DeleteAtPos(T Pos)
{
    int size = Count;
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Pos == 1)
    {
        DeleteFirst();
    }
    else if (Pos == size)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp1 = Head;
        int iCnt = 0;
        for (iCnt = 1; iCnt < Pos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        struct node<T> *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    Count--;
}
template <class T>
void SinglyCLL<T>::Display()
{
    struct node<T> *temp = Head;
    if ((Head == NULL) && (Tail == NULL)) // if LL is empty
    {
        return;
    }
    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    } while (temp != Head); // we can write Tail -> next also replace with head
    cout << endl;
}
template <class T>
int SinglyCLL<T>::CountNode()
{
    return Count;
}

int main()
{
    int iRet = 0;
    SinglyCLL<int> obj1;
    SinglyCLL<float> obj2;
    SinglyCLL<char> obj3;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertAtPos(75, 3);
    //obj1.DeleteFirst();
    obj1.DeleteLast();
    //obj1.DeleteAtPos(3);
    obj1.Display();
    iRet = obj1.CountNode();
    cout << "Number of nodes are : " << iRet << endl;

    obj2.InsertFirst(51.51);
    obj2.InsertFirst(21.21);
    obj2.InsertFirst(11.1);
    obj2.InsertLast(101.12);
    obj2.InsertLast(111.13);
    obj2.InsertAtPos(75.55, 3);
    obj2.Display();
    iRet = obj2.CountNode();
    cout << "Number of nodes are : " << iRet << endl;

    obj3.InsertFirst('A');
    obj3.InsertFirst('F');
    obj3.InsertFirst('C');
    obj3.InsertLast('D');
    obj3.InsertLast('E');
    obj3.InsertAtPos('G', 3);
    obj3.Display();
    iRet = obj3.CountNode();
    cout << "Number of nodes are : " << iRet << endl;

    return 0;
}