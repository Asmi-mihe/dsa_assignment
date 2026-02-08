# Documentation for Program 8: Comparison of Sorting Algorithms Using Random Data
This program generates **N random integers** in the range **[1, 1000]**, where N is entered by the user at run time. The user is then asked to choose one sorting algorithm among Bubble Sort, Selection Sort, Insertion Sort, and Merge Sort.
The program sorts the numbers using the selected method, displays the array before and after sorting, and shows the total number of comparisons and swaps performed.

## (a) Explanation of how the data structures are defined
1) Array
    int arr[n];
Here,
arr[n] = A one-dimensional integer array used to store N randomly generated numbers.

2) Global Counters
    int comparisons;
    int swaps;
Here,
comparisons = Counts how many comparisons are made during sorting.
swaps = Counts how many swaps or movements are performed (if applicable).

3) Temporary Array (for Merge Sort)
    int temp[1000];
Here,
temp[] = A temporary array used during the merging process in Merge Sort.

## (b) Description of the Functions Implemented and its purpose
1) printArray(int arr[], int n)
Function:
    void printArray(int arr[], int n)
    {
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    }
Purpose:
    Displays the elements of the array.
Working:
    It traverses the array from index 0 to n-1 and prints each element and it is also used to display both the original and sorted arrays.

2) swap(int *a, int *b)
Function:
    void swap(int *a, int *b)
    {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
    }
Purpose:
    Exchanges two elements in the array.
Working:
    It stores one value in a temporary variable, assigns the second value to the first, and then assigns the temporary value to the second.
    Each time swap is called, the swap counter increases.

3) bubbleSort(int arr[], int n)
Purpose:
    Sorts the array using Bubble Sort.
Working:
    It repeatedly compares adjacent elements and swaps them if they are in the wrong order.     After each pass, the largest unsorted element moves to its correct position.
    Comparisons and swaps are counted during the process.

4) selectionSort(int arr[], int n)
Purpose:
    Sorts the array using Selection Sort.
Working:
    It selects the smallest element from the unsorted portion of the array and swaps it with the first unsorted element.
    This process continues until the entire array is sorted. Comparisons are counted in the inner loop and swaps are counted when exchange occurs.
    
5) insertionSort(int arr[], int n)
Purpose:
    Sorts the array using Insertion Sort.
Working:
    It takes one element at a time and inserts it into its correct position in the sorted part of the array. Elements are shifted to make space for insertion.  Comparisons and movements are counted.

6) mergeSort(int arr[], int l, int r)
Purpose:
    Sorts the array using Merge Sort.
Working:
    It divides the array into two halves recursively until each subarray has one element.
    Then it merges the subarrays in sorted order using the merge() function.
    Comparisons are counted during the merging process.

7) merge(int arr[], int l, int m, int r)
Purpose:
    Merges two sorted subarrays into a single sorted array.
Working:
    It compares elements from both halves and places the smaller element into a temporary array.
    After merging, the sorted elements are copied back into the original array.

## (c) Overview of the main() Function

The main() function performs the following steps:
1. At first, it asks the user to enter the number of elements (N) and then generates N random integers in the range [1, 1000].
3. It displays the original unsorted array.
4. It asks the user to choose a sorting algorithm.
5. It then calls the corresponding sorting function and displays the sorted array.
7. Finally, it prints the total number of comparisons and swaps performed.

## (d) Sample Output of Complete Run
Input:
    Enter number of elements: 5
    Choose sorting method: 1 (Bubble Sort)
Output:
    Original Array:
    523 12 876 45 300

    Sorted Array:
    12 45 300 523 876  

    Total Comparisons: 10  
    Total Swaps: 5  

## (e) Conclusion
This program demonstrates the implementation of multiple sorting algorithms and allows comparison of their performance based on the number of comparisons and swaps.
It clearly shows how different sorting techniques work on the same dataset and helps in understanding their efficiency and behavior. The program provides a practical way to analyze and compare sorting algorithms in a simple and effective manner.