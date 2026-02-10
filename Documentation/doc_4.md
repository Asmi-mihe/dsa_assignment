# Documentation for Program 4: Implementation of Doubly Linked List with Insert and Delete Operations
This program demonstrates insertion and deletion operations in a doubly linked list using structures named Node. Each node contains data and pointers that points to both the previous and next nodes while conveniently allowing traversal in both directions. The program inserts a new node after a given node, deletes a specified node, and prints the updated list to show the changes in the linked list structure.

## (a) Explanation of how the data structures are defined
In this program, a doubly linked list is used to store integer values, with each node containing pointers to both the previous and next nodes, allowing insertion, deletion, and traversal in both directions. 

### 1) Doubly Linked List Node Structure
```c
    struct Node 
    {
    int data;
    struct Node* prev;
    struct Node* next;
    };
```
Here, 

data= stores the integer value of the node    
prev= pointer to the previous node in the list     
next= pointer to the next node in the list      

## (b) Description of the Functions Implemented and its purpose

### 1) CreateNode(int data)
Function: 
```c
    struct Node* CreateNode(int data) 
    {
        struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
        NewNode->data = data;
        NewNode->prev = NULL;
        NewNode->next = NULL;
        return NewNode;
    }
```
Purpose:     
    Creates a new linked list node with the given data and returns its pointer.     

Working:       
    It allocates memory for a new node using 'malloc' and then initializes 'data' with the provided value and next as 'NULL'. Finally, it returns a pointer to the new node.    

### 2) InsertAfter(struct Node* GivenNode, int data)
Function: 
```c
    void InsertAfter(struct Node* GivenNode, int data) {...}
```
Purpose:     
    Inserts a new node with the given data after the specified node in the doubly linked list.     

Working:    
    1. It creates a new node using the CreateNode()     
    2. It then sets the next of the new node to the next of the given node.    
    3. It updates the prev and next pointers of the surrounding nodes to maintain list integrity    

### 3) DeleteNode(struct Node** Head, struct Node* NodeToDelete)
Function: 
```c
    void DeleteNode(struct Node** Head, struct Node* NodeToDelete) {...}
```
Purpose:     
    Deletes the specified node from the doubly linked list.   

Working:      
    1. If the next node exists, then it updates the next pointer of the previous node.     
    2. If the previous node exists, then it updates the previous pointer of the next node.      
    3. It then frees the memory located to the node.      
    4. Finally, it updates the head pointer if the deleted node is the head of the list.     

### 4) PrintList(struct Node* Head)
Function: 
```c
    void PrintList(struct Node* Head) 
    {
        struct Node* temp = Head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
```
Purpose:     
    Prints all the elements of the doubly linked list from head to tail.      

Working:      
    1. It starts from the head node while using a temporary pointer.     
    2. It traverses the list using the next pointer while printing each node's data while moving to the next node     
    3. It then stops when the pointer becomes NULL i.e. end of the list.      

## (c) Overview of the main() Function      
The main() function demonstrates the working of the doubly linked list:   
1. It initially creates three initial nodes: 11, 22, 33 using the function struct Node* Head = CreateNode().   
2. It then links them to form the initial doubly linked list and then prints the list with the function PrintList(Head).     
3. It uses the function InsertAfter(Second, 44) to insert a node with data 44 after the second node and then prints the list after insertion.        
4. It then uses the function DeleteNode(&Head, Second) to delete the second node(22).       
5. Finally, it prints the list after deletion to show the updated structure.         

## (d) Sample Output of Complete Run        
```c
Initial List: 
Doubly Linked List: 11 22 33 
After Insertion: 
Inserting node with data 44 after node with data 22    
11 22 44 33
After Deletion:
Deleting node with data 22
11 44 33
```
      
## (e) Conclusion
This program demonstrates the implementation of a doubly linked list using structures in C. It performs insertion after a given node and deletion of a specified node while maintaining both forward and backward links via pointers. The program also illustrates how pointers can be used to manage nodes in a linked list and shows the practical use of linked data structures for flexible data storage and manipulation.
