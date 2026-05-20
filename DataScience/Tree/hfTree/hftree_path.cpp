#include <iostream>

struct Node{
    int left;
    long long weight;
    int right;
    Node(int l=0, int w=0, int r=0){left = l; right = r; weight = w;}
    ~Node(){}
};

void cal_wpl(int root, Node *arr, int layer, long long int &ans){//不使用静态类型，递归过程中可能会互相干扰
    if (arr[root].left == 0 && arr[root].right == 0){
        ans += layer * arr[root].weight;
        return;
    }
    cal_wpl(arr[root].left, arr, layer+1, ans);
    cal_wpl(arr[root].right, arr, layer+1, ans);//不能写return，否则右链无法遍历
}

int main(){
    //根结点不一定在一号节点，通过一个数组统计父节点的存在情况，查找根结点，参数传递每一层都有副本，不影响上层
    int n;
    std::cin >> n;
    
    Node *arr = new Node[n+1];
    bool *hasParent = new bool[n+1]();  // 标记是否有父结点
    
    int l, r;
    long long w;
    for (int i=1; i<=n; i++){
        std::cin >> l >> w >> r;
        arr[i] = Node(l, w, r);
        if (l != 0) hasParent[l] = true;
        if (r != 0) hasParent[r] = true;
    }
    
    // 查找根结点（没有父结点的结点）
    int root = 1;
    for (int i=1; i<=n; i++){
        if (!hasParent[i]){
            root = i;
            break;
        }
    }
    
    long long ans = 0;
    cal_wpl(root, arr, 0, ans);
    std::cout << ans;
    
    delete[] arr;
    delete[] hasParent;
    return 0;
}