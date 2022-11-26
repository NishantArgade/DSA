#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *arr, int n) // take reference(i.e Address) of array for here changes will reflected in main array
{
    printf("\nSelection Sort\n");
    
    int indexOfminV, j;
    
    for (int i = 0; i < n - 1; i++)  // Loop for No. passes
    {
        indexOfminV = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[indexOfminV])
                indexOfminV = j;    
        }
        
        // sort arr[i] and arr[indexOfminV]
        int temp = arr[i];
        arr[i] = arr[indexOfminV];
        arr[indexOfminV] = temp;
    }

    printf("\n");
}

void dispaly(int arr[], int n){
   for (int i = 0; i < n; i++)
       printf("%d ", arr[i]); 
}

int main()
{
    int Array[] = {98, 2, 1, 4, 15};
    int n = sizeof(Array)/sizeof(Array[0]);
    
    dispaly(Array, n);       // Before sort
    SelectionSort(Array, n); // to sorted
    dispaly(Array, n);       // after sort
    
    /*
     Algo-> selecting smallest element from the array and (swap) place it's right place.
     
     Space complexity : O(1)
     Time complexity :
      Average Case -> O(n^2)
      Best Case (if Array is already sorted ) -> O(n^2)
      Worst Case -> O(n^2)
         
     Use Case :
       1. Use when we have memory constraints (less memorey).
       2. effecient/good for small array.
        
    */
    
    return 0;
}
