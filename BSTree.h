#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"
using namespace std;

template <typenam<T>* root;
		
		
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
	    	if(n != nullptr){ 
				print_inorder(out, n->left);   
				out << n->elem << " ";        
				print_inorder(out, n->right);  
			}
	    }

		
		T max(BSNode<T>* n) const {
			if (n == nullptr) { 
				throw runtime_error("El arbol esta vacio");
			} else if (n->right != nullptr) {
				return max(n->right);  
			} else {
				return n->elem; 
			}
    	}

		
		BSNode<T>* remove_max(BSNode<T>* n){
			if (n->right == nullptr) { // Si no hay hijo derecho, este es el nodo máximo
				BSNode<T>* temp = n->left; // Guarda el subárbol izquierdo (puede ser nullptr)
				delete n; // Borra el nodo actual (el máximo)
				nelem--;
				return temp; // El nodo padre se conectará a 'temp'
			} else {
				n->right = remove_max(n->right); // Continúa buscando el máximo a la derecha
				return n;
			}
		}

		// Método principal para eliminar un elemento
		BSNode<T>* remove(BSNode<T>* n, T e) {
			if (n == nullptr) {
				throw runtime_error("Elemento no encontrado para eliminar");
			} else if (e < n->elem) { // Busca a la izquierda
				n->left = remove(n->left, e);
			} else if (e > n->elem) { // Busca a la derecha
				n->right = remove(n->right, e);
			} else { // n->elem == e: Elemento encontrado
				
				if (n->right == nullptr) {
					BSNode<T>* temp = n->left;
					delete n;
					nelem--;
					return temp;
				}
				
				else if (n->left == nullptr) {
					BSNode<T>* temp = n->right;
					delete n;
					nelem--;
					return temp;
				}
				
				else {
					n->elem = max(n->left);
					n->left = remove(n->left, n->elem);
				}
			}
			return n;
		}
		void delete_cascade(BSNode<T>* n) {
			if (n != nullptr) {
				delete_cascade(n->left);
				delete_cascade(n->right);
				delete n; 
			}
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
			delete_cascade(root);
    	}

	    friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
			bst.print_inorder(out,bst.root);
			return out;
		}
		
    	
};

#endif
