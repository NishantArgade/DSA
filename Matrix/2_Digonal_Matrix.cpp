#include <stdio.h>
#include <stdlib.h>

class Matrix
{
private:
    int *A;
    int n; //Dimention
public:
    Matrix()
    {
        n = 2;
        A = new int[n];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Matrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display(int i, int j);
};
void Matrix::Set(int i, int j, int x)
{
    if (i == j)
        A[i] = x;
}

int Matrix::Get(int i, int j)
{
    if (i == j)
        return A[i];
    else
        return 0;
}

void Matrix::Display(int i, int j)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                printf("%d ", A[i]);
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
    struct Matrix M(3);

    M.Set(0, 0, 5);
    M.Set(1, 1, 7);
    M.Set(2, 2, 9);

    M.Display(0, 0);
    printf("Get Element is : %d\n", M.Get(2, 2));

    return 0;
}