#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
struct node
{
    T data;
    struct node *next;
};

//typedef struct node NODE;
//typedef struct node * PNODE;
//typedef struct node ** PPNODE;

template <class T>
class SinglyLL
{
    public:
        // Characteristics
        struct node <T>* First;

        // Behaviours
        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no ,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int Count();

};

/*
Return_Value Class_Name :: Function_Name(Parameters)
{

}
*/
template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    // Step1 : Allocate memory for node
    struct node <T>* newn = new struct node <T>;

    // Step2 : Initialise node
    newn->data = no;
    newn->next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
    }
    else    // If LL contains atleast one node
    {
        newn->next = First;
        First = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    // Step1 : Allocate memory for node
    struct node <T>* newn = new struct node <T>;

    // Step2 : Initialise node
    newn->data = no;
    newn->next =  NULL;

    // Step3 : Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
    }
    else    // If LL contains atleast one node
    {
        struct node <T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertAtPosition(T no, int ipos)
{
    int iCount=0;
    iCount=Count();
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
         struct node <T>* newn = new struct node <T>;

        newn->data = no;
        newn->next = NULL;

        struct node <T> * temp = First;
        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node <T> *temp = First;
        First = First -> next;
        delete temp;
    }
}

template <class T>
void SinglyLL <T>:: DeleteLast()
{    
    if(First == NULL)   // if(iCount == 0)
    {
        return;
    }
    else if(First -> next == NULL) // else if(iCount == 1)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node <T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

    }
}

template <class T>
void SinglyLL <T>:: DeleteAtPosition(int ipos)
{
    int iCount=0;
    iCount=Count();
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct node <T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct node <T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

    }
}

template <class T>
int SinglyLL<T> :: Count()
{
    struct node<T> *  temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

template <class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    struct node <T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    int iRet=0;
    SinglyLL <int> iobj;
    
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    iobj.Display();

    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);
    iobj.Display();

    iRet=iobj.Count();
    cout<<"Number of Nodes are "<<iRet<<"\n";
    
    iobj.InsertAtPosition(105,5);
    iobj.Display();
    iRet=iobj.Count();
    cout<<"Number of Nodes are "<<iRet<<"\n";
    
    iobj.DeleteAtPosition(5);
    iobj.Display();
    iRet=iobj.Count();
    cout<<"Number of Nodes are "<<iRet<<"\n";
    
    iobj.DeleteFirst();
    iobj.DeleteLast();

    iobj.Display();
    iRet=iobj.Count();
    cout<<"Number of Nodes are "<<iRet<<"\n";

    SinglyLL <char> cobj;
    
    cobj.InsertFirst('C');
    cobj.InsertFirst('B');
    cobj.InsertFirst('A');
    cobj.Display();

    cobj.InsertLast('D');
    cobj.InsertLast('E');
    cobj.InsertLast('F');
    cobj.Display();

    iRet=cobj.Count();
    cout<<"Number of Nodes are "<<iRet<<"\n";
    
    cobj.InsertAtPosition('O',5);
    cobj.Display();
    iRet=cobj.Count();
    cout<<"Number of Nodes are "<<iRet<<"\n";
    
    cobj.DeleteAtPosition(5);
    cobj.Display();
    iRet=cobj.Count();
    cout<<"Number of Nodes are "<<iRet<<"\n";
    
    cobj.DeleteFirst();
    cobj.DeleteLast();

    cobj.Display();
    iRet=cobj.Count();
    cout<<"Number of Nodes are "<<iRet<<"\n";
   
    
    return 0;
}