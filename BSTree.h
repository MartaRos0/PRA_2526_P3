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
        
        BSNode<T>* create_node(T e){
            return new BSNode<T>(e);
        }

        BSNode<T>* search(BSNode<T>* n, T e) const { 
            if(n == nullptr){
                throw runtime_error("Element not found!");
            } else if(n->elem < e){
                return search(n->right, e);
            } else if(n->elem > e){
                return search(n->left, e);
            } else {
                return n; 
            }
        }

        BSNode<T>* insert(BSNode<T>* n, T e){
            if(n == nullptr){
                nelem++;
                return create_node(e);
            } else if(n->elem == e){
                throw runtime_error("Duplicated element!");
            } else if(n->elem < e){
                n->right = insert(n->right, e);
            } else { // n->elem > e
                n->left = insert(n->left, e);
            }
            return n;
        }

        void print_inorder(ostream &out, BSNode<T>* n) const {
            if(n != nullptr){ 
                print_inorder(out, n->left);   
                out << n->elem << " ";        
                print_inorder(out, n->right);  
            }
        }

        T max(BSNode<T>* n) const {
            if (n->right != nullptr) {
                return max(n->right); 
            } else {
                return n->elem; 
            }
        }

        BSNode<T>* remove(BSNode<T>* n, T e) {
            if (n == nullptr) {
                throw runtime_error("Element not found!");
            } else if (e < n->elem) {
                n->left = remove(n->left, e);
            } else if (e > n->elem) {
                n->right = remove(n->right, e);
            } else { 
                if (n->left == nullptr) {
                    BSNode<T>* temp = n->right;
                    delete n;
                    nelem--; 
                    return temp;
                } else if (n->right == nullptr) {
                    BSNode<T>* temp = n->left;
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

        ~BSTree() {
            delete_cascade(root);
        }

        int size() const{
            return nelem;
        }

        T search(T e) const{
            BSNode<T>* node = search(root, e);
            return node->elem; 
        }
        
        // Sobrecarga del operador []
        T operator[](T e) const{
            return search(e);
        }

        void insert(T e){
            root = insert(root, e);
        }

        T remove(T e){
            T removed_element = search(e); 
            root = remove(root, e); 
            return removed_element;
        }

        // Sobrecarga de operador de salida para imprimir el árbol
        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
            bst.print_inorder(out, bst.root);
            return out;
        }
};

#endif
