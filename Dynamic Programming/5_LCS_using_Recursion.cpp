#include <iostream>
using namespace std;

int LongestCommonSubsequence(string S1,string S2 ,int i, int j)
{
    if (S1[i]=='\0'|| S2[j] == '\0')
        return 0;

    else if (S1[i] == S2[j])
        return 1 + LongestCommonSubsequence(S1,S2,i + 1, j + 1);

    return max(LongestCommonSubsequence(S1,S2,i + 1, j), LongestCommonSubsequence(S1,S2,i, j + 1));
}
int main()
{ /*
   # Longest Common Subsequence using Recursion.
  Time Complexcity : 2^n (exponential)
         */
    string S1 = "stone";
    string S2 = "longest";

    int ans = LongestCommonSubsequence(S1,S2,0,0);
    cout << "Longest Common Subsequence is " << ans;

    return 0;
}