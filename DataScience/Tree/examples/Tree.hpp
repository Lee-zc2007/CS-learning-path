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
        virtual T rchild(T x, T flag) const = 0;
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
        binaryTree():root(nullptr){}
        binaryTree(T x){root = new Node(x);}
        ~binaryTree();
        void clear();
        bool isEmpty();
        T Root(T flag) const;
        T lchild(T x, T flag) const;
        T rchild(T x, T flag) const;
        void delLeft(T x);
        void delRight(T x);
        //外部接口，调用private函数实现
        void preOrder();
        void midOrder();
        void postOrder();
        void levelOrder() const;//不需要调用，直接实现
        void createTree(T flag);//构造整棵树，构造函数只负责创建对象    
        T parent(T x, T flag) const {return flag;}//?为什么 return flag?
        int size();
        int height();

    private:
        Node *find(T x, Node *t) const;//查找以t为根结点的子树中值为x的结点
        void clear(Node *&t);//清空以t为根结点的子树，采用指针引用可以把t改为空指针，否则函数会创建一个t的副本，t并不能变成空指针
        //递归遍历的辅助函数
        void preOrder(Node *t) const;
        void midOrder(Node *t) const;
        void postOrder(Node *t) const;
        int size(Node *t) const;
        int height(Node *t) const;
};

#endif