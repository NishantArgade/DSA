

#include <iostream>
using namespace std;

#define V 4

void print_Solution(int x[V]);

void NextVertex(int Graph[V][V], int x[], int k, int n)
{
    do
    {
        x[k] = (x[k] + 1) % (n + 1);

        if (x[k] == 0)
            return;

        int j;
        if (Graph[k - 1][k] == 1)
        {
            for (j = 1; j < k; j++)
            {
                if (x[j] == x[k])
                    break;
            }
            if (j == k)
            {
                if (k < n || (k == n) && Graph[x[n], x[1]] != 0)
                    return;
            }
        }

    } while (true);
}

void hamiltonincycleutil(int Graph[V][V], int n, int x[], int k)
{
    do
    {
        NextVertex(Graph, x, k, n);

        if (x[k] == 0)
            return;

        if (k == n)
            print_Solution(x);

        else
            hamiltonincycleutil(Graph, n, x, k + 1);
    } while (true);
}
void print_Solution(int x[V])
{
    cout << endl;
    for (int k = 1; k <= V; k++)
        cout << x[k] << " ";
}
int main()
{ // note taht This function print most appropriate one solution
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
    int x[] = {0, 0, 0, 0, 0};

    int k = 1;

    hamiltonincycleutil(Graph, V, x, k);

        return 0;
}