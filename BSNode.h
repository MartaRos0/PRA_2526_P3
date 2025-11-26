#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
	    T elem;
	    BSNode<T>* left;
	    BSNode<T>* right;
	    BSNode(T _elem, BSNode<T>* _left=nullptr, BSNode<T>* _right=nullptr){
	    	elem=_elem;
		left=_left;
		right=_right;   
	    }

	    friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
	    	out<<bsn.elem;
		return out;
	    }
    		
};

#endif
