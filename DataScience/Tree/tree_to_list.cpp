/*给你二叉树的根结点root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用TreeNode ，其中right子指针指向链表中下一个结点，而左子指针始终为null 。

展开后的单链表应该与二叉树 先序遍历 顺序相同。

第一行输入一个整数n，表示二叉树的节点数。
接下来n行，每行输入三个整数val,left,right表示一个节点的信息。其中 val 是节点的值，left 是左子节点的编号，
right 是右子节点的编号。节点编号从 1 到 n，0 表示空节点。

输出展开后的单链表，按照先序遍历的顺序输出每个节点的值，节点之间用一个空格分隔。*/

#include <iostream>
using namespace std;

//构建TreeNode
struct TreeNode{
    int val, left, right;
    TreeNode():val(0), left(0), right(0){}
};

//前序遍历实现(直接在数组的基础上展开：维护一个栈，将结点依次进栈，出栈的时候把左右结点按照先右后左出栈)
// void preOr(int n,TreeNode *arr){
//     TreeNode *tmp = new TreeNode[n];
//     int currentLength = 0;
//     tmp[currentLength] = arr[1];
//     currentLength++;

//     while (currentLength){
//         cout<<tmp[currentLength-1].val<<' ';
//         int l = tmp[currentLength-1].left;//记录出栈结点的左右子结点位置
//         int r = tmp[currentLength-1].right;
//         currentLength--;
//         if (r != 0){
//             tmp[currentLength] = arr[r];
//             currentLength++;
//         }
//         if (l != 0){
//             tmp[currentLength] = arr[l];
//             currentLength++;
//         }
//     }

//     delete []tmp;
// }

//展开为单链表（把右子树接到左子树的最右边，把左子树移到右边）
void flat(TreeNode *arr, int root){
    int curr = root;
    while (curr != 0){
        //需要找到左子树的最右边结点，以根结点为起点，按照前序遍历，根结点为0的时候代表遍历完成
        if (arr[curr].left != 0){
            int leftson = arr[curr].left;
            while (arr[leftson].right != 0)
                leftson = arr[leftson].right;
        
        //把右子树接到左子树最右边后，移动左子树到右边
            arr[leftson].right = arr[curr].right;
            arr[curr].right = arr[curr].left;
            arr[curr].left = 0;
        }
        curr = arr[curr].right;
    }
}

int main(){
    //数据输入
    int n,x,l,r;
    cin>>n;
    TreeNode *arr = new TreeNode[n+1];
    for (int i=1; i<n+1; i++){
        cin>>x>>l>>r;
        arr[i].val = x;
        arr[i].left = l;
        arr[i].right = r;
    }

    //遍历
    // preOr(n,arr);
    flat(arr, 1);
    int curr = 1;
    while (curr != 0){
        cout<<arr[curr].val<<' ';
        curr = arr[curr].right;
    }


    delete []arr;
}