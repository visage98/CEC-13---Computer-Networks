#include <stdio.h>
#include <limits.h>
#include<iostream>
using namespace std;

//0 0 0 2 0 0 2 4 0 2 0 1 2 4 1 0
int minDistance(int dist[], bool sptSet[],int V)
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

// A utility function to print the constructed distance
// array
int printSolution(int dist[], int n, int parent[],int sr,int des)
{
    int src = sr;
    printf("Vertex\t  Distance\tPath");

        printf("\n%d -> %d \t\t %d\t\t%d ", src, des, dist[des], src);
        printPath(parent, des);

}

// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[100][100], int src,int des, int V)
{
    int dist[V];
    bool sptSet[V];


    int parent[V];


    for (int i = 0; i < V; i++)
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }


    dist[src] = 0;


    for (int count = 0; count < V-1; count++)
    {

        int u = minDistance(dist, sptSet,V);

        sptSet[u] = true;


        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }


    printSolution(dist, V, parent,src,des);
}


int main()
{
    int V;
    cout<<"DIJKSTRA'S ALGO FOR ROUTING:-"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Enter number of vertices in the graph :"<<endl;
    cin>> V;
    cout<<"Enter graph"<<endl;
    int graph[100][100];
    for(int i=0;i<V;++i)
    {
        for(int j=0;j<V;++j)
        {
            cin>>graph[i][j];
        }
    }


    cout<<"Enter source vertex: ";
    int src;
    cin>>src;
    cout<<"Enter destination: ";
    int dest;
    cin>>dest;

    dijkstra(graph,src,dest, V);

    return 0;
}
/*
0 1 0 0 0
1 0 4 5 0
0 4 0 0 1
0 5 0 0 2
0 0 1 2 0
*/
