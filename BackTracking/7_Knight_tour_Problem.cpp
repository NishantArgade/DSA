#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define n 8

bool isSafe(int Board[n][n], int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && Board[x][y] == -1)
        return true;

    return false;
}
bool KnightTour(int Board[n][n], int x, int y, int move, int xdis[n], int ydis[n])
{

    // Base Case
    if (move == n * n)
        return true;

    for (int step = 0; step < 8; step++)
    {

        int nx = x + xdis[step],
            ny = y + ydis[step];

        if (isSafe(Board, nx, ny))
        {
            Board[nx][ny] = move;

            if (KnightTour(Board, nx, ny, move + 1, xdis, ydis))
                return true;

            Board[nx][ny] = -1;
        }
    }
    return false;
}
int main()
{ //Each Knight has at most 8 posible setp:
    // Knight ( setps ) Co-ordinates

    int Board[n][n];
    memset(Board, -1, sizeof(Board)); // initialize all are -1
    Board[0][0] = 0;

    int xdis[n] = {2, 1, -1, -2, -2, -1, 1, 2};
    int ydis[n] = {1, 2, 2, 1, -1, -2, -2, -1};

    if (KnightTour(Board, 0, 0, 1, xdis, ydis))
    {
        cout << "\nThe Knight Tour on board is :\n"
             << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << Board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Knight Tour cannot posible!";

    return 0;
}