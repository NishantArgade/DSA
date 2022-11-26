#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(int arr[], int s, int e)
{
    int pivot = s, cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[pivot] >= arr[i])
            cnt++;
    }
    pivot += cnt;
    swap(arr, s, pivot);

    int i = s, j = e;
    while (i < pivot && pivot < j)
    {
        while (arr[i] < arr[pivot])
            i++;
        while (arr[j] > arr[pivot])
            j--;

        if (i < pivot && pivot < j)
            swap(arr, i++, j--);
    }
    return pivot;
}

void QuickSort(int Arr[], int low, int high)
{
    int partitionIndex;
    if (low < high) // min two block required,if one block then cannot sort bcs it is already sorted.
    {
        partitionIndex = partition(Arr, low, high);
        QuickSort(Arr, low, partitionIndex - 1);  // sort for left
        QuickSort(Arr, partitionIndex + 1, high); // sort for right
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
    int a[] = {31, 2, 9, 2, 9, 0, 15, 10, 55, 8};
    int n = 8;
    display_Array(a, n);
    printf("Quick Sort Perform....\n");
    QuickSort(a, 0, n - 1);
    display_Array(a, n);

/*
   Algo-> 1.partition -> set pivot it's right place such that Lift__eles < pivot < Right_eles
          2.Recurssion -> perform left recursion and right recursion.

    S.C -> O(n)
    Avgerage case T.C -> O(n*logn)
    Best case T.C -> O(n*logn)
    Worst case T.C -> O(n^2)

    Properties:
    1.it is inplace sorting algo.
    2.it is stable sorting algo.
*/
    return 0;
}
