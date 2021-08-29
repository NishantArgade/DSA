#include <iostream>
using namespace std;

int LongestCommonSubsequence(string S1, string S2, int Memoization[][7], int i, int j)
{
    if (S1[i] == '\0' || S2[j] == '\0')
        return Memoization[i][j] = 0;
    
    else if (S1[i] == S2[j])
        return Memoization[i][j] = 1 + Memoization[i+1][j+1];
          
   return Memoization[i][j] = max(LongestCommonSubsequence(S1, S2, Memoization, i + 1, j), LongestCommonSubsequence(S1, S2, Memoization, i, j + 1));
}
int main()
{ /*
   # Longest Common Subsequence using Recursion.
  Time Complexcity : (mxn) = n^2 (Optimize) Bcs Avoid overlapping
         */
    string S1 = "stone";
    string S2 = "longest";

 int Memoization[5][7] = {0};

    LongestCommonSubsequence(S1, S2, Memoization, 0, 0);
    cout << "\nLongest Common Subsequence is " << Memoization[0][0];

    return 0;
}