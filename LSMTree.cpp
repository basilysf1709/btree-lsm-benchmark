#include "LSMTree.h"

LSMTree::LSMTree(size_t limit) : memTableLimit(limit) {}

void LSMTree::put(int key, std::string value) {
    memTable[key] = value;
    if (memTable.size() >= memTableLimit) {
        flushMemTable();
    }
}

std::string LSMTree::get(int key) {
    if (memTable.find(key) != memTable.end()) {
        return memTable[key];
    }
    for (auto it = ssTableFiles.rbegin(); it != ssTableFiles.rend(); ++it) {
        auto table = SSTable::readFromFile(*it);
        if (table.find(key) != table.end()) {
            return table[key];
        }
    }
    return "Key not found";
}

void LSMTree::flushMemTable() {
    std::string filename = "sst" + std::to_string(ssTableFiles.size()) + ".txt";
    SSTable::writeToFile(filename, memTable);
    ssTableFiles.push_back(filename);
    memTable.clear();
}
