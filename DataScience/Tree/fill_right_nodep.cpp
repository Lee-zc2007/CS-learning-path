#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : left(nullptr), right(nullptr), next(nullptr){}
  Node(int v, Node *l = nullptr, Node *r = nullptr, Node *n = nullptr){val = v; left =l; right = r; next = n;}
  ~Node(){}
};



int main(){}