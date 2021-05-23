#pragma once
#include <iostream>

using namespace std;

namespace ariel
{
    template<typename T>
    class BinaryTree {

    private:
    struct Node {
        T value;
        Node *parent;;
        Node* right;
        Node* left;
        Node(const T& v, Node* L= nullptr, Node* R= nullptr,Node* p=nullptr)
                : value(v), left(L),right(R),parent(p) {
        }
       // Node(const T& v){value=v;}
    	~Node(){delete left;delete right;}
    };
         // END Node

    class iterator {
    private:
        Node* p_currNode;
        unsigned int depth=0;

    public:
    unsigned int get_depth() const{
        return depth;
    }

        iterator(Node* ptr = nullptr)
                : p_currNode(ptr) {
        }

        
        T& operator*() const {
            
            return p_currNode->value;
        }

        T* operator->() const {
            return &(p_currNode->value);
        }

        // ++i;
        iterator& operator++() {
            //++p_currNode;
            p_currNode = p_currNode->right;
            depth++;
            return *this;
        }

        // i++;
        // 
        const iterator operator++(int) {
            iterator tmp= *this;
            p_currNode= p_currNode->left;
            depth++;
            return tmp;
        }

        bool operator==(const iterator& other) const {
            return p_currNode == other.p_currNode;
        }

        bool operator!=(const iterator& other) const {
            return p_currNode != other.p_currNode;
        }
    };  // END ITERATOR

        Node* _root;
    public:
    BinaryTree() : _root(nullptr){};
        ~BinaryTree(){};

        Node *get_root();
        
        Node *FindNode(Node *n, T nodeValue);

        BinaryTree<T> & add_root(T root);
      
        BinaryTree<T> & add_left(T val, T node);
    
      
        BinaryTree<T> & add_right(T val, T node);
        
        iterator begin()
        {
            return iterator(_root);
        }
        iterator end()
        {
            return iterator(_root);
        }

        iterator end_preorder()
        {
            return iterator(_root);
        }
        iterator begin_preorder()
        {
            return iterator(_root);
        }
        iterator end_inorder()
        {
            return iterator(_root);
        }
        iterator begin_inorder()
        {
            return iterator(_root);
        }
        iterator end_postorder()
        {
            return iterator(_root);
        }
        iterator begin_postorder()
        {
            return iterator(_root);
        }
        friend std::ostream &operator<<(std::ostream &output, const BinaryTree<T> &bt)
        {
            return output;
        }
    };


   template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_root(T root)
    {
          this->_root = new Node(root);
            return *this;
    }

 template <typename T>
    typename BinaryTree<T>::Node *BinaryTree<T>::get_root()
    {
        if (this->_root)
        {
            return this->_root;
        }
        throw("not fount a root for this tree");
    }

     template <typename T>
      typename BinaryTree<T>::Node *BinaryTree<T>::FindNode(BinaryTree::Node *n, T nodeValue){
      if (n== nullptr) return nullptr;
      if (n->value == nodeValue) return n;

   Node *L = FindNode(n->left, nodeValue);
        Node *R = FindNode(n->right, nodeValue);
        if (L == nullptr) {
            return R;
        } else {
            return L;
        }
}


     template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_left(T val, T node)
    {
       
        return *this;
    }

    template <typename T>
    BinaryTree<T> &BinaryTree<T>::add_right(T val, T node)
    {
      
        return *this;
        }


}
