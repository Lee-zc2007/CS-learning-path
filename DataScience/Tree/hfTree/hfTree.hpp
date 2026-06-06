#ifndef HFTREE
#define HFTREE

#include <cstring>

template <class Type>
class hfTree{
    private:
        struct Node{
            Type data;
            int weight;
            int parent, left, right;
        };

        Node *elem;
        int length;
    
    public:
        struct hfCode{
            Type data;//待编码的字符
            string code;//对应的哈夫曼编码
        };
        hfTree(const Type *x, const int *w, int size);
        void getCode(hfCode result[]);
        ~hfTree(){delete []elem;}
};

#endif