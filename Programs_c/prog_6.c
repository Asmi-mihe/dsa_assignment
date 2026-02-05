//Write a program to build the min and max heap, if the given array has unsorted data.//

#include <stdio.h>

//Function that swaps two integers
void swap(int *x, int *y) 
{
    int temp= *x;
    *x= *y;
    *y= temp;
}

// function that maintains the minimum-heap property
void MinHeap(int arr[], int n, int i) 
{
    int smallest= i; 
    int left= 2 * i + 1; 
    int right= 2 * i + 2; 

    if (left < n && arr[left] < arr[smallest])
    {
        smallest= left;
    }

    if (right < n && arr[right] < arr[smallest])
    {
        smallest= right;
    }

    if (smallest != i) 
    {
        swap(&arr[i], &arr[smallest]);
        MinHeap(arr, n, smallest);
    }
}

// Function that maintains the maximum-heap property
void MaxHeap(int arr[], int n, int i) 
{
    int largest= i; 
    int left= 2 * i + 1; 
    int right= 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
    {
        largest= left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest= right;
    }
   
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        MaxHeap(arr, n, largest);
    }
}

// Function to build a mininum heap from the given array
void buildMinHeap(int arr[], int n) 
{
    for (int i= n/2 - 1; i >= 0; i--)
    {
        MinHeap(arr, n, i);
    }
}

// Function to build a maximum heap from the given array
void buildMaxHeap(int arr[], int n) 
{
    for (int i= n/2 - 1; i >= 0; i--)
    {
        MaxHeap(arr, n, i);
    }
}

// Function to display the array
void display(int arr[], int n) 
{
    for (int i= 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the above functions
int main() 
{
    int arr1[]= {45, 12, 89, 33, 7, 56, 23};
    int arr2[]= {45, 12, 89, 33, 7, 56, 23};
    int n= 7;

    printf("Original array:\n");
    display(arr1, n); 
    
    buildMinHeap(arr1, n);
    printf("Min Heap:\n");
    display(arr1, n);  

    buildMaxHeap(arr2, n);
    printf("Max Heap:\n");
    display(arr2, n);

    return 0;
}