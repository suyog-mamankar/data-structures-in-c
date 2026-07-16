/*
 * Binary Search in C
 * ---------------------------------------
 * Finds a target in a SORTED array by repeatedly halving the search range.
 *
 * Time Complexity:
 *   Best case    -> O(1)        (target at the first computed mid)
 *   Worst case   -> O(log n)    (target at an extreme, or absent)
 *   Average case -> O(log n)
 * Space Complexity: O(1)
 *
 * NOTE: Array MUST be sorted before calling this function.
 */

#include <stdio.h>

int binarySearch(int a[], int n, int data) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {  // must be <=, not <, to check the final single element
        int mid = (low + high) / 2;

        if (data == a[mid]) {
            return mid;              // found
        } else if (data < a[mid]) {
            high = mid - 1;          // search left half
        } else {
            low = mid + 1;           // search right half
        }
    }

    return -1;  // low > high means the target isn't present
}

int main() {
    int a[] = {5, 7, 19, 25, 32, 47, 52};
    int n = sizeof(a) / sizeof(a[0]);

    int targets[] = {19, 5, 52, 20};
    int numTargets = sizeof(targets) / sizeof(targets[0]);

    for (int t = 0; t < numTargets; t++) {
        int data = targets[t];
        int result = binarySearch(a, n, data);

        if (result != -1) {
            printf("Element %d found at index %d\n", data, result);
        } else {
            printf("Element %d not found\n", data);
        }
    }

    return 0;
}
