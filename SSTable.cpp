#include "SSTable.h"
#include <fstream>
#include <sstream>

void SSTable::writeToFile(const std::string& filename, const std::map<int, std::string>& memtable) {
    std::ofstream file(filename);
    for (const auto& [key, value] : memtable) {
        file << key << " " << value << "\n";
    }
    file.close();
}

std::map<int, std::string> SSTable::readFromFile(const std::string& filename) {
    std::map<int, std::string> table;
    std::ifstream file(filename);
    std::string line;
    int key;
    std::string value;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> key >> value;
        table[key] = value;
    }
    return table;
}
