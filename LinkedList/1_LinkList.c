//  Creation and Traversal Of Link List :

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
};

void linkList_Traversal(struct Node *p)
{   
    printf("This is Node's data :\n");
    while (p != NULL)
    {  
        printf("Element : %d\n", p->data);
        p = p->next;
    }
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

    //Traversing Node's
    linkList_Traversal(head);

    return 0;
}