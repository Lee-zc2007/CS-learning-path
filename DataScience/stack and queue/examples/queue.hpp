#ifndef QUEUE
#define QUEUE

template <class elemType>
class queue{
    public:
        virtual bool isEmpty() const = 0;
        virtual void enQueue(const elemType &x) = 0;
        virtual elemType deQueue() = 0;
        virtual elemType getHead() const = 0;
        virtual ~queue(){}
};

//循环队列
template <class elemType>
class seqQueue: public queue<elemType>{
    private:
        elemType *elem;
        int maxSize;
        int front, rear;//front指向队头元素前一个，rear指向队尾，便于区分队列空和满
        //front初始化为-1，维护数组长度length代替rear，队尾位置即为（length + front）%maxSize
        void doubleSpace();
    public:
        seqQueue(int size = 10);//顺序存储的构造一般要传空间，链式不用
        bool isEmpty() const;
        void enQueue(const elemType &x);
        elemType deQueue();
        elemType getHead() const;
        ~seqQueue();
};

//链接队列
template <class elemType>
class linkQueue:public queue<elemType>{
    private:
        struct node{
            elemType data;
            node *next;
            node(const elemType &x, node *n = nullptr){data = x; next = n;}
            node():next(nullptr){}
            ~node(){}
        };
        node *front, *rear;
    public:
        linkQueue();
        ~linkQueue();
        bool isEmpty() const;
        void enQueue(const elemType &x);
        elemType deQueue();
        elemType getHead() const;
};



#endif