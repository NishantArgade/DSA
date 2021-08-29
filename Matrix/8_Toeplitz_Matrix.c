#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n; //Dimention
};
void Set(struct Matrix *M, int i, int j, int x)
{

    if (i <= j) // row
        M->A[j - i] = x;

    else if (i > j) // Column
        M->A[M->n + (i - j - 1)] = x;
}
int Get(struct Matrix M, int i, int j)
{
    if (i <= j) // row
        return M.A[j - i];

    else if (i > j) // column
        return M.A[M.n + (i - j - 1)];
    else
        return 0;
}
void Display(struct Matrix M)
{

    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.n; j++)
        {
            if (i <= j) // row
                printf("%d ", M.A[j - i]);

            else if (i > j) // column
                printf("%d ", M.A[M.n + (i - j - 1)]);

            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    //Note: This are Square Matrix So That dimention  is n*n;
    /* Toplitz Matrix => M[i,j]==M[i-1,j-1] ex.
   
     2 3 4 5 6 
     7 2 3 4 5
     8 7 2 3 4 
     9 8 7 2 3 
    10 9 8 7 2  */ 

    struct Matrix M;

    printf("Enter Dimention : ");
    scanf("%d", &M.n);
    M.A = (int *)malloc((M.n + (M.n - 1)) * sizeof(int));

    int x;
    printf("Enter All Matrix Elements :\n");

    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.n; j++)
        {
            scanf("%d", &x);
            Set(&M, i, j, x);
        }
    }
    printf("\n\n");

    Display(M);
    // printf("Get Element is : %d\n", Get(M, 1, 1));

    return 0;
}