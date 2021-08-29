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

// Code For Deletion in Sorted array
int indDeletion(int arr[], int size, int index, int capacity)
{
    if (index >= capacity)
    {
        printf("Deletion Fail ! (index >= Capacity) ");
        return -1;
    }

    printf("Deletion Successful  at index %d:\n",index);
    for (int i = index; i <= size; i++)
    {
        arr[i] = arr[i+1];
    }
    return 1;
}
int main()
{
    // Bfore insertion
    int size = 4;
    int arr[100] = {1, 3, 58, 9};
    // display(arr, size);

    // insert element at index of sorted array
    int index = 2, capacity = 100;
    size -= 1;
    indDeletion(arr, size, index, capacity);
    display(arr, size,capacity);

    return 0;
}