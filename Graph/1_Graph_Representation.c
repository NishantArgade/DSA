#include <stdio.h>
#include <stdlib.h>

#define V 5 // Vertices
#define e 6 // edges
#define n 6 // Dimention

struct LLnode
{
    int data;
    struct LLnode *next;
};
int Add_edge(struct LLnode *A[V], int v1, int v2)
{
    struct LLnode *V2newNode, *t1;

    V2newNode = (struct LLnode *)malloc(sizeof(struct LLnode));
    V2newNode->data = v2;
    V2newNode->next = NULL;

    if (A[v1] != NULL)
    {
        t1 = A[v1];

        while (t1->next != NULL)
            t1 = t1->next;

        t1->next = V2newNode;
    }
    else
    {
        A[v1] = V2newNode;
    }
}
void AdjList(struct LLnode *A[V])
{
    struct LLnode *t;

    int v1, v2;
    for (int i = 0; i < e; i++)
    {
        printf("For Add edge Enter V1 and V2 :  \n");
        scanf("%d%d", &v1, &v2);
        Add_edge(A, v1, v2);
        Add_edge(A, v2, v1);
    }
}
void Display_adjList(struct LLnode *A[V])
{
    struct LLnode *t;
    for (int i = 0; i < V; i++)
    {
        t = A[i];
        printf("Adjecent of %d is : ", i);
        if (t != NULL)
        {
            for (; t != NULL; t = t->next)
                printf("%d ", t->data);
        }

        printf("\n");
    }
}

void Display_matrix(int G[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}
void Display_Array(int B[V][3])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}

int main()
{ /*
   Graph Representation:
    Graph:
                                      
             (1)
           /    \  
        (5)-----(2)
         |       | 
        (4)-----(3)                                                  
                                (0)                                                                         
                               /   \                                            
                            (4)-----(1)                                                  
                             |       |                                          
                            (3)-----(2)                                              

   1) Adjecency Matrix Representation.
   TC=> O(n^2) SC =>O(n^2)
     Pros: Better in Dense  Graph.(n(e)=n(v^2))

   2) Adjecency List Represention.   
   TC=> O(v + e)=O(n+n)=O(2n)=O(n)   SC=>O(n)
    Cons: Not Better in Dense Graph.(n(e)=n(v^2))

   2) Adjecency Array Represention.   
    TC=> O(n)   SC=>O(n)
    Pros: Better in Dense  Graph.(n(e)=n(v^2)) */

    //    1) Adjecency Matrix Representation.

    int G[n][n] = {

        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 1, 1, 0, 1, 0},
    };
    printf("\nAdjecent matrix Representation is : \n");
    Display_matrix(G);

    //    2) Adjecency List Represention.

    printf("\nAdjecent List Representation is : \n");

    struct LLnode *Array[V] = {NULL};
    AdjList(Array);
    Display_adjList(Array);

    //    2) Adjecency Array Represention.

    int B[6][3] = {
        {1, 2, 10},
        {2, 5, 2},
        {2, 3, 9},
        {3, 4, 18},
        {4, 5, 2},
        {5, 1, 12},
    };
    // printf("\nAdjecent Array Representation is : \n");
    // Display_Array(B);

    return 0;
}
