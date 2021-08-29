
#include <stdio.h>
#include <stdlib.h>

#define n 6
#define I 999999

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

void printSol(int G[n][n],int Dist[n],int parent[n]){
    for (int i = 1; i < n; i++)
    {
      printf("Up to %d from path %d Distance is %d.\n",i,parent[i],Dist[i]);
    }
    
}
// use Queue:
void BFS(int G[][n], int start)
{
    int i = start, r;

    int Dist[n];
    int parent[n];
    int visited[n]; //initialy All Block Assign Zero

    for (int i = 0; i < n; i++)
    {
        Dist[i] = I;
        parent[i] = -1;
        visited[i] = 0;
    }
    Dist[i] =0;

    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * (sizeof(int)));

    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q))
    {
        r = dequeue(&q);
        for (int c = 1; c < n; c++)
        {
            if (G[r][c] == 1 && visited[c] == 0)
            {
                Dist[c]=Dist[r] + G[r][c];
                parent[c]=r;
                visited[c] = 1;
                enqueue(&q, c);
            }
        }
    }
    printSol(G,Dist,parent);
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

    printf("\nMinimum path of non-directed Graph is :\n\n");
    BFS(G,1);

  

    return 0;
}