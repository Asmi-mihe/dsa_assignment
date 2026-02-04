# Documentation for Program 3: Reverse Traversal of a Singly Linked List Using Stack
This program is used to perform the reverse traversal of a linked list via stack. A stack is used to temporarily store the data of each node while traversing the list in forward direction. After storing all elements, the stack is then used to pop and print the values in reverse order, and finally displaying the linked list from last node to first node.

## (a) Explanation of how the data structures are defined
In this program, a linked list, singly linked list, is used to store the integer values, and a stack is used to perform the reverse traversal.

1) Linked List Node Structure
    struct Node 
    {
        int data;
        struct Node* next;
    };
Here, 
data= stores the integer value of the given node
next= pointer that points to the next node in the linked list

2) Stack for Reverse Traversal
    int stack[100]; 
    int top = -1;
Here, 
stack[]= an array thats used to store the node data temporarily
top= keep track of the top element in the stack

## (b) Description of the Function Implemented and its purpose

1) CreateNode(int data)
Function: 
    struct Node* CreateNode(int data) 
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
Purpose: 
    Creates a new linked list node with the given data and returns its pointer.
Working:
    It allocates memory for a new node using 'malloc' and then initializes 'data' with the provided value and next as 'NULL'. Finally, it returns a pointer to the new node.

2) ReverseTraversal(struct Node* head)
Function: 
    void ReverseTraversal(struct Node* head) { ....} 
Purpose: 
    Prints the element of the linked list in reverse order using a stack.
Working: 
    1. If the list is empty then it prints "List is empty".
    2. It traverses the linked list from head to the last node while pushing each node's data into the stack.
    3. It pops the elements from the stack one by one and prints them, producing them in their reverse order.

## (c) Overview of the main() Function
The main() function demonstrates the use of the ReverseTraversal() function:
1. It initially creates a linked list with nodes containing data: 8, 16, 24, 32, 40. 
2. It then calls the ReverseTraversal(head) that prints the elements the elements in the reverse order.
The operation of the main function shows a simple example of how the reverse traversal works.

## (d) Sample Output of Complete Run
1. Input:
    struct Node* head = CreateNode(8);
    head->next = CreateNode(16);
    head->next->next = CreateNode(24);
    head->next->next->next = CreateNode(32);
    head->next->next->next->next = CreateNode(40);
Output: 
    Reverse traversal of the linked list: 40 32 24 16 8 
2. Input: 
    struct Node* head = NULL;
Output: 
    List is empty.

## (e) Conclusion
This program demonstrates how a stack can be used to perform reverse traversal of a singly linked list. It prints the elements in reverse order without changing the original list. The program also handles the case of an empty list and prints the corresponding output. 