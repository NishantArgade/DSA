#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *arr,int n){// take reference(i.e Address) of array for here changes will reflected in main array  
int k =0;
printf("\nBubble Sort running ....\n");
for (int i = 1; i < n; i++)// for No. passes( n-1 )
{
    for (int j = 0; j < n-1-k; j++)// for No. compersions( n-i )
    {
      if(arr[j] > arr[j+1]){
          int temp = arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
      }
    }
    k++;
    
}

}
void dispaly(int arr[],int n){
   
   for (int i = 0; i < n; i++)
   {
       printf("%d ",arr[i]);      
   }    
}

int main()
{	
    int Array[]={11,2,13,4,15};
    int n = 5;
    dispaly(Array,n);// Before sort
    BubbleSort(Array,n);// to sorted
    dispaly(Array,n);// after sort
    return 0;
}