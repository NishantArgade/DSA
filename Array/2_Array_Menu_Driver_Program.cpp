#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int lenght;

public:
    Array()
    {
        size = 10;
        A = new int[size];
        lenght = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new int[size];
        lenght = 0;
    }
    ~Array()
    {
        delete[] A;
    }
    void Append(int x);
    void Insert(int index, int x);
    void Delete(int index);
    void Display();
    void swap(int *x, int *y);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    int Average();
    void Reverse();
    void Reverse2();
    void InsertinSortedArr(int x);
    int isSorted();
    void ReArrange();
    void Merge(struct Array *arr1,struct Array *arr2,struct Array *arr3);
};

void Array::Append(int x) // Arrgument pass by reference(i want reflect changes)
{
    if (lenght < size)
        A[lenght++] = x;
}
void Array::Insert(int index, int x)
{
    if (index >= 0 && index < size)
    {
        for (int i = lenght - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }

        A[index] = x;
        lenght++;
    }
}
void Array::Delete(int index)
{
    if (index >= 0 && index < size)
    {
        for (int i = index; i < lenght; i++)
        {
            A[i] = A[i + 1];
        }

        lenght--;
    }
}
void Array::Display() // Arrgument pass by Value(i don't want reflect changes)
{
    cout << "Elements are : \n";

    for (int i = 0; i < lenght; i++)
        cout << A[i]<<" ";
    cout << "\n";
}
void Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int Array::LinearSearch(int key)
{
    for (int i = 0; i < lenght; i++)
    {
        if (A[i] == key)
        {
            // swap(&arr->A[i], &arr->A[0]); // for Optimal solution.
            return i;
        }
    }
    return -1;
}
int Array::BinarySearch(int key)
{ // for that Array must be Sorted.

    int l, mid, h;
    l = 0;
    h = lenght - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            l = mid + 1;
        else if (A[mid] > key)
            h = mid - 1;
    }
    return -1;
}

int Array::Get(int index)
{
    if (index >= 0 && index < lenght)
        return A[index];
}
void Array::Set(int index, int x)
{
    if (index >= 0 && index < lenght)
        A[index] = x;
}
int Array::Max()
{
    int max = A[0];
    for (int i = 1; i < lenght; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
int Array::Min()
{
    int min = A[0];
    for (int i = 1; i < lenght; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}
int Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < lenght; i++)
    {
        sum = sum + A[i];
    }
    return sum;
}
int Array::Average()
{
    int Total_sum = Sum();
    int avg = (Total_sum) / lenght;
    return avg;
}
void Array::Reverse()
{
    int *B = (int *)malloc(lenght * sizeof(int));
    for (int i = lenght - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    for (int i = 0; i < lenght; i++)
    {
        A[i] = B[i];
    }
    delete (B);
}
void Array::Reverse2()
{
    for (int i = 0, j = lenght - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}
void Array::InsertinSortedArr(int x)
{

    int i = lenght - 1;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    lenght++;
}
int Array::isSorted()
{

    for (int i = 0; i < lenght; i++)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}
void Array::ReArrange() // -ve on Left Side and +ve on Right side.
{
    int i = 0, j = lenght - 1;

    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            swap(&A[i], &A[j]);
    }
}

int main()
{
    struct Array arr(20);
    struct Array arr2(20);
    struct Array arr3(40);

    cout << "1.Append\n"
         << "2.Insert\n"
         << "3.Delete\n"
         << "4.Display\n"
         << "5.Linear Search \n"
         << "6.Binary Search\n"
         << "7.Get\n"
         << "8.Max\n"
         << "9.Min\n"
         << "10.Sum\n"
         << "11.Average\n"
         << "12.Reverse1\n"
         << "13.Reverse2\n"
         << "14.is Sorted Array\n"
         << "15.Insert element in right position in sorted array\n"
         << "16.Re-Arrange All element \n"
         << "17.Exit\n";
    int ch, ele, ind;
    do
    {
        cout << "Enter Choice : \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Append ele : \n";
            cin >> ele;
            arr.Append(ele);
            break;

        case 2:
            cout << "Enter Insert ele : \n";
            cin >> ele;
            cout << "Enter index : \n";
            cin >> ind;
            arr.Insert(ind, ele);
            break;

        case 3:
            cout << "Enter index for deleting: \n";
            cin >> ind;
            arr.Delete(ind);
            break;

        case 4:
            arr.Display();
            break;

        case 5:
            cout << "Enter Search  element : \n";
            cin >> ele;
            cout << "Element is found at index : "<<arr.LinearSearch(ele)<<endl;
            break;

        case 6:
            cout << "Enter Search element : \n";
            cin >> ele;
            cout << "Element is found at index : "<< arr.BinarySearch(ele)<<endl;
            break;
        case 7:
            cout << "Enter index for Searching element : \n";
            cin >> ind;
            cout << "Element is found at index "<< ind <<" is : "<< arr.Get(ind)<<endl;
            break;
            

        case 8:
            cout << "The Maximum Element is : " << arr.Max()<<endl;
            break;

        case 9:
            cout << "The Mnimum Element is : " << arr.Min()<<endl;
            break;

        case 10:
            cout << "The Total Sum of Elements is : "<< arr.Sum()<<endl;
            break;

        case 11:
            cout << "The Average of Elements is :  "<< arr.Average()<<endl;
            break;

        case 12:
            cout << "The Reverse Array is : \n";
            arr.Reverse();
            arr.Display();
            break;

        case 13:
            cout << "The Reverse Array is : \n";
            arr.Reverse2();
            arr.Display();
            break;

        case 14:
            cout << "is The Sorted Array ? : "
                 << arr.isSorted()<<endl;
            break;

        case 15:
            cout << "Enter Inserted element : \n";
            cin >> ele;
            arr.InsertinSortedArr(ele);
            break;

        case 16:
            cout << "The ReArrange Array is : "<< endl;
            arr.ReArrange();
            arr.Display();
            break;

        default:
            break;
        }

    } while (ch < 17);
    return 0;
}