/*
    Practice Problems - Linear Search
    ----------------------------------
    A collection of small problems built on top of the basic
    linear search idea, to practice variations of the same concept.

    Problems covered:
    1. Find the FIRST occurrence of a key
    2. Find the LAST occurrence of a key
    3. Count how many times a key occurs
    4. Find the largest element using linear search logic
    5. Find the smallest element using linear search logic

    Menu-driven so all problems can be tried from one program.
*/

#include <stdio.h>

int find_first(int a[], int n, int key);
int find_last(int a[], int n, int key);
int count_occurrences(int a[], int n, int key);
int find_largest(int a[], int n);
int find_smallest(int a[], int n);

int main()
{
    int a[30], n, i, key, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nElements: ");
    for(i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");

    do {
        printf("\n--- Linear Search Practice Menu ---\n");
        printf("1. Find first occurrence of a key\n");
        printf("2. Find last occurrence of a key\n");
        printf("3. Count occurrences of a key\n");
        printf("4. Find largest element\n");
        printf("5. Find smallest element\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter key to search: ");
                scanf("%d", &key);
                i = find_first(a, n, key);
                if(i == -1)
                    printf("Element is NOT FOUND\n");
                else
                    printf("First occurrence at location = %d\n", i);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                i = find_last(a, n, key);
                if(i == -1)
                    printf("Element is NOT FOUND\n");
                else
                    printf("Last occurrence at location = %d\n", i);
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                printf("Key occurs %d time(s)\n", count_occurrences(a, n, key));
                break;

            case 4:
                printf("Largest element = %d\n", find_largest(a, n));
                break;

            case 5:
                printf("Smallest element = %d\n", find_smallest(a, n));
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

// Problem 1: Return the position (1-indexed) of the first match, else -1
int find_first(int a[], int n, int key)
{
    int i;
    for(i = 0; i < n; i++) {
        if(a[i] == key)
            return (i + 1);
    }
    return (-1);
}

// Problem 2: Return the position (1-indexed) of the last match, else -1
int find_last(int a[], int n, int key)
{
    int i, last = -1;
    for(i = 0; i < n; i++) {
        if(a[i] == key)
            last = i + 1;
    }
    return last;
}

// Problem 3: Count total occurrences of key
int count_occurrences(int a[], int n, int key)
{
    int i, count = 0;
    for(i = 0; i < n; i++) {
        if(a[i] == key)
            count++;
    }
    return count;
}

// Problem 4: Find largest element by scanning linearly
int find_largest(int a[], int n)
{
    int i, max = a[0];
    for(i = 1; i < n; i++) {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

// Problem 5: Find smallest element by scanning linearly
int find_smallest(int a[], int n)
{
    int i, min = a[0];
    for(i = 1; i < n; i++) {
        if(a[i] < min)
            min = a[i];
    }
    return min;
}
