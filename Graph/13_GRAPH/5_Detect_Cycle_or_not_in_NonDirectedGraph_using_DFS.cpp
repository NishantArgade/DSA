#include <iostream>
#include <vector>

using namespace std;

#define V 5

void Add_edge(vector<int> adj[V], int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}
void Display(vector<int> adj[V])
{
    cout << "Adjecent List is :\n";
    for (int i = 1; i <= V; i++)
    {
        cout << "Vertex (" << i << ")";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << " --> " << adj[i][j];
        }
        cout << endl;
    }
}

bool CheckCycle_DFS(vector<int> adj[V + 1], int visited[V + 1], int v, int parent)
{
    visited[v] = 1;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int node = adj[v][i];

        if (visited[node] == 0)
        {
            if (CheckCycle_DFS(adj, visited, node, v))
                return true;
        }
        else if (visited[node] == 1 && node != parent)
            return true;
    }
    return false;
}
bool hasCycle(vector<int> G[V + 1])
{
    int visited[V + 1] = {0};

    for (int i = 1; i <= V; i++)
    {
        if (visited[i] == 0)
        {
            if (CheckCycle_DFS(G, visited, i, -1))
                return true;
        }
    }
    return false;
}

int main()
{ /* Check Cycle or not in Graph Using DFS:

  Logic: if Node is visited and it is not parent then cycle is exists
 otherwise it is not cycle exists
 
            (1)
          /       
        (5)-----(2)
         |       | 
        (4)-----(3)    */

    vector<int> adj[V + 1];

    Add_edge(adj, 2, 3);
    Add_edge(adj, 3, 4);
    Add_edge(adj, 4, 5); //Here this edge make Cycle
    Add_edge(adj, 5, 1);
    Add_edge(adj, 5, 2);

    Display(adj);

    if (hasCycle(adj))
        cout << "Given Graph Has Cycle . ";
    else
        cout << "Given Graph Has not Cycle ! ";

    return 0;
}