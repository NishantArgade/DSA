#include <stdio.h>
// linear binary search (Unsorted):
int linerSearch(int array[], int data,int  size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == data)
        {
            return i;
        }

    }
    return -1;
}


int main()
{
    int arr[] = {2, 61, 17, 98, 7, 66, 5};
    int data = 17,size = 7;
    int index = linerSearch(arr, data,size);
    printf("%d",index);
    return 0;
}

// //  linear binary search (Sorted):
// int linerSearch(int array[], int data, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (array[i] == data)
//             return i;
        
//         else if (array[i] > data)
//             return -1;
//     }
//     return -1;
// }
// int main()
// {
//     int arr[] = {2, 61, 17, 98, 7, 66, 5};
//     int data = 17, size = 7;
//     int index = linerSearch(arr, data, size);
//     printf("%d", index);
//     return 0;
// }

