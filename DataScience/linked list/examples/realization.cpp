#include <realization.hpp>
#include <iostream>
using namespace std;
//线性表的顺序实现和链接实现
/*易错点
const没加
currentLength没有维护
*/

//顺序表
//clear visit length和析构函数
template <class elemType>
void seqList<elemType>::clear(){
    currentLength=0;//逻辑上表为空，后续的操作会直接覆盖原有的元素,
    //注意如果元素是对象的话需要析构，指针的话要防止内存泄漏
}

template <class elemType>
elemType seqList<elemType>::visit(int i){
    return data[i];
}

template <class elemType>
int seqList<elemType>::length() const{
    return currentLength;
}

template <class elemType>
seqList<elemType>::~seqList(){
    delete []data;
}

//遍历
template <class elemType>
void seqList<elemType>::traverse() const {
    for (int i=0;i<currentLength;i++)//这里i是基本类型 ++前置和后置区别不大，对于迭代器等复杂类型，++前置效率更高
    cout<<data[i];
}


//构造函数
template <class elemType>
seqList<elemType>::seqList(int initSize){//缺省值只在声明里写，实现里不写
    maxSize = initSize;
    currentLength=0;
    data = new elemType[initSize];
}

//search实现
template <class elemType>
int seqList<elemType>::search(const elemType &x) const{
    for (int i=0;i<currentLength;i++){
        if (data[i]==x)
        return i;
    }
    return -1;
}

/*另一种简洁的写法
template <class elemType>
int seqList<elemType>::search(const elemType &x) const{
    int i;
    for (int i=0;i<currentLength && data[i] != x;++i);
    if (i == currentLength) return -1;
    else return i;
}
*/

//insert和doubleSpace
template <class elemType>
void seqList<elemType>::insert(int i,const elemType &x){
    if (currentLength == maxSize)
    doubleSpace();
    for (int j=currentLength;j>i;j--)
    data[j] = data[j-1];//队列下标从0开始，j=currentLength是空的
    data[i] = x;
    ++currentLength;//要记得维护
}

template <class elemType>
void seqList<elemType>::doubleSpace(){
    elemType *tmp = data;
    maxSize *= 2;//必须要先更新，如果在new里面乘，maxSize不会更新
    data = new elemType[maxSize];
    for (int i=0;i<currentLength;i++)
    data[i] = tmp[i];
    delete []tmp;
}

//删除函数
template <class elemType>
void seqList<elemType>::remove(int i){
    for (int j=i;j<currentLength-1;j++)//必须减一，否则j=currentLength-1会越界
    data[j] = data[j+1];
    currentLength --;
}

//单链表
//move
template <class elemType>
sLinkeList<elemType>::node *sLinkList<elemType>::move(int i) const {//node 不是全局类型，要加作用域限定
    node *tmp = head;
    while (i-->=0) tmp = tmp->next;//i=0时循环执行一次，返回第0个结点，头结点统一了0号结点与后面结点的操作
    return tmp;
}

//构造函数
template <class elemType>
sLinkList<elemType>::sLinkList(){
    head = new node;//要创建新的结点，不能对空指针
    currentLength = 0;
}

//清空函数
template <class elemType>
void sLinklist<elemType>::clear(){
    while (head->next != nullptr){
        node *tmp;
        tmp = head->next;
        head->next = head->next->next;
        delete tmp;
    }
    currentLength = 0;
}

/*书上另一种实现
template <class elemType>
void sLinkList<elemType>::clear(){
    node *p=head->next, *q;
    head->next = nullptr;
    while (p != nullptr){
        q=p->next;
        delete p;//删除的是指针指向的对象，而不是本身
        p=q;
    }
    currentLength = 0;
}
*/

//插入和删除
template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x){
    node *tmp = move(i-1);
    tmp->next = new node(x,tmp->next);//node里面tmp->next指向的还是原来的第i个结点，不需要遍历效率比move（i）高
    currentLength++;
}

template <class elemType>
void sLinkList<elemType>::remove(int i){
    node *p = move(i-1);
    node *q = p->next;
    p->next = q->next;
    delete q;
    currentLength--;
}

//search visit和traverse
template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const {
    int i = 0;
    node *curr = head->next;//不能从head开始，head是空
    while (curr != nullptr && curr->data != x){//顺序不能反，必须先判断是否非空，否则读不到data程序会崩溃
        curr = curr->next;
        i++;
    }

    if (curr == nullptr)
    return -1;

    return i;
}

template <class elemType>
elemType sLinkList<elemType>::visit(int i) const {
    return move(i)->data;
}

template <class elemType>
void sLinkList<elemType>::traverse() const {
    node* p = head->next;
    while (p != nullptr){
        cout<<p->data;
        p = p->next;
    }
}

//双链表
//构造函数
template <class elemType>
dLinkList<elemType>::dLinkList(){
    currentLength = 0;
    head = new node;//head和tail互指，不能为同一个
    head->next = tail = new node;
    tail->pre = head;
}

//插入 删除和move
template <class elemType>
void dLinkList<elemType>::insert(int i, const elemType &x){
    node *curr = move(i-1);
    node *af = curr->next;
    curr->next = new node(x, af, curr);
    af->pre = curr->next;
}

template <class elemType>
void dLinkList<elemType>::remove(int i){
    node *tmp = move(i);
    tmp->pre->next = tmp->next;
    tmp->next->pre = tmp->pre;
    delete tmp;
    --currentLength;
}

template <class elemType>
dLinkList<elemType>::node* dLinkList<elemType>::move(int i) const {//node 也需要作用域限定
    node *curr = head;
    while (i-->0)
    curr = curr->next;
    return curr;
}

//visit clear search 和traverse
template <class elemType>
elemType dLinkList<elemType>::visit(int i) const {
    return move(i)->data;
}

template <class elemType>
void dLinkList<elemType>::clear(){//把head和tail拆出来单独重置，用p和q代替索引交替删除中间部分
     node *p = head->next, q;
     head->next = tail;
     tail->pre = head;
     while (p != tail){
        q = p->next;
        delete p;
        p = q;
     }
     currentLength = 0;
}

template <class elemType>
int dLinkList<elemType>::search(const elemType &x) const{
    node *res = head->next;
    int count = 1;
    while (res != tail){
        if (res->data == x)
        return count;
        res = res->next;
        count++;
    }
    return -1;
}
/*
template <class elemType>
int dLinkList<elemType>::search(const elemType &x) const{
    int i = 1;
    node *res = head->next;
    for (; res != tail && res->data != x; ++i) res = res->next;
    if (res != tail) return i;
    return -1;
}
*/

template <class elemType>
void dLinkList<elemType>::traverse() const {
    node *p = head->next;
    while (p != tail){
        cout<<p->data;
        p = p->next;
    }
}