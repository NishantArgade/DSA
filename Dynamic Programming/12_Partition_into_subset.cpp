#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void partitionIntoSubset(int dp[5][6], int people, int team)
{
    for (int i = 1; i <= team; i++)
    {
        for (int j = 1; j <= people; j++)
        {
            if (i == j) // there is only one way to partitiat if (no.people == no.team)
                dp[i][j] = 1;
            else if (j < i) // you cannot partitiate less people into more team
                dp[i][j] = 0;
            else // no.people > no. team
                dp[i][j] = i * dp[i][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[4][5];
}
int main()
{                   /*   
    Q. How many ways you can partitiate 5 people into 4 teams ?
                      
   ans :     DP           People(p) j
                   \    0  1  2  3  4  5 
                    \ ------------------
              i  0  |  0  0  0  0  0  0 
            (t)  1  |  0  1  1  1  1  1
            team 2  |  0  0  1  3  7  15
                 3  |  0  0  0  1  10 45  
                 4  |  0  0  0  0  1  49    
                       

  ans: 49 different ways you can partitate 5 people into 4 team
  ex. teams
  1-2-3-45
  1-23-4-5
  14-2-3-5...........so on total 49 ways you can
 */
    int people = 5; // pepole
    int team = 4;   // teams

    int dp[4 + 1][5 + 1];
    memset(dp, 0, sizeof(dp));

    partitionIntoSubset(dp, people, team);
    return 0;
}