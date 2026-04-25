#include <iostream>
using namespace std;

struct Node {
  int val;
  int left, right, next, num;

  Node() : left(0), right(0), next(-1),num(-1){}
  Node(int v, int l, int r, int nu = -1, int n = -1){val = v; left =l; right = r; num = nu; next = n;}
  ~Node(){}
};


int main(){
  //数据处理
  int n;
  cin>>n;
  
  Node* arr = new Node[n+1];
  int v, l, r;
  for (int i=1; i<n+1; i++){
    cin>>v>>l>>r;
    arr[i] = Node(v, l, r, i);
  }

 //更新next(初始化为-1，先更新最右边为0)
  int k = 1;
  while (arr[k].right != 0){
    arr[k].next = 0;
    k = arr[k].right;
  }


  Node* que = new Node[n];
  que[0] = arr[1];
  int currentLength = 1;//下一个可写入的位置
  int pos = 0;//队首位置
  while (currentLength < n){
    //入队
    if (que[pos].left != 0){
    que[currentLength] = arr[que[pos].left];
    currentLength++;
    }
    if (que[pos].right != 0){
    que[currentLength] = arr[que[pos].right];
    currentLength++;
    }
    //更新pos
    pos++;
  }

  for (int curr = 0; curr < n; curr++){
    if (que[curr].next != 0)
    que[curr].next = que[curr + 1].num;
    cout<<que[curr].next<<endl;
  }


  delete []que;
  delete []arr;
}