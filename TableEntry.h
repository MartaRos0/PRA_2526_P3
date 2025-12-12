#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>
#include <stdexcept>
using namespace std;

template <typename V> 
class TableEntry {
public:
    string key;
    V value;

    // Constructores
    TableEntry(string k, V v) : key(k), value(v) {}
    TableEntry(const TableEntry<V>& other) : key(other.key), value(other.value) {}
    TableEntry(string k) : key(k) {} // Constructor útil para la búsqueda (solo con clave)

    // Sobrecarga de operadores de comparación (< y >) por clave.
    // Necesarios para la navegación en BSTree.
    friend bool operator<(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key < te2.key; 
    }

    friend bool operator>(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key > te2.key;
    }
    
    // El BSTree.h utiliza '==' en el método search
    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key == te2.key;
    }
    
    // El BSTree.h utiliza '!=' en el método search
    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key != te2.key;
    }

    // Sobrecarga del operador de impresión
    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
        out << "('" << te.key << "' => " << te.value << ")";
        return out;
    }
};

#endif