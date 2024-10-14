#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot element at the correct position
int partition(int array[], int low, int high) {
    int pivot = array[high]; // Choose the rightmost element as the pivot
    int i = (low - 1); // Pointer for the greater element

    // Traverse each element and compare with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    // Place the pivot element at the right position
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high); // Get the pivot element
        quickSort(array, low, pi - 1); // Sort elements before the pivot
        quickSort(array, pi + 1, high); // Sort elements after the pivot
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    
    int array[n];
    printf("Enter the Elements:");
    int size = sizeof(array) / sizeof(array[0]);
    for (int i=0; i<n; i++){
    scanf("%d", &array[i]);
    }
    
    
    quickSort(array, 0, size - 1);
    
    printf("Sorted array: \n");
    printArray(array, size);
    
    return 0;
}