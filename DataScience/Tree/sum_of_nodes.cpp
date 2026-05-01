#include <iostream>

struct node{
    int val, left, right, layer, fin;
    node():val(0),left(0),right(0),layer(0),fin(0){}
    node(int v, int l = 0, int r = 0){val = v; left = l; right = r; layer = 0; fin = v;}
    ~node(){}
};

//前序遍历，下一个结点的值是父节点的值乘以10+自身的val
void cal_fin(node* arr, int c){
    int curr;
    curr = c;
    int last_fin = 0;
    if (arr[curr].left == 0 && arr[curr].right == 0){
        arr[curr].fin = last_fin + arr[curr].fin;
        return ;
    }
    arr[curr].fin = last_fin + arr[curr].fin; 
    last_fin = arr[curr].fin;
    cal_fin(arr,arr[curr].left)
    cal_fin(arr,arr[curr].right)
}

int main(){
    //输入数据
    int n;
    std::cin>>n;

    int v, l, r;
    node* arr = new node[n+1];
    for (int i = 0; i<n; i++){
        std::cin>>v>>l>>r;
        arr[i] = node(v, l, r);
    }
}