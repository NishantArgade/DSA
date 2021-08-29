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

int pop(int arr[], int size)
{
    int pop_value = arr[0];

    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
    size = size - 1;
    maxheapify(arr, 0, size);

    size = size - 1;
    return pop_value;
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d ", arr[i]);
    printf("\n");
}
int main()
{
    // build or Creation of max heap
    int arr[] = {19, 1, 2, 50, 36, 25, 100, 17, 7, 60};
    int size = 10;
    buildHeap(arr, size);

    printf("The Max Heap is:\n");
    display(arr, size);

    // deletion of max heap
    for (int i = 1; i <= 10; i++)
    {
        // printf("The Poped Element is : %d\n", pop(arr, size));
        pop(arr, size);
        size = size - 1;
    }

    // SORT of max heap
    printf("\nAfter SORT The Max Heap is:\n");
    display(arr, 10);

    return 0;
}