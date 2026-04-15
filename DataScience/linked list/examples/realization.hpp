#ifndef LINKED_LIST
#define LINKED_LIST

//抽象类
template <class elemType>
class list{
    public:
    virtual void clear()=0;//删除所有元素
    virtual int length() const =0;//求线性表长度 不需要对表本身操作，用const
    virtual int insert(int i, const elemType &x)=0;//插入元素 用引用避免拷贝
    virtual int search(const elemType &x)=0;//搜索元素x是否出现
    virtual elemType visit(int i) const =0;//访问i位置的元素
    virtual void traverse() const =0;//遍历
    virtual ~list(){};
};

//顺序表类
template <class elemType>
class seqList: public list<elemType>{
    private:
        elemType *data;
        int currentLength;
        int maxSize;
        void doubleSpace();
    public:
        seqList(int initSize=10);
        ~seqList();
        void clear();
        int length() const;
        void insert(int i, const elemType &x);
        void remove(int i);
        int search(const elemType &x) const;//非const引用只能绑定到左值，临时值不能传入，不加引用就会造成拷贝
        elemType visit(int i) const;
        void traverse() const;
};

//链接表类
template <class elemType>
class sLinkList: public lsit<elemType>{
    private:
        struct node{
            elemType data;
            node *next;

            node(const elemType &x,node *n=nullptr){
                data = x;
                next = n;
            }
            node():next(nullptr){};//创造空结点
            ~node(){}
        };//结构体定义和class一样要加分号

        node *head;//头指针
        int currentLength;//表长，不能直接初始化，除非用静态变量

        node *move(int i) const;//返回第i个结点的地址

    public:
        sLinkList();
        ~sLinkList(){clear(),delete head;}

        void clear();
        int length() const {return currentLength;}
        void insert(int i,const elemType &x);
        void remove(int i);
        int search(const elemType &x) const;
        elemType visit(int i) const;
        void traverse() const;
};

#endif
