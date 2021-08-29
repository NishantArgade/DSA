#include <stdio.h>
#include <stdlib.h>
//  stack Follow LIFO(Last in first out) Sequence,But
// CircularQueue Follow FIFO(first in first out) Sequence

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct CircularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct CircularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    else
     return 0;
}
void enqueue(struct CircularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("CircularQueue is Full !\n");
    }
    else
        q->r = (q->r + 1) % q->size;
    q->arr[q->r] = val;
}
int dequeue(struct CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("CircularQueue is Empty !\n");
    }
    else
        q->f = (q->f + 1) % q->size;
    return q->arr[q->f];
}
int main()
{
    struct CircularQueue q;
    // initialized and create CircularQueue
    q.size = 3;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * (sizeof(int)));
    // <--f==r=(0)
    enqueue(&q, 20); //<-- f(0)
    enqueue(&q, 29);
    enqueue(&q, 30); //<--r(2)[if f==r =QEmpty ,if r==size-1=QFull]

    printf("The DeQueue element is : %d\n", dequeue(&q));
    printf("The DeQueue element is : %d\n", dequeue(&q));
    printf("The DeQueue element is : %d\n", dequeue(&q));

    enqueue(&q, 15); //<--r(2)[if f==r =QEmpty ,if r==size-1=QFull]
    


    if (isEmpty(&q))
    {
        printf("CircularQueue is Empty!\n");
    }
    else
        printf("CircularQueue is not Empty!\n");
    if (isFull(&q))
    {
        printf("CircularQueue is Full!\n");
    }
    else
        printf("CircularQueue is not Full!\n");

    return 0;
}