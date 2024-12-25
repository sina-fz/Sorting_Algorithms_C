// CODE: include necessary library(s)
#include <stdio.h>
#include "mySort.h"
#include <string.h>

// Utility functions
void printArray(int arr[], int n);


// Test the sorting algorithms
int main() {
    int arr[] = {64, -134, -5, 0, 25, 12, 22, 11, 90,-887};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int testArr[n];
    int testArr1[n];
    int testArr2[n];
    int testArr3[n];
    int testArr4[n];
    
    // Bubble Sort
    memcpy(testArr, arr, n * sizeof(int));
    printf("Original array: ");
    printArray(testArr, n);
    bubbleSort(testArr, n);
    printf("Bubble sorted array: ");
    printArray(testArr, n);

    printf("\n");
    
    //Insertion Sort
    memcpy(testArr1, arr, n * sizeof(int));
    printf("Original array: ");
    printArray(testArr1, n);
    insertionSort(testArr1, n);
    printf("insertion sorted array: ");
    printArray(testArr1, n);

    printf("\n");
    
    //merge sort
    memcpy(testArr2, arr, n * sizeof(int));
    printf("Original array: ");
    printArray(testArr2, n);
    mergeSort(testArr2,0,n-1);
    printf("merge sorted array: ");
    printArray(testArr2, n);

    printf("\n");

    //counting sort
    memcpy(testArr3, arr, n * sizeof(int));
    printf("Original array: ");
    printArray(testArr3, n);
    countingSort(testArr3, n);
    printf("counting sorted array: ");
    printArray(testArr3, n);

    printf("\n");

    //heap sort
    memcpy(testArr4, arr, n * sizeof(int));
    printf("Original array: ");
    printArray(testArr4, n);
    heapSort(testArr4, n);
    printf("heap sorted array: ");
    printArray(testArr4, n);

    // CODE: do the same test cases for Insertion Sort, Merge Sort, Heap Sort, Counting Sort
    // You will submit main.c, and your project will be marked based on main.c as well
    
    return 0;
}

// Helper functions
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
