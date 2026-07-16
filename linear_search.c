/*
 * Linear Search in C
 * ---------------------------------------
 * Scans an array sequentially from index 0 until it finds the target
 * or reaches the end of the array.
 *
 * Time Complexity:
 *   Best case    -> O(1)   (target at index 0)
 *   Worst case   -> O(n)   (target at last index, or not present)
 *   Average case -> O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int linearSearch(int a[], int n, int data) {
    int found = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == data) {
            found = 1;
            index = i;
            break;  // stop as soon as we find a match — avoids redundant checks
        }
    }

    if (found == 0) {
        return -1;  // sentinel value for "not found"
    }
    return index;
}

int main() {
    int a[] = {15, 5, 20, 35, 2, 42, 67, 17};
    int n = sizeof(a) / sizeof(a[0]);

    int targets[] = {42, 41, 15, 17};
    int numTargets = sizeof(targets) / sizeof(targets[0]);

    for (int t = 0; t < numTargets; t++) {
        int data = targets[t];
        int result = linearSearch(a, n, data);

        if (result != -1) {
            printf("Element %d found at index %d\n", data, result);
        } else {
            printf("Element %d not found\n", data);
        }
    }

    return 0;
}
