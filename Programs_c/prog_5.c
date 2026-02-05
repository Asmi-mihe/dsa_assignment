/*How can we implement the undirected graph using adjacency matrix? 
Write a function that implement the BFS and DFS technique to traverse through the graph. 
Demonstrate the use of your program with example graph.*/

#include <stdio.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int stack[MAX];
int queue[MAX];
int nV;;

//Initialize the graph with given number of vertices
void initGraph(int vertices) 
{
    nV = vertices;
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }
}

void addEdge(int a, int b) 
{
    adjMatrix[a][b] = 1;
    adjMatrix[b][a] = 1; // Undirected graph
}

// Depth First Search (DFS) implementation using stack of the adjacency matrix
void DFS(int startV) 
{
   int top = -1;
    stack[++top] = startV;
    
    while(top != -1) 
    {
        int currentV = stack[top--];
        if (!visited[currentV]) 
        {
            visited[currentV] = 1;
            printf("%d ", currentV);
            for (int i = nV - 1; i >= 0; i--) 
            {
                if (adjMatrix[currentV][i] == 1 && !visited[i]) 
                {
                    stack[++top] = i;
                }
            }
        }
    }
}

// Breadth First Search (BFS) implementation using queue of the adjacency matrix
void BFS(int startV) 
{
    int front = 0, rear = 0;
    visited[startV] = 1;
    queue[rear++] = startV;

    while (front < rear) 
    {
        int currentV = queue[front++];
        printf("%d ", currentV);
        for (int i = 0; i < nV; i++) 
        {
            if (adjMatrix[currentV][i] == 1 && !visited[i]) 
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

//Main function to demonstrate the use of the graph and traversal techniques
int main() 
{
    int vertices = 7; // Example graph with 7 vertices
    initGraph(vertices);
    addEdge(0, 1); // Adding edges to the graph
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);

    // Perform DFS traversals
    printf("DFS Traversal starting from vertex 0:\n");
    DFS(0);
    printf("\n");

    // Reset visited array for BFS
    for (int i = 0; i < vertices; i++) 
    {
        visited[i] = 0;
    }
    
    // Perform BFS traversals
    printf("BFS Traversal starting from vertex 0:\n");
    BFS(0);
    printf("\n");

    return 0;
}