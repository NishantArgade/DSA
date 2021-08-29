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
    int arr[] = {19, 1, 2, 3, 36, 25, 100, 17, 7};
    int size = 9;
    buildHeap(arr, size);

    printf("The Max Heap is:\n");
    display(arr, size);

    printf("\nAfter deletion The Max Heap is:\n");
    printf("The Poped Element is : %d\n", pop(arr, size));
    size = size - 1;
    display(arr, size);

    printf("The Poped Element is : %d\n", pop(arr, size));
    size = size - 1;
    display(arr, size);

    printf("The Poped Element is : %d\n", pop(arr, size));
    size = size - 1;
    display(arr, size);

    return 0;
}