# include <iostream>
using namespace std;
#pragma pack(1)

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;      // X
};

//typedef struct node NODE;
//typedef struct node * PNODE;
//typedef struct node ** PPNODE;
template<class T>
class DoublyLL
{
   public:
      struct node<T> *First;

      DoublyLL();
      void InsertFirst(T no);
      void InsertLast(T no);
      void InsertAtPos(T no,int ipos);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int ipos);

      void Display ();
      int Count ();
      
};

template<class T>
 DoublyLL<T>::DoublyLL()
 {
    First=NULL;
 }
template<class T>
void DoublyLL<T>::InsertFirst( T no)
{
    struct node <T>* newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
    }
}
template<class T>
void DoublyLL<T>:: InsertLast( T no)
{
    struct node <T>* newn = new struct node<T>;

    struct node <T>*temp = First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
    }
}
template<class T>
void DoublyLL<T>::Display()
{
    struct node <T>* temp=First;
    cout<<"Elements of Linked list are"<<"\n";

    cout<<"NULL<=> ";

    while(temp != NULL)
    {
        //printf("| %d |<=> ",temp->data);
        cout<<"|"<<temp->data<<"|"<<"<=>";
        temp = temp->next;
    }
    cout<<"NULL "<<"\n";
}
template<class T>
int DoublyLL<T>::Count()
{
    struct node <T>*temp=First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }

    return iCnt;
}
template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if((First)->next == NULL) // LL contains 1 node
    {
        free(First);
        First = NULL;
    }
    else    // LL contains more than 1 node
    {
        First = (First) -> next;
        free((First)->prev);               // X
        (First)->prev = NULL;              // X
    }
}
template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct node <T>* temp = First;

    if(First == NULL)  // LL is empty
    {
        return;
    }
    else if((First)->next == NULL) // LL contains 1 node
    {
        free(First);
        First = NULL;
    }
    else    // LL contains more than 1 node
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

template<class T>
void DoublyLL<T>::InsertAtPos( T no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    struct node <T>* newn = NULL;
    struct node <T>*temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;


        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      // X

        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    // X
        temp->next = newn;
        newn->prev = temp;      // X
    }
}
template<class T>
void DoublyLL<T>:: DeleteAtPos( int ipos)
{
    struct node <T>*temp1 = NULL;
    struct node <T>*temp2 = NULL;
    int iCnt = 0, NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
       cout<<"Invalid position"<<"\n";

        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;  
        temp2->next->prev = temp1;      // X
        free(temp2);
    }
}

int main()
{
    DoublyLL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.Display();

    obj.InsertFirst(21);
    obj.Display();

    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(101);
    obj.Display();

    obj.InsertLast(111);
    obj.Display();

    obj.InsertLast(121);
    obj.Display();

    iRet = obj.Count();
    cout<<"Numbers of Elements are:"<<iRet<<"\n";

    obj.InsertAtPos(105,5);
    obj.Display();

    obj.DeleteAtPos(5);
    obj.Display();

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Numbers of Elements are:"<<iRet<<"\n";
    
    return 0;
}