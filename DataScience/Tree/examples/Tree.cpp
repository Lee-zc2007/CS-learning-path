#include "Tree.hpp"
#include "linkQueue.hpp"
#include <iostream>
#include <queue>
#include <list>

template <class T>
bool binaryTree<T>::isEmpty(){
    return root == nullptr;
}

template <class T>
T binaryTree<T>::Root(T flag) const {
    if (root == nullptr) return flag;
    else return root->data;
}

template <class T>
void binaryTree<T>::clear(){
    clear(root);
}

template <class T>
binaryTree<T>::~binaryTree(){
    clear(root);
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t){
    //终止条件
    if (t == nullptr) return;
    //递归删除，不能加return，否则会提前终止
    clear(t->left);
    clear(t->right);
    //处理根结点
    delete t;
    t = nullptr;
}

template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const {
    if (t == nullptr) return;
    std::cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}

template <class T>
void binaryTree<T>::preOrder(){
    std::cout << "\n 前序遍历：";
    preOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const {
    if (t == nullptr) return;
    midOrder(t->left);
    std::cout << t->data << ' ';
    midOrder(t->right);
}

template <class T>
void binaryTree<T>::midOrder(){
    std::cout << "\n 中序遍历：";
    midOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const {
    if (t == nullptr) return;
    postOrder(t->left);
    postOrder(t->right);
    std::cout << t->data << ' ';
}

template <class T>
void binaryTree<T>::postOrder(){
    std::cout << "\n 后序遍历：" << ' ';
    postOrder(root);
}

template <class T>
void binaryTree<T>::levelOrder() const {
    linkQueue<Node *> que;//自己实现的linkQueue,等价于std::queue<Node *, std::list<Node *>> que;
    Node *tmp;

    std::cout << "\n 层次遍历：" << ' ';
    que.enQueue(root);

    while (!que.isEmpty()){
        tmp = que.deQueue();
        std::cout << tmp->data << ' ';
        if (tmp->left) que.enQueue(tmp->left);
        if (tmp->right) que.enQueue(tmp->right);
    }
}

template <class T>
binaryTree<T>::Node *binaryTree<T>::find(T x, binaryTree<T>::Node *t) const{
    Node *tmp;
    if (tmp == nullptr) return nullptr;
    if (t->data == x) return t;
    if (tmp = find(x,t->left)) return tmp;
    else return (tmp = find(x, t->right)); 
}

template <class T>
void binaryTree<T>::delLeft(T x){
    Node *tmp = find(x, root);
    if (tmp == nullptr) return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(T x){
    Node *tmp = find(x, root);
    if (tmp == nullptr) return;
    clear(tmp->right);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const{
    Node * tmp = find(x, root);
    if (tmp == nullptr || tmp->left == nullptr) return flag;
    return tmp->left->data;
}

template <class T>
T binaryTree<T>::rchild(T x, T flag) const{
    Node * tmp = find(x, root);
    if (tmp == nullptr || tmp->right == nullptr) return flag;
    return tmp->right->data;
}

template <class T>
void binaryTree<T>::createTree(T flag){
    std::queue<Node *, std::list<Node *>> que;
    Node *tmp;
    T x, ldata, rdata;

    std::cout << "\n 请输入根结点：" << endl;
    std::cin >> x;
    root = new Node(x);
    que.enQueue(root);

    //先入队根结点，队列为空的时候循环结束
    while (!que.empty()){
        std::cout << "\n 请输入" << tmp->data << "的两个儿子（flag表示空结点）";
        std::cin >> ldata >> rdata;
        if (ldata != flag) que.enQueue(tmp->left = new Node(ldata));
        if (ldata != flag) que.enQueue(tmp->right = new Node(rdata));
    }

    std::cout << "create completed!\n";
}

template <class T>
void printTree(const binaryTree<T> &t, T flag){
    //这里@为flag，针对字符树写的
    std::queue<T> que;
    que.enQueue(root->data);
    cout<<endl;
    while (!que.empty()){
        char p,l,r;
        p = que.deQueue();
        l = t.lchild(p, flag);
        r = t.rchild(p, flag);
        std::cout << p << ' ' << l << ' ' << r << endl;
        if (l != '@') que.enQueue(l);
        if (r != '@') que.enQueue(r);
    }
}

template <class T>
int binaryTree<T>::size(){
    return size(root);
}

template <class T>
int binaryTree<T>::size(binaryTree<T>::Node *t) const{
    if (t == nullptr) return 0;
    return 1 + size(t->left) + size(t->right);
}

template <class T>
int binaryTree<T>::height(){
    return height(root);
}

template <class T>
int binaryTree<T>::height(binaryTree<T>::Node *t){
    if (t == nullptr) return 0;
    else {
        lt = height(t->left);
        rt = height(t->right);
        return 1+((rt>lt) ? rt : lt);
    }
}