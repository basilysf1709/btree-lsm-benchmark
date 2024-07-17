#ifndef LSMTREE_H
#define LSMTREE_H

#include "SSTable.h"
#include <vector>
#include <map>
#include <string>

class LSMTree {
    std::map<int, std::string> memTable;
    std::vector<std::string> ssTableFiles;
    size_t memTableLimit;

public:
    LSMTree(size_t limit = 10);
    void put(int key, std::string value);
    std::string get(int key);
    void flushMemTable();
};

#endif // LSMTREE_H
