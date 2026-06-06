#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

template <class Type>
class priorityQueue: public queue<Type>{
    public:
        priorityQueue(int capacity = 100);
        priorityQueue(const Type data[], int size);
        ~priorityQueue();
        bool isEmpty() const;
        void enQueue(const Type &x);
        Type deQueue();
        Type getHead() const;
    private:
        int currentSize;
        Type *arr;
        int maxSize;

        void doubleSize();
        void prelocateDown(int hole);
        void buildHeap();
};

#endif