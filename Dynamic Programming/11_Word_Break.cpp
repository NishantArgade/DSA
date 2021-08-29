#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

bool ContainWord(string wordDictionary[], string s, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (wordDictionary->compare(s) == 0)
            return true;
    }
    return false;
}
bool iswordbreak(string wordDictionary[], string s, int n)
{
    int l = s.length();
    bool dp[l + 1];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= l+1; i++)
    {
        dp[i] = false;
    }
    
       // i go from 1 to 11
    for (int i = 1; i <= l; i++)
    {
        if (dp[i] == false && ContainWord(wordDictionary, s.substr(0, i), n))
        {
            dp[i] = true;
        }
        if (i == l && dp[i] == true)
            return true;

        for (int j = i + 1; j <= l; j++)
        {
            if (dp[j] == false && ContainWord(wordDictionary, s.substr(i, j - i), n))
            {
                dp[j] = true;
            }
            if (j == l && dp[j] == true)
                return true;
        }
    }
    return false;
}
int main()
{ /*
  Word break Problem:
dic[]= {cycle ,like,nishant,mango};
  l = 11
         0 1 2 3 4 5 6 7 8 9 10 11
string = n i s h a n t l i k e  \0
                       i        j                  
dp[] =  f f f f f f f T f f  f  T
       0 1 2 3 4 5 6 7 8 9  10 11 
*/
    int n;
    cout << "Enter Size of Dictionary  :\n";
    cin >> n;
    cout << "Enter Dictionary :\n";
    string WordDictionary[n];
    for (int i = 0; i < n; i++)
        cin >> WordDictionary[i];

    string str;
    cout << "Enter String :\n";
    cin >> str;
    iswordbreak(WordDictionary, str, n) ? cout << "Given String is breakable for given words dic" : cout << "Given string is not breakable for given word dic!";
    return 0;
}