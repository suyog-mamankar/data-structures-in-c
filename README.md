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
    └── binary_search.c
```

---

## ✅ Progress Tracker

| # | Topic | Status | Notes |
|---|-------|--------|-------|
| 1 | Time Complexity Basics (O(1), O(n), O(n²)) | ✅ Done | [notes](./time-complexity/notes.md) |
| 2 | Linear Search | ✅ Done | [notes](./searching/notes.md) · [code](./searching/linear_search.c) |
| 3 | Binary Search | ✅ Done | [notes](./searching/notes.md) · [code](./searching/binary_search.c) |
| 4 | Bubble / Selection / Insertion Sort | ⬜ Upcoming | — |
| 5 | Recursion Basics | ⬜ Upcoming | — |
| 6 | Arrays (2D, Prefix Sums) | ⬜ Upcoming | — |
| 7 | Linked Lists | ⬜ Upcoming | — |

*(I'll keep updating this table as I move through topics.)*

---

## 🛠 How to run the code

Each `.c` file is standalone. Compile and run with `gcc`:

```bash
gcc searching/linear_search.c -o linear_search
./linear_search

gcc searching/binary_search.c -o binary_search
./binary_search
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
