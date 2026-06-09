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
    else if (x < t->data.key) return insert(x, t->left);//只要满足BST就行，不一定按照绝对顺序，比如可以 50-右-70-左-60
    else if (x > t->data.key) return insert(x, t->right);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY &x){
    remove(x, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY &x, BinaryNode *t){
    if (t == nullptr) return;
    if (x < t->data.key) return remove(x, t->left);
    else if (x > t->data.key) return remove(x,t->right);//x不等于key的时候先判断删除哪个子树
    else if (t->left != nullptr && t->right != nullptr)//确认x等于key后再看删除的结点有几个子节点，防止破坏BST结构
    {//有两个孩子
        BinaryNode *tmp = t->right;//中序后继
        while (tmp->left != nullptr) tmp = tmp->left;//找到删除结点右子树最左边的结点，将数据覆盖删除结点，维持BST性质，右子树的最左边结点有可能有右子树，所以递归删除这个结点
        t->data = tmp->data;
        remove(t->data.key, t->right);
    }
    else{//只有一个孩子或者没有
        BinaryNode *Oldt = t;//本质没有移动t，所以不需要把父节点连接过来
        t = (t->left != nullptr)?t->left:t->right;
        delete BinaryNode;
    }
}

template <class KEY, class OTHER>
BinarySearchTree<KEY,OTHER>::BinarySearchTree(){
    root = nullptr;
}

template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::~BinarySearchTree(){
    makeEmpty(root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode *t){
    if (t==nullptr) return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *AvlTree<KEY, OTHER>::find(const KEY &x) const {
    AvlNode *t = root;
    while (t != nullptr && x != t->data.key){
        if (t->data.key < x) t = t->right;
        else t = t->left;
    }

    if (t == nullptr) return nullptr;
    else return (SET<KEY, OTHER> *)t;
}

//四种旋转，用于解决失衡的问题
template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LL(AvlNode *&t){
    AvlNode *t1 = t->left;
    t->left = t1->right;
    t1->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    t1->height = max(height(t1->left), height(t)) + 1;
    t = t1;//让父节点连接，所以需要传指针引用
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RR(AvlNode *&t){
    AvlNode *t1 = t->right;
    t->right = t1->left;
    t1->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    t1->height = max(height(t1->right), height(t)) + 1;
    t = t1;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LR(AvlNode *&t){
    RR(t->left);
    LL(t);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RL(AvlNode *&t){
    LL(t->right);
    RR(t);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x){
    insert(x, root);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x, AvlNode *t){
    if (t == nullptr) t = new AvlNode(x, nullptr, nullptr);
    else if (x.key < t->data.key){
        insert(x, t->left);
        if (height(t->left) - height(t->right) >= 2){
            if (x.key < t->left->data.key) LL(t); else LR(t);
        }
    }
    else if (x.key > t->data.key){
        insert(x, t->right);
        if (height(t->right) - height(t->left) >= 2){
            if(x.key < t->right->data.key) RL(t); else RR(t);
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::remove(const KEY &x){
    remove(x, root);
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::remove(const KEY &x, AvlNode *t){
    if (t = nullptr) return true;
    if (x = t->data) {//没有或只有一个儿子
        if (t->left == nullptr || t->right == nullptr){
            AvlNode *oldT = t;
            t = (t->left != nullptr)?t->left:t->right;
            delete oldT;
            return false;
        }
        else {//被删结点有两个儿子
            AvlNode *tmp = t->right;
            while (tmp->left != nullptr) tmp = tmp->left;
            t->data = tmp->data;
            if (remove(t->data.key, t->right)) return true;//与BST相同
            return adjust(t, 1);
        }
    }

    if (x < t->data.key){
        if (remove(x, t->left)) return true;
        return adjust(t, 0);
    }
    else{
        if (remove(x, t->right)) return true;
        return adjust(t, 1);
    }
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::adjust(AvlNode *&t, int subTree){
    if (subTree){
        if (height(t->left) - height(t->right) == 1) return true;//删除前左右高度相同
        if (height(t->left) == height(t->right)) {--t->height; return false;}//删除前右边高1，高度要调整
        if (height(t->left->left) < height(t->left->right)) {LR(t); return false;}//删除前左边高，分成LL和LR两种，LR高度必然-1，LL分两种，L左右相同，高度不变，L左高（t删除后左右差2），高度减一
        LL(t);
        if (height(t->right) == height(t->left)) return false; return true;
    }
    else{
        if (height(t->right) - height(t->left) == 1) return true;
        if (height(t->left) == height(t->right)) {--t->height; return false;}
        if (height(t->right->left) > height(t->right->right)) {RL(t); return false;}
        RR(t);
        if (height(t->right) == height(t->left)) return false; return true;
    }
}