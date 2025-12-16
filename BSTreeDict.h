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
    // Constructor
    BSTreeDict() {
        tree = new BSTree<TableEntry<V>>();
    }

    // Destructor 
    ~BSTreeDict() override { 
        delete tree;
    }

    // Metodo entries
    int entries() const override {
        return tree->size();
    }

    // Metodo insert
    void insert(std::string key, V value) override {
        TableEntry<V> entry_to_insert(key, value);
        tree->insert(entry_to_insert);
    }

    // metodo search
    V search(std::string key) const override {
        TableEntry<V> entry_to_search(key);
        TableEntry<V> found_entry = tree->search(entry_to_search); 
        return found_entry.value;
    }

    // metodo remove
    V remove(std::string key) override {
        TableEntry<V> entry_to_remove(key);
        TableEntry<V> removed_entry = tree->remove(entry_to_remove);
        return removed_entry.value;
    }

    // Sobrecarga operator[]
    V operator[](std::string key) {
        return static_cast<const BSTreeDict<V>*>(this)->search(key);
    }

    // Sobrecarga operator<< 
    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
        out << *(bs.tree);
        return out;
    }
};

#endif
