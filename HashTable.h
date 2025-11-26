#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../practica1/ListLinked.h"  
using namespace std;
template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
	int max;
	ListLinked<TableEntry<V>>* table;
	int h(string key){
		int sum = 0;
        	for (size_t i = 0; i < key.length(); i++) {
            		sum += int(key.at(i));
        	}
        	return sum % max;
	}

    public:
        HashTable(int size){
		max = size;
		n=0;
		table= new ListLinked<TableEntry<V>>[max];
	}
	~HashTable(){
		delete[] table;
	}
	int capacity(){
		return max; //max almacena el max cubetas
	}

	void insert(string key, V value) override{
		int pos=h(key);
		TableEntry<V> entry(key,value);
		for (int i = 0; i < table[pos].size(); i++) {
         	   TableEntry<V> current = table[pos].get(i);
            		if (current.key == key) {
                		throw runtime_error("Key '" + key + "' already exists!");
            		}
        	}
		table[pos].prepend(entry);
        	n++;
	
	}
	V search(string key) override {
        int pos = h(key);

        // Buscar en la lista de la cubeta
        for (int i = 0; i < table[pos].size(); i++) {
            TableEntry<V> current = table[pos].get(i);
            if (current.key == key) {
                return current.value;
            }
        }

        // No encontrado
        throw runtime_error("Key '" + key + "' not found!");
    	}



	V remove(string key) override {
        int pos = h(key);

        // Buscar y eliminar
        for (int i = 0; i < table[pos].size(); i++) {
            TableEntry<V> current = table[pos].get(i);
            if (current.key == key) {
                V value = current.value;
                table[pos].remove(i);
                n--;
                return value;
            }
        }

        // No encontrado
        throw runtime_error("Key '" + key + "' not found!");
    	}




	int entries() override {
        	return n;
    	}

	V operator[](string key){
        	return search(key);
    	}
	
friend ostream& operator<<(ostream &out, const HashTable<V> &th){
        out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << endl;
        out << "==============" << endl << endl;
        
        for (int i = 0; i < th.max; i++) {
            out << "== Cubeta " << i << " ==" << endl << endl;
            out << "List => " << th.table[i] << endl << endl;
        }
        
        out << "==============" << endl;
        return out;
    }

        
};

#endif
