#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
bool compaireLL(struct Node * h1,struct Node *h2){
       while (h1 && h2)
       {
        if(h1->data == h2->data){
            h1 = h1->next;
            h2 = h2->next;
        }
        else
            return false;
       }
       if(h1 == NULL && h2 == NULL){
         return true;
       }
       else
       return false;
       
}
struct Node *Traverse_Nodes(struct Node *head2)
{
    struct Node *ptr = head2;
    while (ptr)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return head2;
}

int main()
{
    struct Node *head1 = NULL, *second1, *third1, *forth1, *fifth1, *sixth1;

    // point pointers to nodes
    head1 = (struct Node *)malloc(sizeof(struct Node));
    second1 = (struct Node *)malloc(sizeof(struct Node));
    third1 = (struct Node *)malloc(sizeof(struct Node));
    forth1 = (struct Node *)malloc(sizeof(struct Node));
    fifth1 = (struct Node *)malloc(sizeof(struct Node));
    sixth1 = (struct Node *)malloc(sizeof(struct Node));

    // link nodes
    head1->data = 6;
    head1->next = second1;

    second1->data = 18;
    second1->next = third1;

    third1->data = 1;
    third1->next = forth1;

    forth1->data = 20;
    forth1->next = fifth1;

    fifth1->data = 20;
    fifth1->next = sixth1;

    sixth1->data = 89;
    sixth1->next = NULL;

    struct Node *head2 = NULL, *second2, *third2, *forth2, *fifth2, *sixth2;

    // point pointers to nodes
    head2 = (struct Node *)malloc(sizeof(struct Node));
    second2 = (struct Node *)malloc(sizeof(struct Node));
    third2 = (struct Node *)malloc(sizeof(struct Node));
    forth2 = (struct Node *)malloc(sizeof(struct Node));
    fifth2 = (struct Node *)malloc(sizeof(struct Node));
    sixth2 = (struct Node *)malloc(sizeof(struct Node));

    // link nodes
    head2->data = 6;
    head2->next = second2;

    second2->data = 18;
    second2->next = third2;

    third2->data = 1;
    third2->next = forth2;

    forth2->data = 20;
    forth2->next = fifth2;

    fifth2->data = 20;
    fifth2->next = sixth2;

    sixth2->data = 89;
    sixth2->next = NULL;

    Traverse_Nodes(head1);
    Traverse_Nodes(head2);
    bool compaire = compaireLL(head1,head2);
    printf("The 1 For Both Linklist Are euqual data and node and vice versa : %d\n",compaire);
    return 0;
}