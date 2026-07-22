# DSA in C 🚀

My journey learning **Data Structures & Algorithms** in C — notes, worked examples, and clean implementations, organized topic by topic as I study.

## 📌 Why this repo exists

I'm using this repo to:
- Track my DSA learning progress over time
- Keep clean, commented, working C code I can revisit before interviews
- Write out notes in my own words (with worked examples) so I actually understand *why* something works, not just how to code it

---

## 📂 Structure

```
DSA-in-C/
├── README.md
├── time-complexity/
│   └── notes.md
└── searching/
    ├── notes.md
    ├── linear_search.c
    ├── binary_search.c
    ├── practice_linear_search.c
    └── practice_binary_search.c
```

---

## ✅ Progress Tracker

| # | Topic | Status | Notes |
|---|-------|--------|-------|
| 1 | Time Complexity Basics (O(1), O(n), O(n²)) | ✅ Done |[notes](notes.md)|
| 2 | Linear Search | ✅ Done | [notes](notes.md) · [code](linear_search.c)
| 3 | Binary Search | ✅ Done | [notes](notes.md) · [code](binary_search.c)
| 4 | Linear Search — Practice Problems | ✅ Done | [code](practice_linear_search.c)
| 5 | Binary Search — Practice Problems | ✅ Done | [code](practice_binary_search.c)

*(I'll keep updating this table as I move through topics.)*

---

## 📝 Practice Problems

Once the basic search was working, I added a menu-driven practice file per topic to try out common variations asked in interviews:

**`practice_linear_search.c`**
- Find the first occurrence of a key
- Find the last occurrence of a key
- Count how many times a key occurs
- Find the largest element
- Find the smallest element

**`practice_binary_search.c`**
- Standard iterative binary search
- Find the first occurrence of a key (with duplicates)
- Find the last occurrence of a key (with duplicates)
- Count occurrences of a key
- Find floor and ceil of a key

---

## 🛠 How to run the code

Each `.c` file is standalone. Compile and run with `gcc`:

```bash
gcc searching/linear_search.c -o linear_search
./linear_search

gcc searching/binary_search.c -o binary_search
./binary_search

gcc searching/practice_linear_search.c -o practice_linear_search
./practice_linear_search

gcc searching/practice_binary_search.c -o practice_binary_search
./practice_binary_search
```

---

## 🧠 Quick Reference — Complexity Cheat Sheet

| Algorithm | Best Case | Worst Case | Average Case | Space |
|---|---|---|---|---|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |

> Binary search requires the array to be **sorted**; linear search does not.

---

## 📖 About

Learning DSA one topic at a time, in C, as groundwork for stronger programming fundamentals (and eventually applying to AI/ML roles). Feedback and PRs welcome!
