#include <iostream>
#include <bits/stdc++.h> // memset
using namespace std;

#define n 6
bool isSafe(int maze[n][n], int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1)
        return true;

    return false;
}
bool RatMazeProblem(int maze[n][n], int x, int y, int sol[n][n])
{
    // Base condition.
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
    //Check current position for maze is safe or not .
    if (isSafe(maze, x, y))
    {
        sol[x][y] = 1;

        if (RatMazeProblem(maze, x + 1, y,sol))
            return true;
        if (RatMazeProblem(maze, x, y + 1,sol))
            return true;
        maze[x][y] = 0;
    }
    return false;
}

int main()
{
    int maze[n][n] = {
        {1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1, 1}, //=>rat Out
    };
    int sol[n][n];
    memset(sol, 0, sizeof(sol));

    if (RatMazeProblem(maze, 0, 0, sol))
    {
        cout <<"\nThe Exit path for rat is :\n"<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout <<maze[i][j]<<" ";
            }
            cout << endl;
        }
    }
    else
        cout << "Rat Couldn't Exit from given maze,\nNo any path exists for Exit !";

    return 0;
}
