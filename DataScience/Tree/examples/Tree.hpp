#ifndef TREE
#define TREE

//树的抽象类
template <class elemType>
class tree{
    public:
        virtual void clear() = 0;
        virtual bool isEmpty() = 0;
        virtual elemType root(elemType flag) = 0;//elemType 是任意类型，不一定存在空值，所以必须返回flag
        virtual elemType parent(elemType x, elemType flag) = 0;
        virtual elemType child(elemType x; int i; elemType flag) = 0;
        virtual void traverse() const = 0;
        virtual void remove(elemType x; int i) = 0;//剪枝，去掉结点x的第i个子树
};

//二叉树的抽象类
template <class T>
class bTree{
    public:
        virtual void clear() = 0;
        virtual bool isEmpty() = 0;
        virtual T root(T flag) const = 0;
        virtual T parent(T x, T flag) const = 0;
        virtual T lchild(T x, T flag) const = 0;
        virtual T rchild(T x; T flag) const = 0;
        virtual void delLeft(T x) = 0; 
        virtual void delRight(T x) = 0; 
        virtual void preOrder () const = 0; 
        virtual void midOrder () const = 0; 
        virtual void postOrder () const= 0; 
        virtual void levelOrder () const = 0; 
};

template <class T>
class binaryTree: public bTree<T>{
        friend void printTree(const binaryTree &t, T flag);
    private:
        struct Node{
            Node *left, *right;
            T data;
            Node(T x; Node *l = nullptr; Node *r = nullptr):data(x), left(l), right(r){}
            Node():left(nullptr), right(nullptr){}
            ~Node(){}
        };

        Node *root;
    
    public:
        void clear();
        bool isEmpty();
        void create(T flag);
};

#endif