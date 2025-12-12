#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"
using namespace std;

template <typename V>
class BSTreeDict : public Dict<V> {

private:
    BSTree<TableEntry<V>>* tree; 

public:
    BSTreeDict() {
        tree = new BSTree<TableEntry<V>>();
    }

    ~BSTreeDict() {
        delete tree;
    }

    int entries() const override {
        return tree->size();
    }

    void insert(std::string key, V value) override {
        TableEntry<V> entry(key, value);
        if (tree->search(entry)) {
            throw std::runtime_error("Duplicated element!");
        }
        tree->insert(entry);
    }

    V search(std::string key) const override {
        TableEntry<V> entry(key);
        TableEntry<V>* found = tree->search(entry);
        if (!found) {
            throw std::runtime_error("Element not found!");
        }
        return found->value;
    }

    V remove(std::string key) override {
        TableEntry<V> entry(key);
        TableEntry<V>* found = tree->search(entry);
        if (!found) {
            throw std::runtime_error("Element not found!");
        }
        V val = found->value;
        tree->remove(entry);
        return val;
    }

    V operator[](std::string key) {
        return search(key);
    }

    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
        out << *(bs.tree);
        return out;
    }

    friend bool operator<(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key < te2.key;
    }

    friend bool operator>(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key > te2.key;
    }

};

#endif
