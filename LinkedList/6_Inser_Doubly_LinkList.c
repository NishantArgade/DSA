//  Insertion in Doubly Link List :

// Case1. Insert at "beginning" of Doubly Link List.  # Time-Complecity = O(1).
// Case2. Insert "Between  Nodes" of Doubly Link List.  # Time-Complecity = O(n).
// Case3. Insert at "end" of Doubly Link List.  # Time-Complecity = O(n).

//=============================================================================================================================================
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
//---------------------------------------------------------------------------------------------------------------------------------------
// Case1. Insert at "beginning" of Doubly Link List.  # Time-Complecity = O(1).

// struct Node *insertAtFirst(struct Node *head, int data)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = data;

//     struct Node *p = head; // set p as like head pointer

//     ptr->next = head;
//     head->prev = ptr;
//     ptr->prev = NULL;

//     head = ptr;

//     return head;
// }
//------------------------------------------------------------------------------------------------------------------------------------
// Case2. Insert "Between  Nodes" of Doubly Link List.  # Time-Complecity = O(n).

// void insertAtIndex(struct Node* head,  int index,int data){

//      struct Node* ptr;// set pointer
//     ptr = (struct Node*)malloc(sizeof(struct Node));// allocate memory for NODE in heap
//     ptr->data=data;// set node value

//      struct Node* p;// set pointer
//     p = head;// allocate memory for NODE in heap

//     int i = 0 ;
//     while (i < index-1 && p->next != NULL )
//     {
//         p = p->next;
//         i++;
//     }
//     struct Node*  x = p->next;

//     ptr->next =x;
//     ptr->prev =p;
//     p->next = ptr;
//     x->prev = ptr;

// }
//---------------------------------------------------------------------------------------------------------------------------------------
// Case3. Insert at "end" of Doubly Link List.  # Time-Complecity = O(n).

// void InsertATEnd(struct Node *head, int data)
// {

//     struct Node *ptr;                                 // set pointer
//     ptr = (struct Node *)malloc(sizeof(struct Node)); // allocate memory for NODE in heap
//     ptr->data = data;                                 // set node value

//     struct Node *p; // set pointer
//     p = head;       // allocate memory for NODE in heap

//     while (p->next != NULL)
//     {
//         p = p->next;
//     }

//     ptr->next = NULL;
//     ptr->prev = p;
//     p->next = ptr;
// }
//---------------------------------------------------------------------------------------------------------------------------------
void linkList_Traversal(struct Node *head)
{
    printf("The Node's data is :\n");
    struct Node *p = head;

    do
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    } while (p != NULL); // if first condition false however run loop at Once
}

int main()
{
    // Creation Of Node:

    struct Node *head;
    struct Node *second;
    struct Node *Third;
    struct Node *Forth;

    head = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for Node in the Heap
    second = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));
    Forth = (struct Node *)malloc(sizeof(struct Node));

    // Linking  Of Nodes:

    // 1 . Linked head To Second Node:
    head->data = 20;
    head->prev = NULL;
    head->next = second;
    second->prev = head;

    // 1 . Linked second To third Node:
    second->data = 9;
    second->next = Third;
    Third->prev = second;

    // 1 . Linked third To forth Node:
    Third->data = 8;
    Third->next = Forth;
    Forth->prev = Third;

    // 1 . Linked forth To NULL :
    Forth->data = 100;
    Forth->next = NULL; // here make Doubly Doubly Link List

    // Case 1.
    // int data = 1111;
    // struct Node* nhead = insertAtFirst(head,data);

    // // Case 2.
    // linkList_Traversal(head);

    // int index = 3,data =3333;
    // insertAtIndex(head,index, data);

    // Case 3.
    // Traversing befor Node's
    // linkList_Traversal(head);

    // int data = 5555;
    // InsertATEnd(head,data);

    //Traversing after insertion Node's
    linkList_Traversal(head);

    return 0;
}