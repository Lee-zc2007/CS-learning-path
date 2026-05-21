#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack.hpp>
using namespace std;

template <class elemType>
seqStack<elemType>::seqStack(int initSize = 10){
    elem = new elemType[initSize];
    maxSize = initSize;
    top_p = -1;
}

template <class elemType>
seqStack<elemType>::~seqStack(){
    delete []elem;
}

template <class elemType>
bool seqStack<elemType>::isEmpty() const {
    return top_p == -1;
}

template <class elemType>
void seqStack<elemType>::push(const elemType &x){
    if (top_p == maxSize - 1)
    doubleSpace();
    elem[++top_p] = x;//++只能写前面，先自增后使用
}

template <class elemType>
elemType seqStack<elemType>::pop(){
    elemType temp = elem[top_p];
    top_p--;
    return temp;
    //或 return elem[top_p--];
}

template <class elemType>
elemType seqStack<elemType>::top() const {
    return elem[top_p];
}

template <class elemType>
void seqStack<elemType>::doubleSpace(){
    elemType *temp = elem;
    elem = new elemType[2 * maxSize];
    for (int i = 0; i<maxSize; i++) elem[i] = temp[i];
    //std::copy(temp, temp + top_p + 1, elem) 在algorithm库中，前两个参数是起始位置和结束位置，前闭后开，第三个参数是复制到的目标的起始位置
    maxSize *= 2;
    delete []temp;
}

//用栈判断回文数
bool isReverse(const char *s){//常量的指针传递和引用传递都要用const，值传递不用，会赋值副本，副本不带有const属性
    int len = strlen(s);
    seqStack<char> st(len);
    for (int i = 0; i<len; i++)
        st.push(s[i]);
    int j = 0;
    while (!st.isEmpty()){
        if (st.pop() != s[j])
            return false;
        j++;
    }
    return true;
    /*判断部分可以替换为
    for (int i = 0; !st.isEmpty(); i++)
        if (s[i] != st.pop()) return false;
    return true;
    */
}