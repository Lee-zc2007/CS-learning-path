#ifndef STACK
#define STACK
template <class elemType>
class stack{
    public:
        virtual bool isEmpty() const = 0;//判断栈是否为空
        virtual void push(const elemType &x) = 0;//进栈
        virtual elemType pop() = 0;//出栈
        virtual elemType top() const = 0;//取栈顶
        virtual ~stack(){}
};

template <class elemType>
class seqStack : public stack<elemType>{
    private:
        elemType *elem;
        int top_p;
        int maxSize;
        void doubleSpace();
    
        public:
            seqStack(int initSize = 10);
            ~seqStack();
            bool isEmpty() const;
            void push(const elemType &x);
            elemType pop();
            elemType top() const;            
};

template <class elemType>
class linkStack : public stack<elemType>{
    private:
        struct node{
            elemType data;
            node *next;
            node(const elemType &x, node *N = nullptr){data = x; next = N;}
            node():next(nullptr){}
            ~node(){}
        };

        node *top_p;

    public:
        linkStack();
        ~linkStack();
        bool isEmpty();
        void push(const elemType &x){};
        elemType pop();
        elemType top() const;
};



#endif