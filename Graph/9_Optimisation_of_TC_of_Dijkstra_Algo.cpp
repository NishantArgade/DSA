#include <iostream>
#include <limits.h>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

#define I INT_MAX
#define V 6
#define n 7

typedef pair<int, int> p;

// Search Min cost vertex Min Heap do this in O(n) TC.
int findMinCostVertex(priority_queue<p, vector<p>, greater<p>> Minheap, int visited[])
{

    p pai = Minheap.top();
    int min_ind = pai.second;
    Minheap.pop();
    return min_ind;
}
int VertexDis(priority_queue<p, vector<p>, greater<p>> Minheap, int vertex)
{
    static int min_cost = 0;
    p x = Minheap.top();

    if (x.second == vertex)
    {
        min_cost = x.first;
        return min_cost;
    }
    else
        Minheap.pop();

    // Minheap.pop();
    min_cost = VertexDis(Minheap, vertex);
    Minheap.push(make_pair(x.first, x.second));
    return min_cost;
}
void updateDis(priority_queue<p, vector<p>, greater<p>> Minheap, int vertexCost,int updatedCost)
{
    // static int min_cost = 0;
    p x = Minheap.top();

    if (x.first == updatedCost)
    {
        int ind = x.second;
        Minheap.pop();
        Minheap.push(make_pair(vertexCost, ind));
         return;
    }
    else
        Minheap.pop();

    updateDis(Minheap, vertexCost,updatedCost);
    Minheap.push(make_pair(x.first, x.second));
    return;
}
void DijkstraAlgo(int Graph[n][n], int start)
{
    priority_queue<p, vector<p>, greater<p>> Minheap; // in cpp priority_queue means heap
    int parent[n];
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        if (i == start)
            Minheap.push(make_pair(0, i));
        else
            Minheap.push(make_pair(I, i));

        parent[i] = -1;
        visited[i] = 0;
    }

    parent[start] = start;
    // do Relaxe all adjecents  of min cost vertex(v)
    for (int i = 1; i <= V - 1; i++)
    {
        int v = findMinCostVertex(Minheap, visited);
        int vdis = VertexDis(Minheap, v);
        visited[v] = 1;

        for (int j = 1; j <= V; j++)
        {

            if (Graph[v][j] != 0)
            {
                int adj = j;
                int u =vdis + Graph[v][adj];
                int v = VertexDis(Minheap, adj)  ;

                if ( u < v)
                {
                    updateDis(Minheap,u,v);
                    parent[adj] = v;
                }
            }
        }
    }
    // print
    for (int v = 1; v <= V; v++)
    {
        p t = Minheap.top();
        cout << "The Shortest Distance up to " << t.second << " is " << t.first << endl;
      Minheap.pop();
    }
}
int main()
{
    /* Dijkstra Algorethem for find shortest path:
                           7
                     (2)------>(4)
    1->2---------->2/ |        ^ \1<----------- 4 to 6
                 (1) 1|<- 2-3  |2 (6)
    1->3--------->4\  |        | /5<------------ 5 to 6
                    (3)----->(5)
                         3

    *Use Data Structure* :
    
    distance[7]={I , 0 , I , I , I , I , I }    
                 0   1   2   3   4   5   6  
    
    parent[7]={-1 , -1 , -1 , -1 , -1 ,-1 }    
               0   1   2   3   4   5   6  
    
    visited[7]={0, 0 , 0 , 0 , 0 , 0 , 0 }    
               0   1   2   3   4   5   6  
   Logic:
   if(dis[1] + C(1,2) < dis[2])
       dis[2]= dis[1]+ c(1,2)

       TC= O(n^2) for Opitimise solution you can use min Heap or set for find min cost vertex.
*/
    //      1  2  3  4  5  6
    int Graph[n][n] = {
        {0, 0, 0, 0, 0, 0, 0},

        {0, 0, 2, 4, 0, 0, 0}, //1
        {0, 0, 0, 1, 7, 0, 0}, //2
        {0, 0, 0, 0, 0, 3, 0}, //3
        {0, 0, 0, 0, 0, 0, 1}, //4
        {0, 0, 0, 0, 2, 0, 5}, //5
        {0, 0, 0, 0, 0, 0, 0}  //6

    };
    DijkstraAlgo(Graph, 1);

    return 0;
}