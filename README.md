# Randomized Algorithms Implementations

This repository contains implementations of a few randomized algorithms in C++.

## Algorithms

### Permutation Generation

The `perm.cpp` file contains three different functions for generating permutations of numbers:

*   `perm_nlogn`: Generates a random permutation of numbers from 1 to `n` with a time complexity of O(n log n).
*   `perm_n`: Generates a random permutation of numbers from 1 to `n` with a time complexity of O(n).
*   `perm_k`: Generates a random permutation of `k` numbers from 1 to `n` with a time complexity of O(k).

#### Compilation and Execution

To compile and run the `perm.cpp` file, use the following commands:

```bash
g++ perm.cpp -o perm
./perm
```

This will compile the program and run the `main` function, which generates a permutation of 5 numbers and prints it to the console.

### Minimum Spanning Tree

The `11.6. An Exploratory Assignment on Minimum Spanning Trees/mst_kruskal.cpp` file contains an implementation of Kruskal's algorithm for finding the Minimum Spanning Tree (MST) of a graph.

The program generates random graphs and runs Kruskal's algorithm on them, writing the results to a CSV file named `result.csv`. The columns in the CSV file are: `n` (number of vertices), `total` (total weight of the MST), `max` (weight of the largest edge in the MST), and `time` (time taken to run the algorithm).

#### Compilation and Execution

To compile and run the `mst_kruskal.cpp` file, use the following commands:

```bash
g++ "11.6. An Exploratory Assignment on Minimum Spanning Trees/mst_kruskal.cpp" -o mst_kruskal
./mst_kruskal
```

This will compile the program and run the `main` function, which runs a series of tests with different numbers of vertices and writes the results to `result.csv`.
