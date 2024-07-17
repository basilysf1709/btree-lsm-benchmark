#include "BTree.h"

int main() {
    BTree<int> t(3);  // A B-Tree with minimum degree 3

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    std::cout << "Traversal of the constructed tree is ";
    t.traverse();
    std::cout << std::endl;

    int k = 6;
    (t.search(k) != nullptr) ? std::cout << "\nPresent" : std::cout << "\nNot Present\n";

    k = 15;
    (t.search(k) != nullptr) ? std::cout << "\nPresent" : std::cout << "\nNot Present\n";

    return 0;
}
