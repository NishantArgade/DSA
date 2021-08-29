

#include <iostream>
using namespace std;
#define V 4

void print_Solution(int colors[V])
{
    cout << "Colores may be given as :" << endl;
    for (int i = 0; i < V; i++)
    {

        cout << colors[i] << " ";
    }
}

bool isSafe(int Graph[V][V], int colors[V], int row, int c)
{
    for (int i = 0; i < V; i++)
    {
        if (Graph[row][i] == 1 && c == colors[i])
            return false;
    }
    return true;
}

bool graphColoring(int Graph[V][V], int colors[V], int i, int m)
{
    // Base Case :
    // Recursive Case.
    if (i == V)
        return true;

    for (int c = 1; c <= m; c++)// Assign colors(1=red,2=blue,3=green)
    {
        if (isSafe(Graph, colors, i, c))
        {
            colors[i] = c;   

            if (graphColoring(Graph, colors, i + 1, m) == true)
                return true;

            // printSloution(colors);
            colors[i] = 0;
        }
    }
    return false;
}
int main()
{ // Graph Adjecent Matrix representation.
    int Graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};

    /*                 Blue (3)--(2) Green
                             |  / |
                             | /  |
                             |/   |
                        Red (0)--(1) Blue
                   
      */          
    int size = sizeof(Graph) / sizeof(Graph[0]);
    int colors[V] = {0, 0, 0, 0};

    int m = 3; // no of colors
    int  i = 0;

    if (graphColoring(Graph, colors, i, m) == true)
        print_Solution(colors);
    else
        cout << "Solution does not exists !";

    return 0;
}