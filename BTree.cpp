#include "BTree.h"

template <typename T>
BTreeNode<T>::BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf), n(0) {
    keys.resize(2 * t - 1);
    children.resize(2 * t);
}

template <typename T>
void BTreeNode<T>::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) {
            children[i]->traverse();
        }
        std::cout << " " << keys[i];
    }
    if (!leaf) {
        children[i]->traverse();
    }
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::search(T k) {
    int i = 0;
    while (i < n && k > keys[i]) {
        i++;
    }
    if (i < n && keys[i] == k) {
        return this;
    }
    if (leaf) {
        return nullptr;
    }
    return children[i]->search(k);
}

template <typename T>
void BTreeNode<T>::insertNonFull(T k) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n++;
    } else {
        while (i >= 0 && keys[i] > k) {
            i--;
        }
        if (children[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < k) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(k);
    }
}

template <typename T>
void BTreeNode<T>::splitChild(int i, BTreeNode<T>* y) {
    BTreeNode<T>* z = new BTreeNode<T>(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }
    if (!y->leaf) {
        for (int j = 0; j < t; j++) {
            z->children[j] = y->children[j + t];
        }
    }
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--) {
        children[j + 1] = children[j];
    }
    children[i + 1] = z;
    for (int j = n - 1; j >= i; j--) {
        keys[j + 1] = keys[j];
    }
    keys[i] = y->keys[t - 1];
    n++;
}

template <typename T>
BTree<T>::BTree(int _t) : root(nullptr), t(_t) {}

template <typename T>
void BTree<T>::traverse() {
    if (root != nullptr) {
        root->traverse();
    }
}

template <typename T>
BTreeNode<T>* BTree<T>::search(T k) {
    return (root == nullptr) ? nullptr : root->search(k);
}

template <typename T>
void BTree<T>::insert(T k) {
    if (root == nullptr) {
        root = new BTreeNode<T>(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode<T>* s = new BTreeNode<T>(t, false);
            s->children[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            s->children[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

template class BTreeNode<int>;
template class BTree<int>;
