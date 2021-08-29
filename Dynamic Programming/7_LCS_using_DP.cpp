#include <iostream>
using namespace std;
#define m 6
#define n 8

void LongestCommonSubsequence(string S1, string S2, int Table[][8])
{
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (S1[i] == S2[j])
                Table[i][j] = 1 + Table[i - 1][j - 1];
            else
                Table[i][j] = max(Table[i - 1][j], Table[i][j - 1]);
        }
    }
}
int main()
{ /*
   # Longest Common Subsequence using Dinamic programing.
  Time Complexcity : (mxn) = n^2 (Optimize) Bcs Avoid overlapping
         */
    string S1 = " stone";
    string S2 = " longest";

    int Table[6][8] = {0};

    LongestCommonSubsequence(S1, S2, Table);
    cout << "\nLongest Common Subsequence is " << Table[5][7];

    return 0;
}