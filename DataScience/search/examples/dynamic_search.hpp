#ifndef DYNAMIC_SEARCH
#define DYNAMIC_SEARCH

template <class KEY, class OTHER>
struct SET{
    KEY key;
    OTHER other;
};


template <class KEY, class OTHER>
class dynamicSearchTable{
    public:
        virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
        virtual void insert(const SET<KEY, OTHER> &x) = 0;
        virtual void remove(const KEY &x) = 0;
        virtual ~dynamicSearchTable(){}
};

//二叉查找树
template <class KEY, class OTHER>
class BinarySearchTree:public dynamicSearchTable<KEY, OTHER>{
    private:
        struct BinaryNode{
            SET<KEY, OTHER> data;
            BinaryNode *left;
            BinaryNode *right;

            Node(const SET<KEY, OTHER> &thedata, BinaryNode *lf = nullptr, BinaryNode *rt = nullptr):data(thedata),left(lt),right(rt){}
        };

        BinaryNode *root;
    
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        SET<KEY, OTHER> *find(const KEY &x) const;
        void insert(const SET<KEY, OTHER> &x);//需要公有接口的原因是，递归实现需要用root，私有函数可以传递一个root参数，这里root是变化的，而公有函数只能固定访问根结点的root，且调用的时候需要用户传入，但是root作为private参数通常调用者不知道
        void remove(const KEY &x);

    private:
        void insert(const SET<KEY, OTHER> &x, BinaryNode *t);
        void remove(const KEY &x, BinaryNode *t);
        SET<KEY, OTHER> *find(const KEY &x, BinaryNode *t) const;
        void makeEmpty(BinaryNode *t);//用于将树置空
};

//AVL树
template <class KEY, class OTHER>
class AvlTree:public dynamicSearchTable<KEY, OTHER>{
    private:
        struct AvlNode{
            SET<KEY, OTHER> data;
            AvlNode *left;
            AvlNode *right;
            int height;

            AvlNode(const SET<KEY, OTHER> &x, AvlNode *lt, AvlNode *rt, int h = 1):data(x), left(lt), right(rt), height(h){}
        };
    
        AvlNode *root;
    
    public:
        AvlTree(){root = nullptr;}
        ~AvlTree(){makeEmpty(root);}
        void insert(const SET<KEY, OTHER> &x);
        void remove(const KEY &x);
        SET<KEY, OTHER> *find(const KEY &x) const;//没用递归实现

    private:
        void insert(const SET<KEY, OTHER> &x, AvlNode *t);
        bool remove(const KEY &x, AvlNode *t);//一定要bool，表示子树是不是变矮了，删除可能一直影响到根结点，true表示没发生变化
        void makeEmpty(AvlNode *t);
        int height(AvlNode *t) const{return (t == nullptr)?0:t->height;}//防止读到空结点的时候崩溃
        void LL(AvlNode *&t);
        void LR(AvlNode *&t);
        void RL(AvlNode *&t);
        void RR(AvlNode *&t);
        int max(int a, int b){return (a>b)?a:b;}
        bool adjust(AvlNode *&t, int subTree);//删除时用于调整失衡，0表示左子树变矮，1表示右子树变矮
};

//散列表
template <class KEY, class OTHER>
class closeHashTable:public dynamicSearchTable<KEY, OTHER>{
    private:
        struct node{
            SET<KEY, OTHER> data;
            int state;//0-empty 1-active 2-deleted
            node(){state = 0;}
        };
        node *array;
        int size;
        int (*key)(const KEY &x);//函数指针key，指向一个函数，函数的参数是x，返回值是int，用于从KEY提取整数关键字
        static int defaultKey(const KEY &x){return x;}//给函数指针key提供一个默认实现

    public:
        closeHashTable(int length = 101; int (*key)(const KEY &x) = defaultKey);
        ~closeHashTable(){delete []array;}
        SET<KEY, OTHER> *find(const KEY &x) const;
        void insert(SET<KEY, OTHER> &x);
        void remove(const KEY &x);
};

#endif