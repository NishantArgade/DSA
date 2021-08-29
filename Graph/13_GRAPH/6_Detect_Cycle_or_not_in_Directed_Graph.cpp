#include <iostream>
#include <vector>

using namespace std;

#define V 5

void Add_edge(vector<int> adj[V], int v1, int v2)
{
    adj[v1].push_back(v2);
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

bool CheckCycle_DFS(vector<int> adj[V + 1], int visited[V + 1], int helper[V + 1], int v)
{
    visited[v] = 1;
    helper[v] = 1;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int node = adj[v][i];

        if (visited[node] == 0)
        {
            if (CheckCycle_DFS(adj, visited, helper, node))
                return true;
        }
        else if (visited[node] == 1 && helper[node] == 1) //if helper 1 then cycle exists
            return true;
        else if (visited[node] == 1 && helper[node] == 0) //if helper 0 then cycle is not exists
            return false;
    }
    helper[v] = 0; // at the returning time mark helper as

    return false;
}
bool hasCycle(vector<int> G[V + 1])
{
    int visited[V + 1] = {0};
    int helper[V + 1] = {0};

    for (int i = 1; i <= V; i++)
    {
        if (visited[i] == 0)
        {
            if (CheckCycle_DFS(G, visited, helper, i))
                return true;
        }
    }
    return false;
}

int main()
{ /* Check Cycle or not in Directed Graph Using DFS:

    Logic: the helper  at returning time mark it as 0
          if visted and helper is 1 then cycle is exists         
          if visted and helper is 0 then cycle is Not exists    

   (1)-->(2)---->(3)
          |       | <= 3 to 4
2 to 5 =>|       | 
        (5)<----(4)     */

    vector<int> adj[V + 1];

    Add_edge(adj, 1, 2);
    Add_edge(adj, 2, 3);
    Add_edge(adj, 3, 4);
    Add_edge(adj, 4, 5);
    Add_edge(adj, 2, 5); //Here Due to this edge can't make Cycle bcs direction of edge(2->5)

    Display(adj);

    if (hasCycle(adj))
        cout << "Given Graph Has Cycle . ";
    else
        cout << "Given Graph Has not Cycle ! ";

    return 0;
}