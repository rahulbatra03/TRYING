#include <stdio.h>

// Function to perform Bubble Sort and return swap count
int bubbleSort(int arr[], int n, int ascending) {
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // For ascending order
            if (ascending) {
                if (arr[j] > arr[j + 1]) {
                    // Swap the elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapCount++;
                }
            }
            // For descending order
            else {
                if (arr[j] < arr[j + 1]) {
                    // Swap the elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapCount++;
                }
            }
        }
    }
    return swapCount;
}

// Helper function to copy array contents
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int n;
    
    // Input number of elements
    scanf("%d", &n);
    
    int arr[n], tempArray[n];
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Create a copy of the array to use for descending sort
    copyArray(arr, tempArray, n);
    
    // Count swaps for ascending order
    int ascendingSwaps = bubbleSort(arr, n, 1);
    
    // Count swaps for descending order
    int descendingSwaps = bubbleSort(tempArray, n, 0);
    
    // Output the minimum of the two swap counts
    int result = ascendingSwaps < descendingSwaps ? ascendingSwaps : descendingSwaps;
    printf("%d\n", result);
    
    return 0;
}
