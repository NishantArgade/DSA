//Deletion in Link List :

// Case1. Deletion at "beginning" of Link List.  # Time-Complecity = O(1).
// Case2. Deletion "Between  Nodes" of Link List.  # Time-Complecity = O(n).
// Case3. Deletion at "end" of Link List.  # Time-Complecity = O(n).
// Case4. Deletion  by value or key . # Time-Complecity = O(n).
//=============================================================================================================================================
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
//---------------------------------------------------------------------------------------------------------------------------------------
// Case1. deletion at "beginning" of Link List.  # Time-Complecity = O(1).

struct Node* deletAtFirst(struct Node* head)
{
     struct Node* ptr = head;// set pointer ptr as head pointer
     head = head->next;
     free(ptr);

     return head;

}
//------------------------------------------------------------------------------------------------------------------------------------
// Case2. deletion "Between  Nodes" of Link List.  # Time-Complecity = O(n).

// void deletAtIndex(struct Node* head,  int index){

//      struct Node* p;// set pointer temp pointer "p" as head pointer position
//     p = head;//

//     int i = 0 ;
//     while (i != index-1 )
//     {
//         p = p->next;
//         i++;
//     }

//     struct Node* q = p->next;

//     p->next = q->next;
//     free(q);
// }
//---------------------------------------------------------------------------------------------------------------------------------------
// Case3. deletion at "end" of Link List.  # Time-Complecity = O(n).

// struct Node* daleteAtLast(struct Node* head)
// {

//     struct Node* p = head;    // set pointer as head pointer
//     struct Node* q = head->next; // set pointer as head->next pointer

//     while (q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }

//     p->next = NULL;
//     free(q);
//     return head;
// }
//-----------------------------------------------------------------------------------------------------------------------------------------
// Case 4. deletion by value or key  # Time-Complecity = O(n).

// void deletAtbyValue(struct Node* head,  int value){

//      struct Node* p= head;// set pointer
//      struct Node* q= head->next;// set pointer
// // allocate memory for NODE in heap

//     while (q->data != value  && q->next != NULL )
//     {
//         p = p->next;
//         q = q->next;
//     }
//     if(q->data = value){
//      p->next = q->next;
//      free(q);
//     }

// }
//---------------------------------------------------------------------------------------------------------------------------------
//Displaying nodes;

void linkList_Traversal(struct Node *p)
{
    printf("This is Node's data :\n");

    while (p != NULL)
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------
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
    head->next = second;

    // 1 . Linked second To third Node:
    second->data = 9;
    second->next = Third;

    // 1 . Linked third To forth Node:
    Third->data = 8;
    Third->next = Forth;

    // 1 . Linked forth To NULL :
    Forth->data = 100;
    Forth->next = NULL;

    //==================================================================================================================================================================================

    // Case 1.
    // struct Node* nhead = deletAtFirst(head);

    // // Case 2.
    // int index = 1 ;// you can not delet zero("0") index value.
    // deletAtIndex(head,index);

     // Case 3.
    // struct Node* nhead;
    // nhead = daleteAtLast(head);
  

    // Case 4.
    // int value =100 ;
    // deletAtbyValue(head,value);

    //Traversing Node's
  
    linkList_Traversal(head);

    return 0;
}