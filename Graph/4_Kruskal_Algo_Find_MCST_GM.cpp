#include <iostream>

#define I 32767 // Infinity
#define V 7     // # of vertices in Graph
#define E 9     // # of edges in Graph

using namespace std;

void PrintMCST(int T[][V - 1], int A[][E])
{
    cout << "\nMinimum Cost Spanning Tree Edges\n"
         << endl;
    for (int i{0}; i < V - 1; i++)
    {
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

// Set operations: Union and FindParent
void Union(int u, int v, int s[])
{
    if (s[u] < s[v])
    {
        s[u] += s[v];
        s[v] = u;
    }
    else
    {
        s[v] += s[u];
        s[u] = v;
    }
}

int FindParent(int u, int s[])
{
    int x = u;
    int v = 0;

    while (s[x] > 0)
    {
        x = s[x];
    }
    // Set/Update parent
    while (u != x)
    {
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}

void KruskalsMCST(int A[3][E])
{
    int T[2][V - 1];                                   // Solution array
    int Included[E]{0};                                // Track edges that are Included in solution
    int set[V + 1] = {-1, -1, -1, -1, -1, -1, -1, -1}; // Array for finding cycle

    int i = 0;

    while (i < V - 1)
    {

        int min = I;
        int u{0};
        int v{0};
        int k{0};

        // FindParent a minimum cost edge
        for (int j{0}; j < E; j++)
        {
            if (Included[j] == 0 && A[2][j] < min)
            {
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }

        // Check if the selected min cost edge (u, v) forming a cycle or not
        if (FindParent(u, set) != FindParent(v, set))
        {
            T[0][i] = u;
            T[1][i] = v;

            // Perform union/Joind
            Union(FindParent(u, set), FindParent(v, set), set);
            i++;
        }
        Included[k] = 1; // marked as Included
    }

    PrintMCST(T, A);
}

int main()
{
       /* Min Cost Spanning Tree.
    Spanning Tree: cover All vertices of graph with minimum edges,is called spanning tree.
    A Graph may have several spanning tree.

     Graph-    
               (A)
               /  \
             (B)--(C) 

     spanning Trees:

               (A)       (A)        (A)
               /         / \          \
             (B)--(C)  (B)  (c)   (B)--(C)
            
             
  NOTE: if Verteses (V) Then  Edges is V-1 number of edges in minimum cost spanning tree. 
   
   the spaning tree whose sum of all edges cost is minimum from other sappning tree is called minimum cost spanning tree.
   
    Required Data Structrue :
  check edges are included or not included.
  
    included = |0|0|0|0|0|0|0|0|0|
                0 1 2 3 4 5 6 7 8
 
    result(T) = 0| 1| | | | | |
               1| 6| | | | | |
                  0 1 2 3 4 5 
                
                (1)        
             5 /   \25
            (6)    (2)
            |   16/  |
          20|  (7)   |12
            |18/ |14 |
           (5)   |  (3)
            16\  | /8
               (4)      */

    int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                       {2, 6, 3, 7, 4, 5, 7, 6, 7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    KruskalsMCST(edges);

    return 0;
}