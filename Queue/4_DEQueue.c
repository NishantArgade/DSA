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
void R_enqueue(struct Queue* q,int val){
    if (isFull(q))
    {
        printf("Queue is Full !\n");
    }
    else
      q->r++;
      q->arr[q->r]= val; 
}
void F_enqueue(struct Queue* q,int val){
    if (isFull(q))
    {
        printf("Queue is Full !\n");
    }
    else
      q->f--;
      q->arr[q->f]= val; 
}
int F_dequeue(struct Queue* q){
    if (isEmpty(q))
    {
        printf("Queue is Empty !\n");
    }
    else
      q->f++;
     return q->arr[q->f];
}
int R_dequeue(struct Queue* q){
    int Rint;
    if (isEmpty(q))
    {
        printf("Queue is Empty !\n");
    }
    else
     Rint = q->r;
      q->r--;
     return q->arr[Rint];
}
int main()
{	struct Queue q;
    // initialized and create Queue
    // q= ()
    q.size = 3;
    q.f = q.r =-1;
    q.arr = (int*)malloc(q.size*(sizeof(int)));
      
    // printf("Normal Enqueue Dequeue Operation :\n");             // <--f==r=(-1)
    R_enqueue(&q,3);//<-- f(0)
    R_enqueue(&q,4);
    // printf("The DeQueue element is : %d\n",F_dequeue(&q));
    // printf("The DeQueue element is : %d\n",F_dequeue(&q));

    printf("Double Ended Enqueue Dequeue Operation :\n");     
    // F_enqueue(&q,3);//<-- f(0)
    // F_enqueue(&q,4);
    printf("The DeQueue element is : %d\n",R_dequeue(&q));
    printf("The DeQueue element is : %d\n",R_dequeue(&q));
        // <--f==r=(-1)
    
    return 0;
}