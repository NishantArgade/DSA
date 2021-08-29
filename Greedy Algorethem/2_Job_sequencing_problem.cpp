#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void SortAccorProfit(char jobs[], int profit[], int Deadline[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                //Swap for arrange in Decreasing order
                char t1 = jobs[i];
                int t2 = profit[i], t3 = Deadline[i];

                jobs[i] = jobs[j];
                jobs[j] = t1;

                profit[i] = profit[j];
                profit[j] = t2;

                Deadline[i] = Deadline[j];
                Deadline[j] = t3;
            }
        }
    }
}
void printMaxprofitSeq(char timeSlot[], int n)
{
    int i = 1;
    cout << "\n\nFollowing are Maximum Profit sequence of job :\n";
    while (i < n)
    {
        if (timeSlot[i] != 0)
            cout << timeSlot[i] << " ";
        i++;
    }
}
void JobSequence(char jobs[], int profit[], int Deadline[], int n)
{
    char timeSlot[n] = {0};
    SortAccorProfit(jobs, profit, Deadline, n);

    for (int j = 0; j < n; j++)
    {
        for (int i = Deadline[j]; i > 0; i--)
        {
            if (timeSlot[i] == 0) // Check free space is Available or not .if so then
            {
                timeSlot[i] = jobs[j];
                break;
            }
        }
    }
    printMaxprofitSeq(timeSlot, n);
}
int main()
{ /*  Maximization / Minimization + constrants(Condition) if so then use Greedy aproach.

     Timeslot:
              0  C  A  E  0  0 
              0--1--2--3--4--5
    Aprroch:
    Arrange jobs according to Profit 
    A--C--D--B--E 
    Fill time slot Acorrding to Deadline.

*/
    char jobs[] = {'A', 'B', 'C', 'D', 'E'};
    int profit[] = {100, 19, 27, 25, 15};
    int Deadline[] = {2, 1, 2, 1, 3};

    int n = sizeof(jobs) / sizeof(jobs[0]);
    JobSequence(jobs, profit, Deadline, n);

    return 0;
}