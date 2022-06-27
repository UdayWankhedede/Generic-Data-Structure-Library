#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
public:
    struct node<T> *Head;
    int Count;

    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(T);
    void Display();
    int CountNode();
    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int Frequency(T);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, T Pos)
{
    int Size = 0, iCnt = 0;
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;

    Size = Count;
    if ((Pos < 1) || (Pos > (Size + 1)))
    {
        return;
    }
    else if (Pos == 1)
    {
        InsertFirst(no);
    }
    else if (Pos == (Size + 1))
    {
        InsertLast(no);
    }
    else
    {
        newn = NULL;
        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;
        temp = Head;
        for (iCnt = 1; iCnt < Pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> *temp = Head;
    if (Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head->next;
        delete (temp);
    }
    Count--;
}
template <class T>
void SinglyLL<T>::DeleteLast()
{

    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp1 = Head;
        struct node<T> *temp2 = NULL;

        while (temp1->next->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = NULL;
        delete (temp2);
    }
    Count--;
}
template <class T>
void SinglyLL<T>::DeleteAtPos(T Pos)
{
    int Size = 0;
    int iCnt = 0;

    Size = Count;

    if ((Pos < 1) || Pos > (Size + 1))
    {
        return;
    }
    else if (Pos == 1)
    {
        DeleteFirst();
    }
    else if (Pos == (Size))
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp1 = Head;
        struct node<T> *temp2 = NULL;

        for (iCnt = 1; iCnt < (Pos - 2); iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete (temp2);
    }
    Count--;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout << "Elements from Linked list are : " << endl;
    struct node<T> *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template <class T>
int SinglyLL<T>::SearchFirstOcc(T No)
{
    int iCnt = 0;

    while (Head != NULL)
    {
        iCnt++;
        if (Head->data == No)
        {
            break;
        }
        Head = Head->next;
    }
    return iCnt;
}

template <class T>
int SinglyLL<T>::SearchLastOcc(T No)
{
    int iCnt = 0;
    int temp = 0;

    while (Head != NULL)
    {
        iCnt++;
        if (Head->data == No)
        {
            temp = iCnt;
        }
        Head = Head->next;
    }
    if (iCnt == 0)
    {
        return iCnt;
    }
    else
    {
        return temp;
    }
}
template <class T>
int SinglyLL<T>::Frequency(T No)
{
    int iCnt = 0;
    while (Head != NULL)
    {
        if(Head->data == No)
        {
            iCnt++;
        }
        Head = Head->next;
    }
    return iCnt;
}
int main()
{
    int iRet = 0;
    int fRet = 0;
    // int iValue = 0;
    // cout<<"Entre the value to search"<<endl;
    // cin>>iValue>>endl;

    SinglyLL<int> obj1;
    SinglyLL<float> obj2;
    // SinglyLL<char> obj3;
    // obj1.InsertFirst(21);
    // obj1.InsertFirst(11);
    // obj1.InsertAtPos(75, 3);
    // obj1.InsertLast(51);
    // obj1.InsertLast(51);
    // obj1.InsertLast(101);
    // obj1.Display();
    // // iRet = obj1.SearchFirstOcc(51);
    // // cout << "Data at :" << iRet << endl;
    // cout << "Number of nodes are : " << obj1.CountNode() << endl;

    // iRet = obj1.SearchLastOcc(51);
    // cout << "Data at :" << iRet << endl;

    obj2.InsertFirst(21.11);
    obj2.InsertFirst(11.11);
    obj2.InsertLast(51.11);
    obj2.InsertLast(101.11);
    obj2.InsertFirst(51.11);
    obj2.InsertFirst(51.11);
    obj2.InsertAtPos(75.5, 3);
    obj2.Display();
    cout << "Number of nodes are : " << obj2.CountNode() << endl;

    // iRet = obj2.SearchLastOcc(51.11);
    // cout << "Data at :" << iRet << endl;
    fRet = obj2.Frequency(51.11);
    cout << "Frequency is :" << fRet << endl;


    // obj3.InsertFirst('A');
    // obj3.InsertFirst('B');
    // obj3.InsertLast('C');
    // obj3.InsertLast('D');
    // obj3.InsertAtPos('U', 3);
    // obj3.Display();
    // cout << "Number of nodes are : " << obj2.CountNode() << endl;
    return 0;
}