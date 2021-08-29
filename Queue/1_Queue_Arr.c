#include <stdio.h>
#include <stdlib.h>
//  stack Follow LIFO(Last in first out) Sequence,But
// Queue Follow FIFO(first in first out) Sequence

struct Queue
{  int size;
   int f;
   int r;
   int* arr;
};
int isFull(struct Queue* q){
    if (q->r == q->size-1)
    {
        return 1;
    }
     return 0;    
}
int isEmpty(struct Queue* q){
    if (q->f==q->r)
    {
        return 1;
    }
    return 0;   
}
void enqueue(struct Queue* q,int val){
    if (isFull(q))
    {
        printf("Queue is Full !\n");
    }
    else
      q->r++;
      q->arr[q->r]= val;
    
}
int dequeue(struct Queue* q){
    if (isEmpty(q))
    {
        printf("Queue is Empty !\n");
    }
    else
      q->f++;
     return q->arr[q->f];
    
}
int main()
{	struct Queue q;
    // initialized and create Queue
    // q= ()
    q.size = 3;
    q.f = q.r =-1;
    q.arr = (int*)malloc(q.size*(sizeof(int)));
                   // <--f==r=(-1)
    enqueue(&q,20);//<-- f(0)
    enqueue(&q,29);
    enqueue(&q,30);//<--r(2)[if f==r =QEmpty ,if r==size-1=QFull]
    
    printf("The DeQueue element is : %d\n",dequeue(&q));
    printf("The DeQueue element is : %d\n",dequeue(&q));
    printf("The DeQueue element is : %d\n",dequeue(&q));
    // enqueue(&q,30);//<--r(2)[if f==r =QEmpty ,if r==size-1=QFull]

    if (isEmpty(&q))
    {
        printf("Queue is Empty!\n");
    }
    else
        printf("Queue is not Empty!\n");
    if (isFull(&q))
    {
        printf("Queue is Full!\n");
    }
    else
        printf("Queue is not Full!\n");
    
    
    return 0;
}