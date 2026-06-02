#include "queue.hpp"

//循环队列
template <class elemType>
seqQueue<elemType>::seqQueue(int size = 10){
    maxSize = size;
    front = rear = 0;
    elem = new elemType[size];
}

template <class elemType>
seqQueue<elemType>::~seqQueue(){
    delete []elem;
}

template <class elemType>
bool seqQueue<elemType>::isEmpty() const{
    return front == rear;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x){
    if ((rear+1)%maxSize == front) doubleSpace();//用rear和front判断，不直接用maxSize
    rear = (rear+1) % maxSize;//先更新rear
    elem[rear] = x;
}

template <class elemType>
elemType seqQueue<elemType>::deQueue(){
    front = (front + 1) % maxSize;//不让front指向队头保证了代码对称性
    return elem[front];
}

template <class elemType>
elemType seqQueue<elemType>::getHead() const {
    return elem[(front+1) % maxSize];
}

template <class elemType>
void seqQueue<elemType>::doubleSpace(){
    elemType *tmp = elem;
    elem = new elemType[maxSize*2];
    for (int i=1; i<=maxSize; i++)//从1开始，共maxSize-1个元素，书上等于是利用了取模的周期性，改成小于不取模也可以
        elem[i] = tmp[(i+front)%maxSize];
    front = 0;
    rear = maxSize -1;
    maxSize *= 2;
    delete tmp;
}

//链式队列
template <class elemType>
linkQueue<elemType>::linkQueue(){
    front = rear = nullptr;
}

template <class elemType>
linkQueue<elemType>::~linkQueue(){
    elemType *tmp = front;
    while (front != rear){
        front = front->next;
        delete tmp;
        tmp = front;
    }
}

template <class elemType>
bool linkQueue<elemType>::isEmpty() const{
    return front == nullptr;//没有头结点的情况下，用front == rear在只有一个数据的时候，两者都指向该数据，也会被认为空
}

template <class elemType>
elemType linkQueue<elemType>::getHead() const{
    return front->data;
}

//出队和入队都要单独考虑为空的情况
template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x){
    if (rear == nullptr)//要分两种情况，空指针不能用->
        front = rear = new node(x);
    else
        rear = rear->next = new node(x);
}

template <class elemType>
elemType linkQueue<elemType>::deQueue(){
    elemType x = front->data;
    elemType *tmp = front;//要专门把这个删掉
    front = front->next;
    if (front == nullptr) rear == nullptr;//删掉最后一个结点，rear不会自动变成空，要手动解决
    delete tmp;
    return x;
}