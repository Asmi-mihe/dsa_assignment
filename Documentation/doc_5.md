# Documentation for Program 5: Implementation of Undirected Graph using Adjacency Matrix with DFS and BFS Traversal
This program implements an undirected graph using an adjacency matrix representation. It provides two traversal techniques: Depth First Search (DFS) and Breadth First Search (BFS) where DFS is implemented using stack, while BFS is implemented using a queue. The program demonstrates both traversal methods using a sample graph of 7 vertices.

## (a) Explanation of how the data structures are defined
In this program an adjacency matrix of an undirected graph is traversed using two traversal techniques: Depth First Search(DFS) and Breadth First Search(BFS).

1) Adjacency Matrix
    int adjMatrix[MAX][MAX];
Here, 
adjMatrix[MAX][MAX]= A two-dimensional array that is used to represent the graph

2) Visited Array 
    int visited[MAX];
Here, 
visited[MAX]= An integer array that is used to keep the track of visited vertices during the traversal which prevents revisiting the same vertex twice.

3) Stack(for DFS)
    int stack[MAX];
Here, 
stack[MAX]= An integer array that is used to perform the DFS where the vertices are pushed on to the stack and popped during the traversal.

4) Queue(for BFS)
    int queue[MAX];
Here, 
queue[MAX]= An integer array that is used inside the BFS.

## (b) Description of the Functions Implemented and its purpose
1) initGraph(int vertices)
Function: 
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
Purpose: 
    Initilizes the graph
Working: 
    It initializes the graph by setting the number of vertices then filling the adjacency matrix with 0 i.e. no edges and finally resetting the visited array to 0.

2) addEdge(int a, int b)
Function: 
    void addEdge(int a, int b) 
    {
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1; 
    }
Purpose: 
    Adds as edge between two vertices.
Working:
    It adds an edge between two vertices and since the graph is undirected, both directions are updated in the adjacency matrix.

3) DFS(int startV) 
Function: 
    void DFS(int startV) {...}
Purpose: 
    Performs Depth First Search(DFS) using a stack
Working: 
    1. First, it pushes the starting vertex onto the stack.
    2. It then pops a vertex from the stack.
    3. If it is not visited, then marks it visited and then prints it.
    4. It then pushes all adjacent unvisited vertices onto the stack.
    5. Finally, it continues until the stack becomes empty.

4) BFS(int startV)
Function: 
    void BFS(int startV) {...}
Purpose: 
    Performs Breadth First Search(BFS) using a queue
Working: 
    1. First, it marks the starting vertex as visited then enqueues it.
    2. It dequeues one vertex at time, visits it and enqueues all adjacent unvisited vertices.
    3. It continues the above action until the queue becomes empty. 

## (c) Overview of the main() Function
The main() function demonstrates the program in the following way:
1. First, it initializes the graph using the function initGraph(vertices) where the vertices=7.
2. It then adds edges to create a sample graph using function addEdge(). For example it uses function, addEdge(0, 1) and addEdge(0, 2) that connects 0 with 1 and 2.
3. It calls DFS(0) to do the depth first search starting from vertex 0 then resets the visited array.
4. Then again it calls BFS(0) to do the breadth first search starting from vertex 0.
5. Finally, it prints both the traversal results.

## (d) Sample Output of Complete Run
Input: 
int vertices = 7;
    initGraph(vertices);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);
Output: 
    DFS Traversal starting from vertex 0:
    0 1 3 4 2 5 6 
    BFS Traversal starting from vertex 0:
    0 1 2 3 4 5 6

## (e) Conclusion
This program successfully demonstrates how an undirected graph can be implemented using an adjacency matrix. It performs DFS using a stack and BFS using a queue. The program shows a clear difference between the DFS and BFS which in turns helps for a better understanding of graph traversal techniques.