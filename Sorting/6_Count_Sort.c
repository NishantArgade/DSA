#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", Arr[i]);
    }
    printf("\n");
}
int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void Count_Sort(int *Arr, int n)
{ // Take reference Address of Array
     int i=0, j=0;
    // Find max ele of A
    int max = maximum(Arr, n);

    // Create Count Array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // initialize the count array element to 0
    for (int j = 0; j < max + 1; j++)
    {
        count[j] = 0;
    }
    // Increment corresponding index in array
    for (int i = 0; i < n; i++)
    {
        count[Arr[i]] = count[Arr[i]] + 1;
    }
     i = 0; // index for given array(Arr)
     j = 0; // index for count array(Count)

    while( j <= max)
    {
        if (count[j] > 0)
        {
            Arr[i] = j;
            count[j] = count[j] - 1;
            i++;
        }
        else
         j++;
    }
}
int main()
{
    int Array[] = {3, 5, 8, 3, 5,44};
    int n = 6;
    printArray(Array, n);
    Count_Sort(Array, n);
    printArray(Array, n);
    return 0;
}