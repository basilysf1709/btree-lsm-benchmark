#include "BTree.h"
#include "LSMTree.h"
#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono;

// Function to generate random integer keys
vector<int> generateRandomKeys(int numKeys, int maxValue) {
    vector<int> keys(numKeys);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, maxValue);
    for (int i = 0; i < numKeys; ++i) {
        keys[i] = dis(gen);
    }
    return keys;
}

int main(int argc, char* argv[]) {
    const int numKeys = 10000;
    const int maxValue = 100000;
    vector<int> keys = generateRandomKeys(numKeys, maxValue);

    // Check for the command line argument for memtable size
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <memtable_size>" << endl;
        return 1;
    }

    int memtableSize = std::atoi(argv[1]);
    if (memtableSize <= 0) {
        cerr << "Invalid memtable size. Please provide a positive integer." << endl;
        return 1;
    }

    // Benchmark B-Tree
    BTree<int> btree(3);  // B-Tree with minimum degree 3

    auto start = high_resolution_clock::now();
    for (int key : keys) {
        btree.insert(key);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "B-Tree Insertion Time: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    for (int key : keys) {
        btree.search(key);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "B-Tree Search Time: " << duration.count() << " ms" << endl;

    // Benchmark LSM Tree
    LSMTree lsmTree(memtableSize);  // LSM Tree with memtable limit 100

    start = high_resolution_clock::now();
    for (int key : keys) {
        lsmTree.put(key, to_string(key));
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "LSM Tree Insertion Time: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    for (int key : keys) {
        lsmTree.get(key);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "LSM Tree Search Time: " << duration.count() << " ms" << endl;

    return 0;
}
