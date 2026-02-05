# Documentation for Program 5: Building Min and Max Heaps from an Unsorted Array
This program takes an unsorted array of integers and builds both a Min Heap and a Max Heap. Min Heap is a heap structure where each parent node is smaller than its children and max heap is a heap structure where each parent node is larger than its children.
This program demonstrates how to maintain heap properties using MinHeap and MaxHeap functions and builds the heaps from a sample array.

## (a) Explanation of how the data structures are defined
1) Array
    int arr[];
Here,
arr[]=A one-dimensional integer array that is used to store the elements of the heap
The array represents the heap in level-order form. The parent and child relationships are calculated using index positions:
Left child = 2*i + 1
Right child = 2*i + 2
Parent = (i - 1) / 2

The same array structure is used to build both the Min Heap and Max Heap.

2) Variables for Heap structure
    int smallest, largest;
    int left, right;
Here, 
smallest= Stores the index of the smallest element(used in Min Heap)
largest= Stores the index of the largest element(used in Max Heap)
left and right=Stores the indices of the left and right child nodes of the given parent node

3) Recursion(Heapify Process)
    MinHeap()
    MaxHeap()
Here, 
MinHeap() and MaxHeap()= Function that uses recursion to maintain the heap property

4) Swap Function
    void swap(int *x, int *y);
Here, 
swap()= Function used to exchange two elements in the array whenever the head property is violated.

## (b) Description of the Functions Implemented and its purpose
1) swap(int *a, int *b)
Function: 
    void swap(int *x, int *y) 
    {
        int temp= *x;
        *x= *y;
        *y= temp;
    }
Purpose: 
    Swaps two integers in memory
Working: 
    It stores the value of the first variable in a temporary variable, assigns the second variable's value to the first and then assigns the temporary value to the second variable.
    This function is used when the heap property is violated.

2) minHeapify(int arr[], int n, int i)
Function: 
    void MinHeap(int arr[], int n, int i) {...}
Purpose:
    Maintains the min-heap property for a subtree rooted at index i
Working: 
    It first assumes the current index i as the smallest and calculates the left and right child indices and then compares the parent with its children.
    >> If the child is smaller than the parent, it updates the smallest index
    >> If the smallest is not the parent, it swaps them and recursively calls itself for the affected subtree.

3) MaxHeap(int arr[], int n, int i)
Function: 
    void MaxHeap(int arr[], int n, int i) {...}
Purpose: 
    Maintains the maximum-heap property for a subtree
Working: 
    It first assumes the current index i as the largest and calculates the left and right child indices and then compares the parent with its children.
    >> If the child is larger than the parent, it updates the largest index
    >> If the largest is not the parent, it swaps them and recursively calls itself for the affected subtree.

4) buildMinHeap(int arr[], int n)
Function:
    void buildMinHeap(int arr[], int n) {...}
Purpose:
    Builds a complete Min Heap from the given unsorted array.
Working:
    It starts from the last non-leaf node (n/2 - 1) and calls MinHeap() for each node moving upwards to the root. This ensures the entire array satisfies the min-heap property.

5) buildMaxHeap(int arr[], int n)
Function:
    void buildMaxHeap(int arr[], int n) {...}
Purpose:
    Builds a complete Max Heap from the given unsorted array.
Working:
    It starts from the last non-leaf node (n/2 - 1) and calls MaxHeap() for each node moving upwards to the root. This ensures the entire array satisfies the max-heap property.

6) display(int arr[], int n)
Function:
    void display(int arr[], int n) {...}
Purpose:
    Displays the elements of the array.
Working:
    It traverses the array from index 0 to n-1 and prints each element.
    It is used to show the original array, Min Heap, and Max Heap.

## (c) Overview of the main() Function
The main() function demonstrates the program in the following way:
1. First, the program starts with an unsorted array of integers.
2. It builds a Min Heap by calling buildMinHeap(), which rearranges the elements so that every parent node is smaller thean its children.
3. It then builds a Max Heap by calling buildMaxHeap(), which rearranges the elements so that every parent node is larger than its children.
4. Finally, it displays the original array, the Min Heap, and the Max Heap.

## (d) Sample Output of Complete Run
Input: 
    int arr1[]= {45, 12, 89, 33, 7, 56, 23};
    int arr2[]= {45, 12, 89, 33, 7, 56, 23};
    int n= 7;
Output: 
    Original array:
    45 12 89 33 7 56 23 
    Min Heap:
    7 12 23 33 45 56 89
    Max Heap:
    89 33 56 12 7 45 23

## (e) Conclusion
The program demonstrates the implementation of both Min Heap and Max Heap using an array representation. It shows how heap structures can be built by rearranging elements according to heap properties. The Min Heap has ensured that the smallest element is placed at the root, while the Max Heap has ensured that the largest element is placed at the root.
The program clearly demonstrates the concept and working of heap data structures in a simple and effective manner.