#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>

template <typename T>
class BTreeNode {
public:
    BTreeNode(int _t, bool _leaf);

    void traverse();
    BTreeNode<T>* search(T k);

    void insertNonFull(T k);
    void splitChild(int i, BTreeNode<T>* y);

private:
    int t;  // Minimum degree
    bool leaf;  // True when node is a leaf. Otherwise false
    std::vector<T> keys;  // Array of keys
    std::vector<BTreeNode<T>*> children;  // Array of child pointers
    int n;  // Current number of keys

    template <typename U> friend class BTree;
};

template <typename T>
class BTree {
public:
    BTree(int _t);

    void traverse();
    BTreeNode<T>* search(T k);
    void insert(T k);

private:
    BTreeNode<T>* root;
    int t;  // Minimum degree
};

#endif // BTREE_H
