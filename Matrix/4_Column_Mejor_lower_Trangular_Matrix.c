#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n; //Dimention
};
void Set(struct Matrix *M, int i, int j, int x)
{
    if (i >= j)
        M->A[M->n * (j - 1) + ((j - 2) * (j - 1) / 2) + (i - j)] = x;
}
int Get(struct Matrix M, int i, int j)
{
    if (i >= j)
        return M.A[M.n * (j - 1) + ((j - 2) * (j - 1) / 2) + (i - j)];
    else
        return 0;
}
void Display(struct Matrix M)
{
    printf("Display matrix :\n");
    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.n; j++)
        {
            if (i >= j)
                printf("%d ", M.A[M.n * (j - 1) + ((j - 2) * (j - 1) / 2) + (i - j)]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    //Note: This are Square Matrix So That dimention  is n*n;   //Note: Row-Major Lower trangular matrix :
    /* Column Major Lower Trangular Matrix =>  ex.
   
     1 0 0 0 0 
     6 2 0 0 0
     9 7 3 0 0 
     8 6 1 4 0 
     7 5 3 9 5 
     
     Array=C1->|1|6|9|8|7|C2->|2|7|6|5|C3->|3|1|3|C4->|4|9|C1->|5| */
    struct Matrix M;

    printf("Enter Dimention : ");
    scanf("%d", &M.n);
    M.A = (int *)malloc((M.n * (M.n + 1) / 2) * sizeof(int));

    int val;
    printf("Enter all element : \n");
    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.n; j++)
        {
            scanf("%d", &val);
            Set(&M, i, j, val);
        }
    }

    Display(M);
    // printf("Get Element is : %d\n", Get(M, 1, 1));

    return 0;
}
