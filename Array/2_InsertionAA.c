#include <stdio.h>
#include <stdlib.h>

int display(int arr[], int size, int capacity)
{
    if (size >= capacity)
    {
        return -1;
    }
    //Code for Traversal(visit all elements at Once)
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
    return 1;
}

// Code For Insertion in Sorted array
int indInsertion(int arr[], int size, int index, int element, int capacity)
{
    if (size >= capacity)
    {
        printf("Insertion Fail ! (Size >= Capacity) ");
        return -1;
    }

    printf("Insertion Successful :\n");
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    // Bfore insertion
    int size = 4;
    int arr[100] = {1, 3, 58, 9};
    // display(arr, size);

    // insert element at index of sorted array
    int index = 3, element = 100, capacity = 100;
    size += 1;
    indInsertion(arr, size, index, element, capacity);
    display(arr, size,capacity);

    return 0;
}