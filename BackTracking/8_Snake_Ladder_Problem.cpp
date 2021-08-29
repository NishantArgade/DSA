#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct QueueEntry
{
    int v;
    int step;
};
// This Function Return Min number of Dice throws require to reach last cell
// from 0 th cell in snake ladder game.
int getMinDiceThrows(int GameBoard[], int cell)
{
    int visited[cell];
    memset(visited, 0, sizeof(visited)); // Set all 0 (mark as unvisited)

    // Create Queue for BFS:
    queue<QueueEntry> q;
    QueueEntry start, temp;

    start.v = 0, start.step = 0;
    visited[0] = 1;

    q.push(start);

    while (!q.empty())
    {
        temp = q.front();
        int ind = temp.v;
        q.pop();

        if (ind == cell - 1)
            break;

        for (int j = ind + 1; j <= (ind + 6) && (j < cell); j++)
        {
            if (!visited[j])
            {
                QueueEntry a;

                // Check if any Ladder or snake is found
                if (GameBoard[j] != -1)
                    a.v = GameBoard[j];

                else
                    a.v = j;

                //set Dice throw tie(chance)
                a.step = (temp.step) + 1;

                visited[j] = 1;
                q.push(a);
            }
        }
    }
    return temp.step;
}
int main()
{ /* Snake Ladder Problem:

   # GameBoard :
    
    Total cell = 30;
    ----------------------------
    |  24  25  26  27  28  29  |
    |  23  22  21  20  19  18  |
    |  12  13  14  15  16  17  |
    |  11  10  9   8   7   6   |
    |  00  1   2   3   4   5   |
    ----------------------------

    Ladder : 2-21, 4-7, 10-25, 19-28 . 
    Snake :  26-00, 20-8, 16-3, 18-6 .
  
  # use Data Structure:

  1. 1D Array for GameBoard Representation.
  2. Queue for BFS
  3. visited Array for mark as visited.

  Time Compx: O(cell) = O(n)
  Space Compx: O(cell) = O(n)         */

    int cell = 30;
    int GameBoard[cell] = {-1, -1, 21, -1, 7, -1, -1, -1, -1, -1, 25, -1, -1, -1, -1, -1, 3, -1, 6, 28, 8, -1, -1, -1, -1, 0, 1, -1, -1, -1};
    //       index:         0  1   2   3   4   5   6   7   8   9  10  11   12  13  14  15 16  17 18 19  20 21  22  23  24  25 26 27  28  29

    cout <<"\n\nMin Dice Thrwos required for to reach destenation is : " << getMinDiceThrows(GameBoard, cell);
    return 0;
}