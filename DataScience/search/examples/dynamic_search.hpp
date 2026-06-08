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
        void makeEmpty(BinaryNode *t);
};

#endif