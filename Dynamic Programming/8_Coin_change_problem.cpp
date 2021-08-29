#include <iostream>
using namespace std;

#define c 3

int CoinChange_Recurr(int Coin[c], int Amount, int index)
{
    if (Amount == 0)
        return 1;

    if (Amount < 0 || index == c)
        return 0;

    int result = 0;
    for (int i = index; i < c; i++)
    {
        if (Amount >= Coin[i])
            result += CoinChange_Recurr(Coin, Amount - Coin[i], i);
    }
    return result;
}
int CoinChange_Dp(int T[3][6], int Coin[c], int Amount)
{
    for (int i = 0; i <= c; i++) // no.of coins
    {
        T[i][0] = 1;
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 1; j <= Amount; j++) // no.of rows
        {
            int includeCurrCoin = 0;
            int excludeCurrCoin = 0;

            if (Coin[i] <= j) // Hypothetical condition
                includeCurrCoin = T[i][j - Coin[i]];

            if (i > 0)
                excludeCurrCoin = T[i - 1][j];

            T[i][j] = includeCurrCoin + excludeCurrCoin;
        }
    }
    return T[c-1][Amount];
}
int main()
{
    int Amount = 5;
    int Coin[c] = {1, 2, 3};

    int Combination = CoinChange_Recurr(Coin, Amount, 0);
    cout << "\nThe number of Combination or No. of ways for to pay an Given Amount is :" << Combination;

    int T[3][6] = {0};
   int ways =  CoinChange_Dp(T, Coin, Amount);
    cout << "\nThe number of Combination or No. of ways for to pay an Given Amount is :" << ways;

    return 0;
}