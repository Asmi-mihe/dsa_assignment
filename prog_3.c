//Write and implement the reverse traversal algorithm in the the linked list. Write main() to demonstrate the use of the function.
#include <stdio.h>
#include <stdlib.h>

// It defines the structure of a node
struct Node 
{
    int data;
    struct Node* next;
};

// Function thats creates a new node
struct Node* CreateNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to perform reverse traversal using a stack
void ReverseTraversal(struct Node* head) {
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    // Stack defined that holds the node data
    int stack[100]; 
    int top = -1;

    struct Node* temp = head;

    // Push all node data onto the stack
    while (temp != NULL) {
        stack[++top] = temp->data;
        temp = temp->next;
    }

    // Pop and print nodes from the stack
    printf("Reverse traversal of the linked list: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

//Main function
int main() {
    // Create the nodes with sample data
    struct Node* head = CreateNode(8);
    head->next = CreateNode(16);
    head->next->next = CreateNode(24);
    head->next->next->next = CreateNode(32);
    head->next->next->next->next = CreateNode(40);

    // Creates a node with NULL data to demonstrate empty list case
    /*  struct Node* head = NULL*/
    
    ReverseTraversal(head); // Calls the reverse traversal function

    return 0;
}

