#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Array
{
    int *A;
    int size;
    int lenght;
};
void Append(struct Array *arr, int x) // Arrgument pass by reference(i want reflect changes)
{
    if (arr->lenght < arr->size)
        arr->A[arr->lenght++] = x;
}
void Display(struct Array arr) // Arrgument pass by Value(i don't want reflect changes)
{
    printf("Elements are : \n");

    for (int i = 0; i < arr.lenght; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int max = INT_MIN;
int min = INT_MAX;
void Max_Min(struct Array arr)
{
    for (int i = 0; i < arr.lenght; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];

        if (arr.A[i] < min)
            min = arr.A[i];
    }
}
void findPairOfSum(struct Array arr, int sum)
{
    for (int i = 0, j = arr.lenght - 1; i < j;)
    {
        if (arr.A[i] + arr.A[j] == sum)
        {
            printf("%d + %d = %d \n", arr.A[i], arr.A[j], sum);
            i++;
            j--;
        }
        if (arr.A[i] + arr.A[j] < sum)
            i++;
        if (arr.A[i] + arr.A[j] > sum)
            j--;
    }
}
int H[15];
void pair_withSum(struct Array arr, int sum)
{

    for (int i = 0; i < 16; i++)
        H[i] = 0;

    for (int i = 0; i < arr.lenght; i++)
        H[arr.A[i]]++;
    for (int j = 0; j < arr.lenght; j++)
    {
        if (sum - arr.A[j] != 0)
            printf("%d + %d = %d \n", arr.A[j], sum - arr.A[j], sum);
    }
}
void find_pair_withSum(struct Array arr, int sum)
{

    for (int i = 0; i < arr.lenght - 1; i++)
    {

        for (int j = i + 1; j < arr.lenght; j++)
        {
            if (arr.A[i] + arr.A[j] == sum)
                printf("%d + %d = %d \n", arr.A[i], arr.A[j], sum);
        }
    }
}
void find_Dublicate(struct Array arr)
{
    for (int i = 0; i < arr.lenght - 1; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {
            for (int j = i + 1; j < arr.lenght; j++)
            {
                if (arr.A[i] == arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if (count > 1)
                printf("Dublicate of \"%d\" in %d times\n", arr.A[i], count);
        }
    }
}
void find_Dublicate2(struct Array arr)
{
    for (int i = 0; i <= 15; i++)
        H[i] = 0;

    for (int i = 0; i < arr.lenght; i++)
        H[arr.A[i]]++;

    for (int i = i; i <= 15; i++)
    {
        if (H[i] > 1)
            printf("Dublicate of \"%d\" in %d times\n", i, H[i]);
    }
}
void find_Dublicate3(struct Array arr)
{
    int j;
    for (int i = 0; i < arr.lenght - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            j = i + 1;
            while (arr.A[i] == arr.A[j])
                j++;
            printf("Dublicate of \"%d\" in %d times\n", arr.A[i], j - i);
            i = j - 1;
        }
    }
}
void is_Dublicate_exists(struct Array arr)
{
    int LastDublicate = 0;
    for (int i = 0; i < arr.lenght; i++)
    {
        if (arr.A[i] == arr.A[i + 1] && arr.A[i] != LastDublicate)
        {
            printf("Dublicate of \"%d\" is exists", arr.A[i]);
            LastDublicate = arr.A[i];
        }
    }
}
int H1[9];
void Find_MissingElement(struct Array arr)
{

    for (int i = 0; i <= 9; i++)
        H1[i] = 0;

    for (int i = 0; i < arr.lenght; i++)
        H1[arr.A[i]]++;
    for (int j = 1; j <= 9; j++)
    {
        if (H1[j] == 0)
            printf("Missing Element is : %d \n", j);
    }
}
void Find_MissingElement2(struct Array arr)
{
    int diff = arr.A[0] - 0;
    for (int i = 0; i < arr.lenght; i++)
        if (arr.A[i] - i != diff)
        {
            while (diff < arr.A[i] - i)
            {
                printf("Missing Element is : %d \n", diff + i);
                diff++;
            }
        }
}
void Find_MissingElement3(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.lenght; i++)
        sum = sum + arr.A[i];

    int n = arr.lenght+1 ;//+1 for missing element
    int Actual_Total_sum = (n*(n + 1))/2; //  1+2+3+4+5+6+7+8.....= n(n+1)/2

    printf("Missing Element is : %d \n", Actual_Total_sum - sum);
}
int main()
{
    struct Array arr;
    struct Array arr2;

    int size;
    printf("Enter Size of Array :\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.lenght = 0;

    Append(&arr, 1);
    Append(&arr, 2);
    Append(&arr, 3);
    Append(&arr, 4);
    Append(&arr, 6);
    

    // find_pair_withSum(arr, 27);

    // find_Dublicate2(arr);
    // continuous Dublicate one after other ex 1,2,3,4,4,5,5,5,7,8
    // find_Dublicate3(arr);
    // continuous Dublicate is Exists or not  ex 1,2,3,4,4,7,8
    // is_Dublicate_exists(arr);

    // Find_MissingElement(arr);
    // Find_MissingElement2(arr);
    Find_MissingElement3(arr);

    return 0;
}