/*Write a program that generates a list of N random integers in the range [1, 1000], where N
is provided by the user at run time. Then, perform the following tasks:
(a) Ask the user to choose a sorting algorithm from the following:
• Bubble Sort
• Selection Sort
• Insertion Sort
• Merge Sort
(b) Sort the randomly generated numbers using the chosen algorithm.
(c) Print the numbers before and after sorting.
(d) Display the total number of comparisons and swaps (if applicable) performed by the
chosen algorithm. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;
int swaps = 0;

// The Function to print array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
        {
            comparisons++;
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        if(min != i)
        {
            swap(&arr[i], &arr[min]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        if(j >= 0)
        {
            comparisons++;
        }
        arr[j + 1] = key;
    }
}

// Merge function for Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int i = l, j = m + 1, k;
    int temp[1000];   // Simple temporary array

    k = l;

    while(i <= m && j <= r)
    {
        comparisons++;
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while(i <= m)
    {
        temp[k++] = arr[i++];
    }

    while(j <= r)
    {
        temp[k++] = arr[j++];
    }

    for(i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// Main function

int main()
{
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));

    // Generate random numbers between 1 and 1000
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;

    printf("\nChoose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("\nOriginal Array:\n");
    printArray(arr, n);
    comparisons = 0;
    swaps = 0;

    if(choice == 1)
    {
        bubbleSort(arr, n);
    }
    else if(choice == 2)
    {
        selectionSort(arr, n);
    }
    else if(choice == 3)
    {
        insertionSort(arr, n);
    }
    else if(choice == 4)
    {
        mergeSort(arr, 0, n - 1);
    }
    else
    {
        printf("Invalid choice!");
        return 0;
    }

    printf("\nSorted Array:\n");
    printArray(arr, n);

    printf("\nTotal Comparisons: %d\n", comparisons);
    printf("Total Swaps: %d\n", swaps);

    return 0;
}