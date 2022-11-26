#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *arr, int n) // take reference(i.e Address) of array for here changes will reflected in main array
{
    printf("\nInersion Sort\n");
    
 
    for (int i = 1; i <= n - 1; i++)    // Loop for No.passes
    {
        int  temp = arr[i];
        
        int  j = i - 1;
        while (j >= 0 && arr[j] > temp)  // Loop for each passes
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printf("\n");
}

void dispaly(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
}
int main()
{
    int Array[] = {98, 2, 1, 4, 15};
    int n = 5;
    dispaly(Array, n);       // Before sort
    InsertionSort(Array, n); // to sorted
    dispaly(Array, n);       // after sort
    
    /*
    
    Algo -> traverse array and compair element with its previous elements & insert that element in its right place
        
       S.C -> O(1)
       Average case T.C -> O(n^2)
       Best case T.C(already sorted array) -> O(n)
       Worst case T.C -> O(n^2)
        
      Use Case ->
       1. Adaptable sorting technique
       2. Stable sorting technique
           
   */
    return 0;
}
