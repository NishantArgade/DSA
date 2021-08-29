#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *arr, int n) // take reference(i.e Address) of array for here changes will reflected in main array
{
    printf("\nInersion sort running ......\n");
    int key, j;
    // Loop for No.passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;

        // Loop for each passes
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("\n");
}

void dispaly(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int Array[] = {98, 2, 1, 4, 15};
    int n = 5;
    dispaly(Array, n);       // Before sort
    InsertionSort(Array, n); // to sorted
    dispaly(Array, n);       // after sort
    return 0;
}