# Time Complexity — Notes

## Core Assumption

Every basic instruction (declaration, assignment, comparison, print, etc.) is assumed to take **1 unit of time**. A single-step operation or constant-time block is represented as **O(1)**.

---

## Example 1 — Constant Time: O(1)

A plain sequence of operations with no loops.

```c
main() {
    int a, b, sum;                              // 1 unit
    printf("Enter 2 variables");                // 1 unit
    scanf("%d %d", &a, &b);                      // 1 unit
    sum = a + b;                                 // 1 unit
    printf("Sum : %d", sum);                     // 1 unit
    return 0;                                    // 1 unit
}
```

- **Total time:** 1+1+1+1+1+1 = 6 units
- **Complexity:** O(1) — constant, doesn't depend on any input size `n`.

---

## Example 2 — Conditional Statements: O(1)

For `if-else` blocks, we analyze the **worst-case path** (the longer branch).

```c
main() {
    int a, b, c;                                 // 1 unit
    printf("Enter a and b");                     // 1 unit
    scanf("%d %d", &a, &b);                       // 1 unit

    if (a > b) {                                  // 1 unit
        printf("a is g");                         // 1 unit
    } else {
        printf("b is g");                         // 1 unit
    }
    return 0;                                     // 1 unit
}
```

- Even with branching, only **one** branch ever executes — the total step count stays constant.
- **Complexity:** O(1)

---

## Example 3 — Linear Time (Single Loop): O(n)

When a loop runs `n` times, everything inside it scales linearly with `n`.

```c
main() {
    int n, i;
    printf("Enter value of n: ");                 // 1 unit
    scanf("%d", &n);                               // 1 unit

    for (i = 0; i < n; i++) {                      // (n + 1) units — condition checked n times + 1 final failing check
        printf("---");                             // n units
        printf("---");                             // n units
    }
    return 0;                                      // 1 unit
}
```

- **Total time equation:** `1 + 1 + (n + 1) + n + n + 1`
- **Simplified:** `3n + 4`
- **Dropping constants/coefficients** (standard Big-O rule): the dominant term is `n`.
- **Complexity:** O(n)

---

## Example 4 — Quadratic Time (Nested Loops): O(n²)

A loop inside another loop means the inner block runs `n × n` times.

```c
main() {
    int n, i, j;
    printf("n");                                   // 1 unit
    scanf("%d", &n);                                // 1 unit

    for (i = 0; i < n; i++) {                       // outer loop: runs n times
        printf("---");                              // runs n times

        for (j = 0; j < n; j++) {                   // inner loop: runs n times FOR EACH outer iteration
            printf("---");                          // runs n * n times total
        }
    }
    return 0;
}
```

- The inner block executes `n × n = n²` times overall.
- **Complexity:** O(n²)

---

## 🔑 Takeaways

| Pattern | Complexity |
|---|---|
| Fixed number of steps, no loops | O(1) |
| `if-else` (no loop) — worst case still constant | O(1) |
| Single loop running `n` times | O(n) |
| Loop inside a loop, both running `n` times | O(n²) |

**Rule of thumb:** count how many times the innermost line of code can possibly execute as a function of `n`, then drop constants and lower-order terms — what's left is the Big-O complexity.
