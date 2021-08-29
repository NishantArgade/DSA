#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int lenght;
};
void Append(struct Array *arr, int x) // Arrgument pass by reference(i want reflect changes)
{
    if (arr->lenght < arr->size)
        arr->A[arr->lenght++] = x;
}
void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->size)
    {
        for (int i = arr->lenght - 1; i >= index; i--)
        {
            arr->A[i + 1] = arr->A[i];
        }

        arr->A[index] = x;
        arr->lenght++;
    }
}
void Delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->size)
    {
        for (int i = index; i < arr->lenght; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }

        arr->lenght--;
    }
}
void Display(struct Array arr) // Arrgument pass by Value(i don't want reflect changes)
{
    printf("Elements are : \n");

    for (int i = 0; i < arr.lenght; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->lenght; i++)
    {
        if (arr->A[i] == key)
        {
            // swap(&arr->A[i], &arr->A[0]); // for Optimal solution.
            return i;
        }
    }
    return -1;
}
int BinarySearch(struct Array arr, int key)
{ // for that Array must be Sorted.

    int l, mid, h;
    l = 0;
    h = arr.lenght - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] < key)
            l = mid + 1;
        else if (arr.A[mid] > key)
            h = mid - 1;
    }
    return -1;
}
int Recur_BinarySearch(struct Array arr, int l, int h, int key)
{ // for that Array must be Sorted.

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] < key)
            return Recur_BinarySearch(arr, mid + 1, h, key);
        else if (arr.A[mid] > key)
            return Recur_BinarySearch(arr, l, mid - 1, key);
    }
    return -1;
}
int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.lenght)
        return arr.A[index];
}
void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->lenght)
        arr->A[index] = x;
}
int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.lenght; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}
int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.lenght; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.lenght; i++)
    {
        sum = sum + arr.A[i];
    }
    return sum;
}
int Average(struct Array arr)
{
    int Total_sum = Sum(arr);
    int avg = (Total_sum) / arr.lenght;
    return avg;
}
void Reverse(struct Array *arr)
{
    int *B = (int *)malloc(arr->lenght * sizeof(int));
    for (int i = arr->lenght - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->lenght; i++)
    {
        arr->A[i] = B[i];
    }
    free(B);
}
void Reverse2(struct Array *arr)
{
    for (int i = 0, j = arr->lenght - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}
void InsertinSortedArr(struct Array *arr, int x)
{

    int i = arr->lenght - 1;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->lenght++;
}
int isSorted(struct Array arr)
{

    for (int i = 0; i < arr.lenght; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}
int ReArrange(struct Array *arr) // -ve on Left Side and +ve on Right side.
{
    int i = 0, j = arr->lenght - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}
// Merge unique elements(no Dublicate) :
void Merge(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{

    int i = 0, j = 0, k = 0;
    while (i < arr1->lenght && j < arr2->lenght)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->lenght; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->lenght; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->lenght = k;
}
void Union(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{

    int i = 0, j = 0, k = 0;
    while (i < arr1->lenght && j < arr2->lenght)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->lenght; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->lenght; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->lenght = k;
}
void Intersection(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{

    int i = 0, j = 0, k = 0;
    while (i < arr1->lenght && j < arr2->lenght)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->lenght = k;
}
void Difference(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{

    int i = 0, j = 0, k = 0;
    while (i < arr1->lenght && j < arr2->lenght)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->lenght; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->lenght = k;
}

int main()
{
    struct Array arr;
    struct Array arr2;
    
    // Menu Driver program:
    int size;
    printf("Enter Size of Array :\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.lenght = 0;
    printf("1.Append\n");
    printf("2.Insert\n");
    printf("3.Delete\n");
    printf("4.Display\n");
    printf("5.Linear Search \n");
    printf("6.Binary Search\n");
    printf("7.Rcursive Binary Search\n");
    printf("8.Max\n");
    printf("9.Min\n");
    printf("10.Sum\n");
    printf("11.Average\n");
    printf("12.Reverse1\n");
    printf("13.Reverse2\n");
    printf("14.is Sorted Array\n");
    printf("15.Insert element in right position in sorted array\n");
    printf("16.Re-Arrange All element \n");
    printf("17.Exit\n");
    int ch, ele, ind;
    do
    {
        printf("Enter Choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Append ele : \n");
            scanf("%d", &ele);
            Append(&arr, ele);
            break;

        case 2:
            printf("Enter Insert ele : \n");
            scanf("%d", &ele);
            printf("Enter index : \n");
            scanf("%d", &ind);
            Insert(&arr, ind, ele);
            break;

        case 3:
            printf("Enter index for deleting: \n");
            scanf("%d", &ind);
            Delete(&arr, ind);
            break;

        case 4:
            Display(arr);
            break;

        case 5:
            printf("Enter Search  element : \n");
            scanf("%d", &ele);
            printf("Element is found at index : %d\n", LinearSearch(&arr, ele));
            break;

        case 6:
            printf("Enter Search element : \n");
            scanf("%d", &ele);
            printf("Element is found at index : %d\n", BinarySearch(arr, ele));
            break;

        case 7:
            printf("Enter Search element : \n");
            scanf("%d", &ele);
            printf("Element is found at index : %d\n", Recur_BinarySearch(arr, 0, arr.lenght - 1, ele));
            break;

        case 8:
            printf("The Maximum Element is : %d\n", Max(arr));
            break;

        case 9:
            printf("The Mnimum Element is : %d\n", Min(arr));
            break;

        case 10:
            printf("The Total Sum of Elements is : %d\n", Sum(arr));
            break;

        case 11:
            printf("The Average of Elements is : %d\n", Average(arr));
            break;

        case 12:
            printf("The Reverse Array is : \n");
            Reverse(&arr);
            Display(arr);
            break;

        case 13:
            printf("The Reverse Array is : \n");
            Reverse2(&arr);
            Display(arr);
            break;

        case 14:
            printf("is The Sorted Array ? : %d\n", isSorted(arr));
            break;

        case 15:
            printf("Enter Inserted element : \n");
            scanf("%d", &ele);
            InsertinSortedArr(&arr, ele);
            break;

        case 16:
            printf("The ReArrange Array is : %d\n", Average(arr));
            ReArrange(&arr);
            Display(arr);
            break;

        default:
            break;
        }

    } while (ch < 17);

    //=================================================================================
    // Creation Of array 3;

    printf("Enter Size of Array2 :\n");
    scanf("%d", &arr2.size);
    arr2.A = (int *)malloc(arr2.size * sizeof(int));
    arr2.lenght = 0;

    Append(&arr2, 40);
    Append(&arr2, 50);
    Append(&arr2, 60);

    struct Array arr3;
    arr3.A = (int *)malloc(arr.size + arr2.size * (sizeof(int)));
    
    // Merge(&arr, &arr2, &arr3);
    // Union(&arr, &arr2, &arr3);
    // Intersection(&arr, &arr2, &arr3);
    // Difference(&arr, &arr2, &arr3);

    Display(arr3);
    return 0;
}