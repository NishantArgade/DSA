#include <stdio.h>
#include <stdlib.h>
void Merge(int Arr[], int mid, int low, int high)
{
    int i, j, k, tempArr[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (Arr[i] < Arr[j])
        {
            tempArr[k] = Arr[i];
            k++, i++;
        }
        else
        {
            tempArr[k] = Arr[j];
            k++, j++;
        }
        
    }
    while (i <= mid)
    {
        tempArr[k] = Arr[i];
        k++, i++;
    }
    while (j <= high)
    {
        tempArr[k] = Arr[j];
        k++, j++;
    }

    for (int i = low; i <= high; i++)
    {
        Arr[i] = tempArr[i];
    }
}

void MergeSort(int Arr[], int low, int high)
{
    int mid;
    if (low < high) // min two block required,if one block then cannot sort bcs it is already sorted.
    {
        mid = (low + high) / 2;
        MergeSort(Arr, low, mid);
        MergeSort(Arr, mid + 1, high);
        Merge(Arr, mid, low, high);
    }
}

//--------------------------------------------------------------------------------------------------------
void display_Array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int Array[] = {31, 2, 9, 2, 9,999,3,45};
    int n = 8;
    display_Array(Array, n);
    printf("Merge Sort Perform....\n");
    MergeSort(Array, 0, n-1);
    display_Array(Array, n);

    return 0;
}