/*
    Practice Problems - Binary Search
    -----------------------------------
    A collection of small problems built on top of the basic
    binary search idea, to practice variations of the same concept.
    The array is sorted first, since binary search requires it.

    Problems covered:
    1. Standard binary search (iterative)
    2. Find FIRST occurrence of a key in a sorted array (with duplicates)
    3. Find LAST occurrence of a key in a sorted array (with duplicates)
    4. Count occurrences of a key using binary search
    5. Find floor (largest element <= key) and ceil (smallest element >= key)

    Menu-driven so all problems can be tried from one program.
*/

#include <stdio.h>

void bubble_sort(int a[], int n);
int binary_search_iterative(int a[], int n, int key);
int find_first_occurrence(int a[], int n, int key);
int find_last_occurrence(int a[], int n, int key);
int count_occurrences(int a[], int n, int key);
void find_floor_ceil(int a[], int n, int key, int *floor_val, int *ceil_val);

int main()
{
    int a[30], n, i, key, choice;
    int floor_val, ceil_val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Binary search needs a sorted array
    bubble_sort(a, n);

    printf("\nSorted elements: ");
    for(i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");

    do {
        printf("\n--- Binary Search Practice Menu ---\n");
        printf("1. Standard binary search\n");
        printf("2. Find first occurrence of a key\n");
        printf("3. Find last occurrence of a key\n");
        printf("4. Count occurrences of a key\n");
        printf("5. Find floor and ceil of a key\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter key to search: ");
                scanf("%d", &key);
                i = binary_search_iterative(a, n, key);
                if(i == -1)
                    printf("Element is NOT FOUND\n");
                else
                    printf("Element is FOUND at location = %d\n", i);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                i = find_first_occurrence(a, n, key);
                if(i == -1)
                    printf("Element is NOT FOUND\n");
                else
                    printf("First occurrence at location = %d\n", i);
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                i = find_last_occurrence(a, n, key);
                if(i == -1)
                    printf("Element is NOT FOUND\n");
                else
                    printf("Last occurrence at location = %d\n", i);
                break;

            case 4:
                printf("Enter key to search: ");
                scanf("%d", &key);
                printf("Key occurs %d time(s)\n", count_occurrences(a, n, key));
                break;

            case 5:
                printf("Enter key: ");
                scanf("%d", &key);
                find_floor_ceil(a, n, key, &floor_val, &ceil_val);
                printf("Floor (largest <= key) = ");
                if(floor_val == -1) printf("Not found\n"); else printf("%d\n", floor_val);
                printf("Ceil  (smallest >= key) = ");
                if(ceil_val == -1) printf("Not found\n"); else printf("%d\n", ceil_val);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }

    } while(choice != 0);

    return 0;
}

void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++) {
        for(j = 0; j < n - i; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Problem 1: Standard iterative binary search, returns 1-indexed position
int binary_search_iterative(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == key)
            return (mid + 1);
        else if(key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Problem 2: Find the first occurrence when duplicates exist
int find_first_occurrence(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid, result = -1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == key) {
            result = mid + 1;   // record match, keep searching left
            high = mid - 1;
        }
        else if(key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

// Problem 3: Find the last occurrence when duplicates exist
int find_last_occurrence(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid, result = -1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == key) {
            result = mid + 1;   // record match, keep searching right
            low = mid + 1;
        }
        else if(key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

// Problem 4: Count occurrences = (last - first + 1), using first/last helpers
int count_occurrences(int a[], int n, int key)
{
    int first = find_first_occurrence(a, n, key);
    int last = find_last_occurrence(a, n, key);
    if(first == -1)
        return 0;
    return (last - first + 1);
}

// Problem 5: Floor = largest element <= key, Ceil = smallest element >= key
void find_floor_ceil(int a[], int n, int key, int *floor_val, int *ceil_val)
{
    int low = 0, high = n - 1, mid;
    *floor_val = -1;
    *ceil_val = -1;

    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == key) {
            *floor_val = a[mid];
            *ceil_val = a[mid];
            return;
        }
        else if(a[mid] < key) {
            *floor_val = a[mid];   // candidate floor
            low = mid + 1;
        }
        else {
            *ceil_val = a[mid];    // candidate ceil
            high = mid - 1;
        }
    }
}
