// #include <stdio.h>
// #include <stdlib.h>
//  stack Follow LIFO(Last in first out) Sequence,But
// Queue Follow FIFO(first in first out) Sequence
struct Node *f = NULL;
struct Node *r = NULL;
struct Node *temp = NULL;

struct Node
{
    int data;
    struct Node *next;
};
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct Node *ptr)
{
    if (ptr == NULL) // if memory is not allow then pointer point to NULL (i.e Memory is full)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Node *ptr)
{
    if (f == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (isFull(ptr))
    {
        printf("Queue is Full !\n");
    }
    else
        ptr->data = val;
        ptr->next = NULL;

    if (f == NULL) // if LinkList is Empty
    {
        f = r = ptr; // Queue is Empty
    }
    else
        r->next = ptr;
        r = ptr;
}
int dequeue(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is Empty !\n");
    }
    else
        temp = f;
        f = f->next;
        int val = temp->data;
        free(temp);

    return val;
}
void LinkListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// int main()
// {
//     LinkListTraversal(f);
//     enqueue(20); //<-- f(0)
//     enqueue(29);
//     enqueue(30); //<--r(2)[if f==r =QEmpty ,if r==size-1=QFull]
//     enqueue(15);
//     enqueue(48);
//     printf("The Dequeuing element is %d\n",dequeue(f)); //<--r(2)[if f==r =QEmpty ,if r==size-1=QFull]
//     printf("The Dequeuing element is %d\n",dequeue(f)); //<--r(2)[if f==r =QEmpty ,if r==size-1=QFull]
//     printf("The Dequeuing element is %d\n",dequeue(f)); //<--r(2)[if f==r =QEmpty ,if r==size-1=QFull]
//     LinkListTraversal(f);

//     return 0;
// }