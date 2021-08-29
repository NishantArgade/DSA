#include <stdio.h>

void maxheapify(int arr[], int i, int size)
{
    int largestInd = i;
    int L_ChildInd = 2 * i + 1;
    int R_ChildInd = 2 * i + 2;

    if (L_ChildInd < size && arr[i] < arr[L_ChildInd])
        largestInd = L_ChildInd;

    if (R_ChildInd < size && arr[largestInd] < arr[R_ChildInd])
        largestInd = R_ChildInd;

    if (largestInd != i)
    {
        // swap(arr[largestInd],arr[i]);
        int temp = arr[largestInd];
        arr[largestInd] = arr[i];
        arr[i] = temp;

        maxheapify(arr, largestInd, size);
    }
}
void buildHeap(int arr[], int size)
{
    for (int i = size / 2; i >= 0; i--)
        maxheapify(arr, i, size);
}

void heapify(int arr[], int i)
{
    int parent_ind = (i - 1) / 2;
    if (parent_ind >= 0 && arr[i] > arr[parent_ind])
    {
        int temp = arr[parent_ind];
        arr[parent_ind] = arr[i];
        arr[i] = temp;

        heapify(arr, parent_ind);
    }
}
void insert(int arr[], int i, int value)
{
    arr[i] = value;
    heapify(arr, i);
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d ", arr[i]);
}
int main()
{
    int arr[] = {19, 1, 2, 3, 36, 25, 100, 17, 7};
    int size = 9;
    buildHeap(arr, size);

    printf("The Max Heap is:\n");
    display(arr,size);

    printf("\nAfter insertion The Max Heap is:\n");

    int index = 9, value = 106;

    insert(arr, index, value);
    size = size + 1;
    display(arr,size);

    return 0;
}