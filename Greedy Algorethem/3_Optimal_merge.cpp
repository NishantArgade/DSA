#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Optimal_Merge(char Arrs[], int Size[], int n)
{
    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int i = 0; i < n; i++)
        minheap.push(Size[i]);

    while (minheap.size() != 1)
    {
        int left = minheap.top();
        minheap.pop();
        int right = minheap.top();
        minheap.pop();

        minheap.push(left+right);
    }

    return minheap.top();
}

int main()
{ /* Optimal Merge:
   
    Approch: This is minimization + optimaization problem use Greedy Approch(follow perticular procedure) to solved it.

    logic:  
    1.Alway Select two low size Arr ,& Add them the process will continue until remain one Resultant size.
    2.At the end we have optimal size after merge of this arrays .
    
    
    */
    char Arrs[] = {'A', 'B', 'C', 'D'};
    int Size[] = {10, 6, 80, 34};
    int n = sizeof(Arrs) / sizeof(Arrs[0]);

    int Optimal_size = Optimal_Merge(Arrs, Size, n);

cout<<"\nAfter Merge Optimal size will be of resultant Array is "<<Optimal_size;
    

    return 0;
}