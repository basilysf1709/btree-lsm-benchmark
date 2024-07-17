#include "LSMTree.h"
#include <iostream>

int main() {
    LSMTree lsm;

    // Simulate inserts
    for (int i = 0; i < 25; ++i) {
        lsm.put(i, "value " + std::to_string(i));
    }

    // Test lookups
    std::cout << "Get key 5: " << lsm.get(5) << std::endl;
    std::cout << "Get key 20: " << lsm.get(20) << std::endl;
    std::cout << "Get key 30: " << lsm.get(30) << std::endl;

    return 0;
}
