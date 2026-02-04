/*How can we implement the doubly linked list using structure? 
Write a method to insert(after given node) and delete the node in doubly linked list. 
Write main() to demonstrate the use of the functions.*/ 

#include <stdio.h>
#include <stdlib.h>

//Structure for the node in the doubly linked list
struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};

//Function to create a new node
struct Node* CreateNode(int data) 
{
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}

//Function to insert a node after a given node
void InsertAfter(struct Node* GivenNode, int data) 
{
    if (GivenNode == NULL) 
    {
        printf("Given Node cannot be NULL.\n");
        return;
    }
    struct Node* NewNode = CreateNode(data);

    NewNode->next = GivenNode->next;
    GivenNode->next = NewNode;
    NewNode->prev = GivenNode;

    if (NewNode->next != NULL) 
    {
        NewNode->next->prev = NewNode;
    }
}

//Function to delete a node from the doubly linked list
void DeleteNode(struct Node** Head, struct Node* NodeToDelete) 
{
    if (*Head == NULL || NodeToDelete == NULL) 
    {
        return;
    }
    // If the node to be deleted is the head node
    if (*Head == NodeToDelete) 
    {
        *Head = NodeToDelete->next;
    }
    // Change next pointer of the previous node after the deleted node
    if (NodeToDelete->next != NULL) 
    {
        NodeToDelete->next->prev = NodeToDelete->prev;
    }
    // Change prev pointer of the next node after the deleted node
    if (NodeToDelete->prev != NULL) 
    {
        NodeToDelete->prev->next = NodeToDelete->next;
    }

    free(NodeToDelete);
}

//Function to print the doubly linked list
void PrintList(struct Node* Head) 
{
    struct Node* temp = Head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main function to demonstrate the use of the functions
int main() 
{
    struct Node* Head = CreateNode(11);
    struct Node* Second = CreateNode(22);
    struct Node* Third = CreateNode(33);

    //Linking the nodes
    Head->next = Second;
    Second->prev = Head;
    Second->next = Third;
    Third->prev = Second;

    printf("Doubly Linked List: ");
    PrintList(Head);
    
    //Inserting a node after the second node
    InsertAfter(Second, 44);
    printf("Inserting node with data 44 after node with data 22\n");
    PrintList(Head);
    
    //Deleting the second node
    DeleteNode(&Head, Second);
    printf("Deleting node with data 22\n");
    PrintList(Head);

    return 0;
}