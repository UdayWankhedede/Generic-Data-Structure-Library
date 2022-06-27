#include <iostream>
using namespace std;

template <class T>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyLL
{
public:
    struct node<T> *Head; // Characterstic
    int Count;

public:
    DoublyLL(); // Default constructor //Declaration
    // Function Declaration
    void InsertFirst(T); // here we declare function in class
    void InsertLast(T);  // as industrial way alway declare  function in class
    void InsertAtPos(T, T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(T);
    void Display();
    int CountNode();
    void FirstOccurance(T);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count = 0;
}
template <class T>
void DoublyLL<T>::Display()
{
    struct node<T> *temp = Head;
    if (Head == NULL) // if LL is empty
    {
        return;
    }
    while (temp != NULL)
    {
        printf("%c",temp->data);
       // cout << "|" << temp->data << "|->";
        temp = temp->next;
    } // we can write Tail -> next also replace with head
    cout << endl;
}
template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}
template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>; // Memory allocation

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL)) // if LL is Empty
    {
        Head = newn;
    }
    else // if LL contain atleast one node
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}
template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;

    newn = new node<T>; // Memory allocation

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL)) // if LL is Empty
    {
        Head = newn;
    }
    else // if LL contain atleast one node
    {
        temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}
template <class T>
void DoublyLL<T>::InsertAtPos(T no, T Pos)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    int size = 0;
    size = Count;

    if ((Pos < 1) || (Pos > (size + 1)))
    {
        return;
    }
    else if (Pos == 1)
    {
        InsertFirst(no);
    }
    else if (Pos == (size + 1))
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
        for (int iCnt = 1; iCnt <= (Pos - 2); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}
template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct node<T> *temp = Head;
    if (Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head->next;
        Head->prev = NULL;

        delete (temp);
    }
    Count--;
}
template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        struct node<T> *temp = Head;
        while ((temp->next) != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete (temp);
        Count--;
    }
}
template <class T>
void DoublyLL<T>::DeleteAtPos(T Pos)
{
    int Size = 0;
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
        int iCnt = 1;
        struct node<T> *temp = Head;
        for (iCnt = 1; iCnt <= Pos - 2; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
    Count--;
}

void FirstOccurance<T>::DoublyLL()
{

}

int main()
{
    int iRet = 0;
    DoublyLL<int> obj1;
    DoublyLL<float> obj2;
    DoublyLL<char> obj3;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertAtPos(75, 3);
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.DeleteAtPos(3);
    obj1.Display();
    iRet = obj1.CountNode();
    cout << "Number of nodes are : " << iRet << endl;

    obj2.InsertFirst(21.11);
    obj2.InsertFirst(11.11);
    obj2.InsertLast(51.11);
    obj2.InsertLast(101.11);

    obj2.Display();
    cout << "Number of nodes are : " << obj2.CountNode() << endl;

    obj3.InsertFirst('A');
    obj3.InsertFirst('B');
    obj3.InsertLast('C');
    obj3.InsertLast('D');
    obj3.Display();
    cout << "Number of nodes are :" << obj3.CountNode() << endl;

    return 0;
}