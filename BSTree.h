#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"
using namespace std;
template <typename T> 
class BSTree {
    private:

	    int nelem;
	    BSNode<T>* root;
		
		//Busqueda recursiva
	    BSNode<T>* search(BSNode<T>* n, T e) const{ 
	    	if(n==nullptr){
				throw runtime_error("Elemento no encontrado");
			}else if(n->elem < e){
				return search(n->right,e);
			}else if(n->elem > e){
				return search(n->left,e);
			}else{
				return n;
			}
	    }

	    BSNode<T>* insert(BSNode<T>* n, T e){
	    	if(n==nullptr){
				nelem++;
				return new BSNode<T>(e);
			}else if(n->elem==e){
				throw runtime_error("Elemento duplicado");
			}else if(n->elem < e){
				n->right=insert(n->right,e);
			}else{
				n->left=insert(n->left,e);
			}
			return n;
	    }

	    void print_inorder(ostream &out, BSNode<T>* n) const{
	    	if(n==nullptr){
				print_inorder(out, n->left);   
				out << n->elem << " ";        
				print_inorder(out, n->right);  
			}
	    }

		T max(BSNode<T>* n) const {
			if (n != nullptr) {
				throw runtime_error("Elemento no encontrado");
			} else if (n->right != nullptr) {
				return max(n->right);  
			} else {
				return n->elem;
			}
    	}

		BSNode<T>* remove_max(BSNode<T>* n){

			//aun no está acabada
		}

		BSNode<T>* remove(BSNode<T>* n, T e) {
			//aun no está acabada
		}

		void delete_cascade(BSNode<T>* n) {
			//aun no está acabada
		}
    public:
	    BSTree(){
			nelem=0;
			root=nullptr;
		}

	    int size() const{
	    	return nelem;
	    }

	    T search(T e) const{
			BSNode<T>* node = search(root, e);
			return node->elem;
	    }
		
	    T operator[](T e) const{
			return search(e);
	    }

	    void insert(T e){
			root=insert(root,e);
	    }

		void remove(T e){
			root=remove(root, e);
		}

		~BSTree() {
			//aun no está acabada
    	}

	    friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
			bst.print_inorder(out,bst.root);
			return out;
		}
		
    	
};

#endif
