//  Insertion in Circular Link List :

// Case1. Insert at "beginning" of Circular Link List.  # Time-Complecity = O(1).
// Case2. Insert "Between  Nodes" of Circular Link List.  # Time-Complecity = O(n).
// Case3. Insert at "end" of Circular Link List.  # Time-Complecity = O(n).
// Case4. Insert at after Node .(pointer of that node is know or given). # Time-Complecity = O(1).
//=============================================================================================================================================
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
//---------------------------------------------------------------------------------------------------------------------------------------
// Case1. Insert at "beginning" of Circular Link List.  # Time-Complecity = O(1).

// struct Node *insertAtFirst(struct Node *head, int data)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = data;

//     struct Node *p = head; // set p as like head pointer

//     while (p->next != head)
//     {
//         p = p->next;
//     }

//     p->next = ptr;
//     ptr->next = head;
//     head=ptr; 

//     return head;
// }
//------------------------------------------------------------------------------------------------------------------------------------
// Case2. Insert "Between  Nodes" of Circular Link List.  # Time-Complecity = O(n).

// void insertAtIndex(struct Node* head,  int index,int data){

//      struct Node* ptr;// set pointer
//     ptr = (struct Node*)malloc(sizeof(struct Node));// allocate memory for NODE in heap
//     ptr->data=data;// set node value

//      struct Node* p;// set pointer
//     p = head;// allocate memory for NODE in heap

//     int i = 0 ;
//     while (i != index-1 )
//     {
//         p = p->next;
//         i++;
//     }

//     ptr->next = p->next;
//     p->next = ptr;
// }
//---------------------------------------------------------------------------------------------------------------------------------------
// Case3. Insert at "end" of Circular Link List.  # Time-Complecity = O(n).

// void InsertATEnd(struct Node* head,int data){

//      struct Node* ptr;// set pointer
//     ptr = (struct Node*)malloc(sizeof(struct Node));// allocate memory for NODE in heap
//     ptr->data=data;// set node value

//      struct Node* p;// set pointer
//     p = head;// allocate memory for NODE in heap

//     while (p->next != head )
//     {
//         p = p->next;
//     }

//     p->next = ptr;
//     ptr->next = head;
// }
//-----------------------------------------------------------------------------------------------------------------------------------------
// Case 4. Insert After given node  # Time-Complecity = O(n).

// void InsertAfterNode(struct Node* head,struct Node* previous_node,int data){

//      struct Node* ptr;// set pointer
//     ptr = (struct Node*)malloc(sizeof(struct Node));// allocate memory for NODE in heap
//     ptr->data=data;// set node value

//     ptr->next = previous_node->next;//  first connection as "/"
//     previous_node->next = ptr;//  second connection  as "\"
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
    } while (p != head); // if first condition false however run loop at Once
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

    // Allocate memory for New Node
    // struct Node* nNode;// set pointer
    // nNode = (struct Node*)malloc(sizeof(struct Node));// allocate memory in heap
    // nNode->data = 1234;// set node value

    // Linking  Of Nodes:

    // 1 . Linked head To Second Node:
    head->data = 20;
    head->next = second;

    // 1 . Linked second To third Node:
    second->data = 9;
    second->next = Third;

    // 1 . Linked third To forth Node:
    Third->data = 8;
    Third->next = Forth;

    // 1 . Linked forth To NULL :
    Forth->data = 100;
    Forth->next = head; // here make Circular Circular Link List

    // Case 1.
    // int data = 300;
    // struct Node* nhead = insertAtFirst(head,data);

    // // Case 2.
    // int index = 3,data =3333;
    // insertAtIndex(head,index, data);

    // Case 3.
    // Traversing befor Node's
    // linkList_Traversal(head); 

    // int data =7000;
    // InsertATEnd(head,data);

    // Case 4.
    // int data =700;
    // InsertAfterNode(head,second,data);

    //Traversing after insertion Node's
    linkList_Traversal(head);

    return 0;
}