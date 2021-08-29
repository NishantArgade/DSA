// 1. Breadth First Search (BFS):(level order Traversal)->uesd Queue
// 2. Deepth First Search (DFS):(preOrder Traversal)->used Stack

#include <stdio.h>
#include <stdlib.h>

#define n 6

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full !\n");
    }
    else
        q->r++;
    q->arr[q->r] = val;
}
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty !\n");
    }
    else
        q->f++;
    return q->arr[q->f];
}

// use Queue:
void BFS(int G[][n], int start)
{
    int i = start, r;
    int visited[n] = {0}; //initialy All Block Assign Zero

    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * (sizeof(int)));

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q))
    {
        r = dequeue(&q);
        for (int c = 1; c < n; c++)
        {
            if (G[r][c] == 1 && visited[c] == 0)
            {
                printf("%d ", c);
                visited[c] = 1;
                enqueue(&q, c);
            }
        }
    }
    printf("\n");
}
// use  Stack:
void DFS(int G[][n], int start)
{
    static int visited[n] = {0}; 

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;

        for (int c = 1; c < n; c++)
        {
            if (G[start][c] == 1 && visited[c] == 0)
                DFS(G, c);
        }
    }
    printf("\n");
}
int main()
{ 
    /* BFS / DFS:
            (1)
          /     \  
        (5)-----(2)
         |       | 
        (4)-----(3)     */

    int G[n][n] = {

        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 1, 1, 0, 1, 0},
    };
    
    printf("Breadth First Search is : \n");
    BFS(G, 1);

    printf("Deepth First Search is : \n");
    DFS(G, 1);

    return 0;
}