#include "dynamic_search.hpp"

template <class KEY, class OTHER>
SET<KEY, OTHER>* BinarySearchTree<KEY, OTHER>::find(const KEY &x) const {
    return find(x, root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* BinarySearchTree<KEY, OTHER>::find(const KEY &x, BinaryNode *t) const{
    if (t == nullptr || t->data.key == x) return (SET<KEY, OTHER> *)t;
    if (x < t->data.key) return find(x, t->left);
    else return find(x,t->right);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x){
    insert(x, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x, BinaryNode *t){
    if (t = nullptr){
        t = new BinaryNode(x, nullptr, nullptr);
    }
    else if (x < t->data.key) return insert(x, t->left);
    else if (x > t->data.key) return insert(x, t->right);
}

