#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *arr, int n) // take reference(i.e Address) of array for here changes will reflected in main array
{
    printf("\nSelection sort running ......\n");
    int indexOfminV, j;
    // Loop for No.passes
    for (int i = 0; i < n - 1; i++)
    {
        indexOfminV = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexOfminV])
            {
                indexOfminV = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexOfminV];
        arr[indexOfminV] = temp;
        
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
    SelectionSort(Array, n); // to sorted
    dispaly(Array, n);       // after sort
    return 0;
}