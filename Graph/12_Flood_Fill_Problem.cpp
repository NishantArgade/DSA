#include <iostream>
#include <limits.h>
using namespace std;

#define n 7

void printSol(int Graph[n][n])
{
    cout << "Flood Fill  Matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int Graph[n][n], int row, int col, int Oldcolor, int Newcolor)
{
    //here Oldcolor = 1 and Newcolor = 8
    if (row >= 0 && row < n && col >= 0 && col < n && Graph[row][col] == Oldcolor)
    {

        Graph[row][col] = Newcolor;

        DFS(Graph, row - 1, col, Oldcolor, Newcolor);
        DFS(Graph, row + 1, col, Oldcolor, Newcolor);
        DFS(Graph, row, col - 1, Oldcolor, Newcolor);
        DFS(Graph, row, col + 1, Oldcolor, Newcolor);
    }
}
void FloodFill(int Graph[n][n], int sr, int sc, int newColor)
{
    if (newColor == Graph[sr][sc])
        printSol(Graph);

    else
    {
        DFS(Graph, sr, sc, Graph[sr][sc], newColor);
        printSol(Graph);
    }
}
int main()
{
    // Flood Fill Problem:
    //   TC= O(n^2)
    // Real Life Use:
    //in Computer paint use for give color to the drowing.
    int Graph[n][n] = {

        {1, 1, 1, 2, 4, 5, 6},
        {3, 1, 1, 2, 4, 5, 6},
        {2, 1, 1, 2, 4, 2, 5},
        {3, 3, 1, 3, 4, 2, 7},
        {3, 3, 1, 1, 1, 1, 1},
        {4, 6, 4, 1, 1, 1, 1},
        {3, 3, 3, 1, 1, 1, 1}

    };
    //here Oldcolor = 1 and Newcolor = 8
    FloodFill(Graph, 1, 1, 8);

    return 0;
}