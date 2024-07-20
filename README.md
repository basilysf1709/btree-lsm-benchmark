# B-Tree and LSM Tree Performance Benchmark

## Overview

This project implements and compares the performance of B-Trees and Log-Structured Merge (LSM) Trees. B-Trees are commonly used in SQL Databases. LSM Trees, on the other hand, optimize write performance for large datasets by periodically flushing data from memory to disk in the form of SSTables and they are more common in NoSQL Databases.

## Project Structure

- **BTree.h**: Header file containing the declaration of B-Tree and B-Tree Node classes.
- **BTree.tpp**: Implementation file for the B-Tree and B-Tree Node templates.
- **LSMTree.h**: Header file containing the declaration of the LSM Tree class.
- **LSMTree.cpp**: Implementation file for the LSM Tree class.
- **SSTable.h**: Header file containing the declaration of the SSTable class.
- **SSTable.cpp**: Implementation file for the SSTable class.
- **main.cpp**: Main file containing the benchmarking tests comparing the performance of B-Trees and LSM Trees.

## Prerequisites

To compile and run this project, you need:
- A C++17 compatible compiler (e.g., `g++`)
- Standard C++ library

## Compilation

To compile the project, use the following commands:

```bash
make
```

To clean the project:

```bash
make clean
```

## Running the Program

To run the compiled program, use the following command:

```bash
./benchmark_program 10000
```

## Benchmark Results

The program benchmarks the insertion and search times for both B-Trees and LSM Trees. It generates a set of random keys, inserts them into both data structures, and measures the time taken for these operations.

### Sample Output

```
B-Tree Insertion Time: <time> ms
B-Tree Search Time: <time> ms
LSM Tree Insertion Time: <time> ms
LSM Tree Search Time: <time> ms
```

## Explanation

### B-Trees

B-Trees are balanced tree data structures that maintain sorted data and allow for efficient insertion, deletion, and search operations. They are widely used in database and file systems for indexing.

### LSM Trees

LSM Trees are designed for write-heavy workloads and handle larger datasets that do not fit entirely in memory. They periodically flush data from an in-memory MemTable to disk in the form of SSTables. This approach optimizes write performance but can result in slower read times due to the need to search multiple SSTables.

## Key Differences

- **In-Memory vs. Disk I/O**: B-Trees operate primarily in memory, making both insertions and searches faster. LSM Trees rely on disk I/O for persistence, which slows down these operations.
- **Balancing and Overhead**: B-Trees maintain balance with in-memory operations, while LSM Trees require compaction and merging of SSTables on disk, adding to the operational overhead.

## Customization

- **MemTable Size**: The size of the MemTable in the LSM Tree can be adjusted to see how it impacts performance. This is controlled by the parameter in the `LSMTree` constructor.
- **Number of Keys**: The number of keys generated for the benchmark can be adjusted in the `main.cpp` file.

## Future Work

- **Compaction and Merging**: Implement compaction and merging for the LSM Tree to optimize read performance.
- **Enhanced I/O Optimization**: Explore buffered and asynchronous I/O operations to improve LSM Tree performance.
