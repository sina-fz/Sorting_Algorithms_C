// CODE: include necessary library(s)
// you have to write all the functions and algorithms from scratch,
// You will submit this file, mySort.c holds the actual implementation of sorting functions
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int *arr, int n, int i) {
    int max_root = i;
    int left_ch = 2 * i + 1;  // Index of the left child
    int right_ch = 2 * i + 2; // Index of the right child

    // Checking if left child exists and is greater than root
    if (left_ch < n && arr[left_ch] > arr[max_root]) {
        max_root = left_ch;
    }

    // Check if right child exists and is greater than the current largest
    if (right_ch < n && arr[right_ch] > arr[max_root]) {
        max_root = right_ch;
    }

    // If largest is not root, swap and continue heapifying
    if (max_root != i) {
        swap(&arr[i], &arr[max_root]);
        heapify(arr, n, max_root); // Corrected recursive call
    }
}
void merge(int *arr, int l, int middle, int r) {
    int leftSize = middle - l + 1;
    int rightSize = r - middle;

    // Allocate memory for temporary sub-arrays
    int *arr1 = (int *)malloc(leftSize * sizeof(int));
    int *arr2 = (int *)malloc(rightSize * sizeof(int));

    // Check for successful memory allocation
    if (arr1 == NULL || arr2 == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Copy data to temporary sub-arrays
    for (int i = 0; i < leftSize; i++) {
        arr1[i] = arr[l + i];
    }
    for (int j = 0; j < rightSize; j++) {
        arr2[j] = arr[middle + 1 + j];
    }

    // Merge the sub-arrays back into the original array
    int i = 0, j = 0, k = l;
    while (i < leftSize && j < rightSize) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of arr1
    while (i < leftSize) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy any remaining elements of arr2
    while (j < rightSize) {
        arr[k] = arr2[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    free(arr1);
    free(arr2);
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
// insertion sort
// in this sorting algorithm we try to make one side of the array sorted and for eaach element try to insert it in the right place

void insertionSort(int* arr, int n){
    for (int i = 1; i<n; i++){
        int j = i-1;
        //temporarly storring each element
        int goal = *(arr+i);
        //checking if the element is bigger that the one behind it and if it is not shift the previous element one to the right 
        while(j>=0 && arr[j] > goal){
             arr[j+1] = arr[j];
            j--;
        }
        //inserting the element in its proper place
        arr[j+1] = goal;
    }
}
//merge sort
// it uses the divide and conquer
void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int middle = l + (r - l) / 2;

        // Recursively sort both halves
        mergeSort(arr, l, middle);
        mergeSort(arr, middle + 1, r);

        // Merge the sorted halves
        merge(arr, l, middle, r);
    }
}

//counting sort
void countingSort(int *arr, int n) {
    // Step 1: Find the minimum and maximum values in the array
    int min = arr[0]; 
    int max = arr[0];

    // Iterate through the array to find the actual min and max
    for (int i = 1; i < n; i++) {  // Start from index 1
        if (arr[i] < min) {
            min = arr[i]; 
        }
        if (arr[i] > max) {
            max = arr[i]; 
        }
    }

    // Step 2: Create and initialize the count array
    int arrSize = max - min + 1;
    int *count_arr = (int *) calloc(arrSize, sizeof(int)); 

    // Check if memory allocation was successful
    if (count_arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    // Step 3: Populate the count array
    for (int i = 0; i < n; i++) {
        int pos = arr[i] - min; // Calculate the position in count_arr
        count_arr[pos]++; // Increment the count for that position
    }

    // Step 4: Rebuild the sorted output array in the original input array
    int k = 0; 
    for (int i = 0; i < arrSize; i++) {
        while (count_arr[i] > 0) {  // Use > 0 instead of != 0
            arr[k] = min + i; // Place the actual value back into arr
            count_arr[i]--; // Decrement the count for that value
            k++; 
        }
    }

    // Free the allocated memory for count_arr
    free(count_arr);
}

// Heap sort function
void heapSort(int *arr, int n) {
    // Build heap (rearrange array)
    int non_leaf = n / 2 - 1; // Index of the last non-leaf node
    for (int i = non_leaf; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// CODE: implement the algorithms for Insertion Sort, Merge Sort, Heap Sort, Counting Sort