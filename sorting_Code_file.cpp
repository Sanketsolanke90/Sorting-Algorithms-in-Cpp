// ============================================================================
// Sorting Algorithms in C++
// Author: Sanket Solanke
// Description: Implementation of basic sorting algorithms in a structured way.
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
// Selection Sort
// Time Complexity: O(n^2)
// Idea: Find the minimum element in unsorted part and place it at the start.
// ============================================================================
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++) {
        int mini = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }
}

// ============================================================================
// Insertion Sort
// Time Complexity: O(n^2)
// Idea: Insert each element into its correct position in the sorted part.
// ============================================================================
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

// ============================================================================
// Bubble Sort
// Time Complexity: O(n^2)
// Idea: Repeatedly swap adjacent elements if they are in the wrong order.
// Optimized: If no swaps happen in one pass, array is already sorted.
// ============================================================================
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--) {
        bool didSwap = false;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap) break; // Optimization
    }
}

// ============================================================================
// Merge Sort
// Time Complexity: O(n log n)
// Idea: Divide the array, sort each half, then merge them.
// ============================================================================
void merge(vector<int> &arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSortHelper(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSortHelper(arr, low, mid);
    mergeSortHelper(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(vector<int> &arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

// ============================================================================
// Quick Sort
// Time Complexity: O(n log n) average, O(n^2) worst case
// Idea: Choose a pivot, partition array, then sort subarrays.
// ============================================================================
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) i++;
        while (arr[j] > pivot && j >= low + 1) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSortHelper(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSortHelper(arr, low, pIndex - 1);
        quickSortHelper(arr, pIndex + 1, high);
    }
}

void quickSort(vector<int> &arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

// ============================================================================
// Utility: Print Array
// ============================================================================
void printArray(const vector<int> &arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// ============================================================================
// Main Driver Code
// ============================================================================
int main() {
    vector<int> arr = {1, 4, 2, 4, 3, 5, 6, 4, 6};

    cout << "Original Array: ";
    printArray(arr);

    // Uncomment to test different sorting algorithms:
    // selectionSort(arr);
    // insertionSort(arr);
    // bubbleSort(arr);
    // mergeSort(arr);
    quickSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
