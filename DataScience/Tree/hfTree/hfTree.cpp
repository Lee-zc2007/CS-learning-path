#include <iostream>
#include "hfTree.hpp"

template <class Type>
hfTree<Type>::hfTree(const Type *x, const int *w, int size){
    const int MAX_INT = 32767;
    int min1, min2;//最小次小树权值
    int x, y;//最小次小树下标

    length = size*2;//size是传入数组的长度
    elem = new Node[length];

    //置初值
    for (int i=size; i<length; i++){
        elem[i].weight = w[i - size];
        elem[i].data = x[i-size];
        elem[i].parent = elem[i].left = elem[i].right= 0;
    }
    //size往后表示叶子结点，中间的用size-1往前表示，归并后正好size-1个

    //合并森林里的树
    for (int i = size - 1; i>0){
        min1 = min2 = MAX_INT;
        x = y = 0;
        for (int j = i+1; j<length; j++){
            if (elem[j].parent == 0){
                if (elem[j].weight < min1){
                    min2 = min1;
                    y = x;
                    min1 = elem[j].weight;
                    x = j;
                }
                else if (elem[j].weight < min2){
                    min2 = elem[j].weight;
                    y = j;
                }
            }
        }

        elem[x].parent = i;
        elem[y].parent = i;
        elem[i].weight = min1 + min2;
        elem[i].left = y;
        elem[i].right = x;
        elem[i].parent=0;
    }
}

template <class Type>
void hfTree<Type>::getCode(hfCode result[]){
    int size = length/2;
    int p,s;//s是正在处理的结点，p是s的父节点下标

    for (int i=size; i<length; i++){
        result[i-size].data = elem[i].data;
        result[i-size].code = "";
        p = elem[i].parent;
        s = i;
        while (p){
            if (elem[p].left == s) result[i-size].code = '0' + result[i-size].code;
            else result[i-size].code = '1' + result[i-size].code;
            s = p;
            p = elem[s].parent;
        }
    }
}