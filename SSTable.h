#ifndef SSTABLE_H
#define SSTABLE_H

#include <map>
#include <string>

class SSTable {
public:
    static void writeToFile(const std::string& filename, const std::map<int, std::string>& memtable);
    static std::map<int, std::string> readFromFile(const std::string& filename);
};

#endif // SSTABLE_H
