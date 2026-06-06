#include <iostream>
#include "priorityQueue.hpp"

template <class Type>
priorityQueue<Type>::priorityQueue(int capacity = 100){
    arr = new Type[capacity];
    currentSize = 0;
    maxSize = capacity;
}


template <class Type>
priorityQueue<Type>::~priorityQueue(){
    delete []arr;
}


template <class Type>
bool priorityQueue<Type>::isEmpty() const {
    return currentSize == 0;
}

template <class Type>
Type priorityQueue<Type>::getHead() const{
    return arr[1];
}

template <class Type>
void priorityQueue<Type>::enQueue(const Type &x){
    if (currentSize == maxSize - 1) doubleSpace()//最后一个位置要加入新的数据，第一个位置不存
    
    //向上过滤
    int hole = ++currentSize;
    while (hole > 1 && x < arr[hole/2]){
        arr[hole] = arr[hole/2];
    }
    arr[hole] == x;
}

template <class Type>
Type priorityQueue<Type>::deQueue(){
    Type minimal = arr[1];
    arr[1] = arr[currentSize--];
    prelocateDown(1);
    return minimal;
}

template <class Type>
void priorityQueue<Type>::prelocateDown(int hole){
    Type tmp = arr[hole];//暂存要过滤的元素
    int child;//存放最小的儿子
    for (; hole*2 <= currentSize; hole = child){
        child = hole * 2;//先更新child，经历一次循环再更新hole，方便比较和存值
        if (child < currentSize && arr[child+1] < arr[child]) child++;//找到较小的儿子
        if (arr[child] < tmp) arr[hole] = arr[child];//如果儿子更小就交换，否则就break
        else break;
    }
    arr[hole] = tmp;
}

template <class Type>
void priorityQueue<Type>::buildHeap(){//用于一开始就有一个乱序数组，要构建成堆
    //数组顺序天然满足完全二叉树的要求
    for (int i=currentSize/2; i>0; i--){
        prelocateDown(i);
    }
}

template <class Type>
priorityQueue<Type>::priorityQueue(const Type data[], int size):maxSize(size + 10), currentSize(size){
    arr = new Type[maxSize];//10是预留enqueue的位置，经验值
    for (int i=0; i<currentSize; i++)
        arr[i+1] = data[i];
    buildHeap();
}