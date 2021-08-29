

#include <iostream>
using namespace std;

#define V 4

bool isSafe(int Graph[V][V], int vertex[V], int k, int v)
{
    if (Graph[k - 1][k] == 1)
    {
        for (int i = 0; i < V; i++)
        {
            if (v == vertex[i])
                return false;
        }
    }
    return true;
}

bool hamiltonincycleutil(int Graph[V][V], int vertex[V], int i)
{
    // Recursive Case.
    if (i == V)
        return true;

    for (int v = 1; v <= V; v++) // Assign vertex(1,2,3...)
    {
        if (isSafe(Graph, vertex, i, v))
        {
            vertex[i] = v;

            if (hamiltonincycleutil(Graph, vertex, i + 1))
                return true;

            vertex[i] = 0;
        }
    }
    return false;
}
void print_Solution(int vertex[V])
{
    cout << "Hameltonin cycle may be like as :" << endl;
    for (int i = 0; i < V; i++)
        cout << vertex[i] << " ";
    
}
int main()
{    // note taht This function print most appropriate one solution
    // Graph Adjecent Matrix representation.
    int Graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};

    /*                  (4)--(3) 
                         |  / |
                         | /  |
                         |/   |
                        (1)--(2) 
                   
      */
    int size = sizeof(Graph) / sizeof(Graph[0]);
    int vertex[V] = {0, 0, 0, 0};

    int i = 0;

    if (hamiltonincycleutil(Graph, vertex, i))
        print_Solution(vertex);
    else
        cout << "Solution does not exists !";

    return 0;
}