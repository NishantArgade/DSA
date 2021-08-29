#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n; //Dimention
};
void Set(struct Matrix *M, int i, int j, int x)
{

    if (i - j == 1) // Lower Digonal
        M->A[i - 1] = x;

    else if (i - j == 0) // Main Digonal
        M->A[(M->n - 1) + (i - 1)] = x;

    else if (i - j == -1) // Upper Digonal
        M->A[(2 * M->n - 1) + (i - 1)] = x;
}
int Get(struct Matrix M, int i, int j)
{
    int x;
    if (i - j <= 1)
    {
        if (i - j == 1) // Lower Digonal
            x = M.A[i - 1];
        else if (i - j == 0) // Main Digonal
            x = M.A[(M.n - 1) + (i - 1)];
        else if (i - j == -1) // Upper Digonal
            x = M.A[(2 * M.n - 1) + (i - 1)];
        return x;
    }
    else
        return 0;
}
void Display(struct Matrix M)
{
    int x;
    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.n; j++)
        {
            if (i - j == 1)
            { // Lower Digonal
                x = M.A[i - 1];
                printf("%d ", x);
            }
            else if (i - j == 0)
            { // Main Digonal
                x = M.A[(M.n - 1) + (i - 1)];
                printf("%d ", x);
            }
            else if (i - j == -1)
            { // Upper Digonal
                x = M.A[(2 * M.n - 1) + (i - 1)];
                printf("%d ", x);
            }

            else
                printf("%d ", 0);
        }
        printf("\n");
    }
}

int main()
{
    //Note: This are Square Matrix So That dimention  is n*n;
    /* Tridigonal Matrix => main dig= i-j =0;lower dig=i-j=1;upper dig= i-j=-1 i.e|i-j|<= 1 ex.
   
     1 3 0 0 0 
     6 2 4 0 0
     0 7 3 5 0 
     0 0 8 4 6 
     0 0 0 9 5  */
    struct Matrix M;

    printf("Enter Dimention : ");
    scanf("%d", &M.n);
    M.A = (int *)malloc((3 * M.n - 2) * sizeof(int));

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