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
int main()
{ /* BFS / DFS:
            (1)
          /     \  
        (5)-----(2)
         |       | 
        (4)-----(3)     */

    vector<int> adj[V + 1];
    Add_edge(adj, 1, 2);
    Add_edge(adj, 2, 3);
    Add_edge(adj, 3, 4);
    Add_edge(adj, 4, 5);
    Add_edge(adj, 5, 1);
    Add_edge(adj, 5, 2);

    Display(adj);
    return 0;
}