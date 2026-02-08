/*Given a weighted graph, implement Dijkstra’s algorithm to find the shortest path from a source node to all other nodes.*/

#include <stdio.h>
#include <limits.h>

#define V 4   // number of vertices

// Function to find vertex with minimum distance
int findMin(int dist[], int visited[])
{
    int min = INT_MAX, index = -1;

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    int visited[V];

   // Initialize distances and visited array
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;   // Source distance is 0

    // Shortest path calculation
    for(int count = 0; count < V - 1; count++)
    {
        int u = findMin(dist, visited);  // Get minimum distance vertex
        visited[u] = 1;

        // Adjacent vertices update
        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] != 0 && visited[v] == 0)
            {
                if(dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Print result
    printf("Vertex   Distance from Source\n");
    for(int i = 0; i < V; i++)
        printf("%d        %d\n", i, dist[i]);
}

int main()
{
    int graph[V][V] = 
    {
        {0, 5, 0, 10},
        {5, 0, 3, 0},
        {0, 3, 0, 1},
        {10, 0, 1, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
