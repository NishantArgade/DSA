#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindTargetSumSubset(bool DP[5 + 1][9 + 1], int Set[], int sum, int set_ele)
{
    for (int i = 0; i <= set_ele; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
                DP[i][j] = true;

            else if (i == 0)
                DP[i][j] = false;

            else if (j == 0)
                DP[i][j] = true;

            else
            {

                if (DP[i - 1][j] == true)
                    DP[i][j] = true;

                else
                {
                    int value = Set[i - 1];

                    if (value <= j)
                    {
                        if (DP[i - 1][j - value] == true)
                            DP[i][j] = true;
                    }
                }
            }
        }
    }
}

bool isPartitiatSetForgivenTarget(int Set[], int set_ele)
{
    bool DP[5 + 1][9 + 1]; // total of sum of set is 18 so that 18/2=9 column is take
    memset(DP, false, sizeof(DP));
    int SetEleSum = 0;

    for (int i = 0; i < set_ele; i++)
        SetEleSum += Set[i];

    if (SetEleSum % 2 != 0) // if sum is odd then can not can partitiate
        return false;
    else
    { // if sum is even then Search subset is present or not for target sum/2
        FindTargetSumSubset(DP, Set, SetEleSum / 2, set_ele);
        if (DP[5][9])
            return true;

        else
            return false;
    }
}
int main()
{  /*  set={1,5,6,3,3}
    s1{1,5,3} == s2{6,3}
   */
    int Set[] = {1, 5, 2, 7, 3}; //subsets like = {Empty set} ,{4} {2,3},{4,7},{2,7,1}....

    int set_ele = sizeof(Set) / sizeof(Set[0]);

    (isPartitiatSetForgivenTarget(Set, set_ele)) ? cout << "\nYou can partitiat Given set into two subset such that there sum are equal ." : cout << "\nYou cannot partitiate into two part for given target sum !";

    return 0;
}