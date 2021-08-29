#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n; //Dimention
};
void Set(struct Matrix *M, int i, int j, int x)
{
    if (i == j)
        M->A[i] = x;
}
int Get(struct Matrix M, int i, int j)
{
    if (i == j)
        return M.A[i];
    else
        return 0;
}
void Display(struct Matrix M, int i, int j)
{
    for (int i = 0; i < M.n; i++)
    {
        for (int j = 0; j < M.n; j++)
        {
            if (i == j)
                printf("%d ", M.A[i]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }

}

int main()
{
    //Note: This are Square Matrix So That dimention  is n*n;
    /* Digonal Matrix =>  ex.
   
     5 0 0 0 0 
     0 6 0 0 0
     0 0 7 0 0 
     0 0 0 8 0 
     0 0 0 0 9 
     
     Array=R1->|5|R2->|6|R3->|7|R4->|8|R1->|9|*/
     
    struct Matrix M;

    printf("Enter Dimention : ");
    scanf("%d", &M.n);
    M.A = (int *)malloc(M.n * sizeof(int));

    Set(&M, 0, 0, 5);
    Set(&M, 1, 1, 7);
    Set(&M, 2, 2, 9);

    Display(M, 0, 0);
   printf("Get Element is : %d\n",Get(M,1,1));
    
    return 0;
}