#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *arr,int n){// take reference(i.e Address) of array for here changes will reflected in main array  

printf("\nBubble Sort\n");
    
for (int i = 1; i < n; i++)// for No. passes( n-1 )
{
    bool swapped = false;
    
    for (int j = 0; j < n-i-1; j++)// for No. compersions( n-i )
    {
      if(arr[j] > arr[j+1]){
          int temp = arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
          swapped = true;
      }
    }
    if(swapped == false) // already sorted
        break;
}

}
void dispaly(int arr[],int n){
   
   for (int i = 0; i < n; i++)
       printf("%d ",arr[i]);        
}

int main()
{	
    int Array[]={11,2,13,4,15};
    int n = sizeof(Array)/sizeof(Array[0]);
    dispaly(Array,n);// Before sort
    BubbleSort(Array,n);// to sorted
    dispaly(Array,n);// after sort
    
    /*
    Algo-> place ith largest element in it's correct place.
          1. run For loop for n-1 rounds
          2. run 2nd For loop for campairing ele if( ele[i] > ele[i+1] ) swap
     
    S.C -> O(1)
    T.C :
    Average T.C -> O(n^2)
    Best T.C (if array is already sorted)-> O(n)
    Worst T.C -> O(n^2)
        
    Use Case:
      1. place ith largest element in it's right place in ith round.
  
  */
    return 0;
}
