#include <stdio.h>
#include <stdlib.h>
int partition(int Arr[], int low, int high)
{
    int pivot = Arr[low];// set pivot as first index
    int i = low + 1;// increase ( i++ --> ) untill pivot < number
    int j = high;// decrease ( j--  <-- ) untill pivot >= number
    int Temp;
    
   while(i<=j){

        while (pivot >= Arr[i])
        {
            i++;
        }
        while (pivot < Arr[j])
        {
            j--;
        }
        if (i <= j)
        {
            Temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = Temp;
        }
    };

    if (j < i)// Here will swap and set pivot Right position : lower numbers(sort or unsort order) <-- pivot --> greater numbers(sort or unsort)
    {
        int temp;
        temp = Arr[low];
        Arr[low] = Arr[j];
        Arr[j] = temp;
    }

    return j;// return new seted pivot index ,lower numbers(sort or unsort order) <-- pivot --> greater numbers(sort or unsort)
}

void QuickSort(int Arr[], int low, int high)
{
    int partitionIndex;
    if (low < high)// min two block required,if one block then cannot sort bcs it is already sorted.
    { 
        partitionIndex = partition(Arr, low, high);
        QuickSort(Arr, low, partitionIndex - 1);// sort for left
        QuickSort(Arr, partitionIndex + 1, high);// sort for right
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
    int a[] = {31, 2,9, 2, 9, 0, 15, 10, 55, 8};
    int n = 8;
    display_Array(a, n);
    printf("Quick Sort Perform....\n");
    QuickSort(a, 0, n - 1);
    display_Array(a, n);

    return 0;
}