#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void FindTargetSumSubset(bool DP[5 + 1][10 + 1], int Set[], int sum, int set_n)
{
    for (int i = 0; i <= set_n; i++)
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
int main()
{
    int Set[] = {4, 2, 7, 1, 3}; //subsets like = {Empty set} ,{4} {2,3},{4,7},{2,7,1}....
    int sum = 10;

    int set_n = sizeof(Set) / sizeof(Set[0]);

    bool DP[5 + 1][10 + 1];
    memset(DP, false, sizeof(DP));

    FindTargetSumSubset(DP, Set, sum, set_n);

    (DP[5][10]) ? cout << "\nTarget sum subset is present ." : cout << "\nTarget sum subset is Not present !";

    return 0;
}