#include <iostream>
#include <limits.h>
using namespace std;

#define I INT_MAX
#define V 6
#define n 7

int findMinCostVertex(int Dis[], int visited[])
{
    int min = INT_MAX, min_ind;
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i] && Dis[i] <= min)
        {
            min = Dis[i];
            min_ind = i;
        }
    }
    return min_ind;
}
void DijkstraAlgo(int Graph[n][n], int start)
{
    int Dis[n];
    int parent[n];
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        Dis[i] = I;
        parent[i] = -1;
        visited[i] = 0;
    }
    Dis[start] = 0;
    parent[start] = start;

    //Reapet V-1 vertices
    for (int t = 1; t <= V - 1; t++)
    {
        int v = findMinCostVertex(Dis, visited);
        visited[v] = 1;

        // do Relaxe all adjecents  of min cost vertex(v)
        for (int i = 1; i <= V; i++)
        {
            if (Graph[v][i] != 0)
            {
                int adj = i;

                if (Dis[v] + Graph[v][adj] < Dis[adj])
                {
                    Dis[adj] = Dis[v] + Graph[v][adj];
                    parent[adj] = v;
                }
            }
        }
    }
    // print Distance And Shortest way path.
    cout << "\nDijkstra Algorethem for find shortest path with *only positive cost is : \n"
         << endl;

    for (int v = 1; v <= V; v++)
    {
        cout << "The Shortest Distance up to " << v << " through path " << parent[v] << " is " << Dis[v] << endl;
    }
}
int main()
{
    /* Dijkstra Algorethem for find shortest path with only positive cost:
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