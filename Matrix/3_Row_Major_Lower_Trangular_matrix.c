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
        M->A[i * (i - 1) / 2 + j - 1] = x;
}
int Get(struct Matrix M, int i, int j)
{
    if (i >= j)
        return M.A[i * (i - 1) / 2 + j - 1];
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
                printf("%d ", M.A[i * (i - 1) / 2 + j - 1]);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    //Note: This are Square Matrix So That dimention  is n*n;   //Note: Row-Major Lower trangular matrix :
    /* Row Major Lower Trangular Matrix =>  ex.
   
     1 0 0 0 0 
     6 2 0 0 0
     9 7 3 0 0 
     8 6 1 4 0 
     7 5 3 9 5 
     
     Array=R1->|1|R2->|6|2|R3->|9|7|3|R4->|8|6|1|4|R1->|7|5|3|9|5|*/
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
