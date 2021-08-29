#include<iostream>
using namespace std;
int isSortedArr(int Arr[],int n){
    if(n==1)
       return 1;

    return (Arr[n-2] > Arr[n-1])?0:isSortedArr(Arr,n-1);

}
int main()
{
    int Arr[]={1,3,5,8,9};
    int size = sizeof(Arr)/sizeof(Arr[0]);
    int ans = isSortedArr(Arr,size);
  (ans)?cout<<"\nis Sorted .":cout<<"\nis Not Sorted !."<<endl;

    return 0;
}