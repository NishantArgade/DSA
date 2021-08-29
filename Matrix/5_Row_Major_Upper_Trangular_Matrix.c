#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n; //Dimention
};
void Set(struct Matrix *M, int i, int j, int x)
{
    if (i <= j)
        M->A[M->n * (i - 1) + ((i - 2) * (i - 1) / 2) + (j - i)] = x;
}
int Get(struct Matrix M, int i, int j)
{
    if (i <= j)
        return M.A[M.n * (i - 1) + ((i - 2) * (i - 1) / 2) + (j - i)];
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
            if (i <= j)
                printf("%d ", M.A[M.n * (i - 1) + ((i - 2) * (i - 1) / 2) + (j - i)]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    //Note: This are Square Matrix So That dimention  is n*n;   //Note: Row-Major Lower trangular matrix :
    /* Row Major Upper Trangular Matrix =>  ex.
   
     1 2 3 4 5 
     0 7 8 9 1
     0 0 6 4 2 
     0 0 0 4 5 
     0 0 0 0 5 
     
     Array=R1->|1|2|3|4|5|R2->|7|8|9|1|R3->|6|4|2|R4->|4|5|R1->|5| */
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
