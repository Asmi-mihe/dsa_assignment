# Documentation for Program 7: Implementation of Dijkstra’s Algorithm
This program implements Dijkstra’s Algorithm to find the shortest path from a given source vertex to all other vertices in a weighted graph.
The graph is represented using an adjacency matrix. The algorithm follows a greedy approach by repeatedly selecting the vertex with the minimum tentative distance and updating its adjacent vertices.

## (a) Explanation of how the data structures are defined
1) Adjacency Matrix
    int graph[V][V];
Here,
graph[V][V] = A two-dimensional integer array used to represent the weighted graph.

2) Distance Array
    int dist[V];
Here,
dist[V] = An integer array used to store the shortest distance from the source vertex to every other vertex.

3) Visited Array
    int visited[V];
Here,
visited[V] = An integer array used to keep track of vertices that have already been processed.

4) Constant Definition
    #define V 4
Here,
V = Represents the total number of vertices in the graph.

## (b) Description of the Functions Implemented and its purpose
1) findMin(int dist[], int visited[])
Function:
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
Purpose:
    Finds the vertex with the minimum distance value among the unvisited vertices.
Working:
    1. It iterates through all vertices and checks:
    >> If the vertex is not visited.
    >> If its distance is smaller than the current minimum.
    2. It returns the index of the vertex having the smallest distance.

2) dijkstra(int graph[V][V], int source)
Function:
    void dijkstra(int graph[V][V], int source){...}
Purpose:
    Implements Dijkstra’s Algorithm to compute the shortest path from the source vertex to all other vertices.
Working:
    1. It initializes all distances to infinity (INT_MAX) and marks all vertices as unvisited.
    2. It sets the distance of the source vertex to 0.
    3. It repeats the following steps (V-1 times):
    >>Selects the unvisited vertex with the smallest distance using findMin().
    >>Marks that vertex as visited.
    >>Updates the distance of all its adjacent unvisited vertices if a shorter path is found.
    4. Finally, it prints the shortest distance from the source to each vertex.

## (c) Overview of the main() Function
The main() function demonstrates the program in the following way:
1. Initially, it defines a weighted graph using an adjacency matrix.
2. And then it calls the dijkstra() function with vertex 0 as the source.
3. The algorithm calculates the shortest path from the source to all other vertices.
4. The final shortest distances are displayed in tabular form.

## (d) Sample Output of Complete Run
Input:
    int graph[V][V] = 
    {
        {0, 5, 0, 10},
        {5, 0, 3, 0},
        {0, 3, 0, 1},
        {10, 0, 1, 0}
    };
    Source = 0
Output:
Vertex   Distance from Source
0        0
1        5
2        8
3        9

## (e) Conclusion
The program successfully implements Dijkstra’s Algorithm using an adjacency matrix representation of a weighted graph. It demonstrates how shortest paths can be calculated efficiently using a greedy approach.