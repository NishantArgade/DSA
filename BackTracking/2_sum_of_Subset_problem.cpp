#include <iostream>
using namespace std;
// find (solution)subset of elements that selected in given set such taht whoes sum is k.

static int totalsets = 0;
#define TARGET_SUM 30

int partition(int Arr[], int low, int high)
{
    int pivot = Arr[low]; // set pivot as first index
    int i = low + 1;      // increase ( i++ --> ) untill pivot < number
    int j = high;         // decrease ( j--  <-- ) untill pivot >= number
    int Temp;

    while (i <= j)
    {

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

    if (j < i) // Here will swap and set pivot Right position : lower numbers(sort or unsort order) <-- pivot --> greater numbers(sort or unsort)
    {
        int temp;
        temp = Arr[low];
        Arr[low] = Arr[j];
        Arr[j] = temp;
    }

    return j; // return new seted pivot index ,lower numbers(sort or unsort order) <-- pivot --> greater numbers(sort or unsort)
}
void QuickSort(int Arr[], int low, int high)
{
    int partitionIndex;
    if (low < high) // min two block required,if one block then cannot sort bcs it is already sorted.
    {
        partitionIndex = partition(Arr, low, high);
        QuickSort(Arr, low, partitionIndex - 1);  // sort for left
        QuickSort(Arr, partitionIndex + 1, high); // sort for right
    }
}

void print_subset(int solutionSet[], int n)
{
    totalsets++;
    for (int i = 0; i < n; i++)
    {
        cout << solutionSet[i] << " ";
    }
    cout << endl;
}
void find_SolutionSet(int weights[], int w_itr, int n, int solutionSet[], int sol_pos, int sol_sum)
{
    if (sol_sum == TARGET_SUM)
    {
        print_subset(solutionSet, sol_pos);//here sol_pos become incremented
    }

    else
    {
        if (sol_sum + weights[w_itr] > TARGET_SUM)
            return;
        for (w_itr; w_itr < n; w_itr++)
        {
            if (sol_sum + weights[w_itr] > TARGET_SUM)
                break;

            solutionSet[sol_pos] = weights[w_itr];

            find_SolutionSet(weights, w_itr + 1, n, solutionSet, sol_pos + 1, sol_sum + weights[w_itr]);
        }
    }
}
int main()
{
    int weights[] = {10, 7, 5, 18, 12, 20, 15};

    int n = sizeof(weights) / sizeof(weights[0]);
    int solutionSet[n];
// convert into sorted formate
    QuickSort(weights, 0, n - 1);

    int TotalSum = 0;
    for (int i = 0; i < n; i++)
    {
        TotalSum += weights[i];
    }
    if (weights[0] <= TARGET_SUM && TotalSum >= TARGET_SUM)
        find_SolutionSet(weights, 0, n, solutionSet, 0, 0);

    cout << "Total number of Solutions subset is  : " << totalsets;

    return 0;
}