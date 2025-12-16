#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>
using namespace std;
template <typename V> 
class TableEntry {
    public:

	    string key;
	    V value;

	    TableEntry(string _key, V _value){
	    	key=_key;
		value=_value;
	    }
	    TableEntry(string n_key){
	    	key=n_key;
	    }
	    TableEntry(){
	    	key=""; 
	    }
	    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
	    	return (te1.key == te2.key);
	    }
	    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
	    	return (te1.key != te2.key);
	    }
	    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
	    	out << "('" << te.key << "' => " << te.value << ")";
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
