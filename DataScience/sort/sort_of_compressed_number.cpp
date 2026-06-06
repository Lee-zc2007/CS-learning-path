#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> arr, temp;
    for (int i=0; i<n; i++){
        std::cin >> arr[i];
        temp.push_back(arr[i]);
    }

    sort(temp.begin(), temp.end());//O(nlogn)
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    //unique将重复的元素移动到容器末尾，返回的it指向第一个重复元素，但是只能对相邻的重复元素操作，所以需要先排序后操作
    //用erase可以将指定部分元素删除并缩小容器长度

    std::unordered_map<int, int> rank;
    for (int i = 0; i<n; i++){
        rank[temp[i]] = i+1;
    }
    for (int i=0; i<n; i++)
    std::cout << rank[arr[i]] << ' ';
}



//不使用stl
#include <cstdio>
#include <cstring>

const int MAXN = 300005;    // 最大元素数量
const int MOD = 400009;     // 哈希桶数量（通常选第一个大于元素数量的素数）

// 原数组和临时数组
int arr[MAXN];   // 原数组
int temp[MAXN];  // 排序去重数组

// 哈希表结点
struct Node {
    int key;    // 原始编号
    int value;  // 压缩编号
    int next;   // 链表指向下一个节点
};

Node node[MAXN];
int head[MOD];   // 哈希桶头指针
int tot = 0;     // 哈希表节点总数

// 哈希函数
int hash_func(int x) {
    long long y = (long long)x;
    y = (y % MOD + MOD) % MOD; // 保证非负
    return (int)y;
}

// 插入哈希表（头插法）
void insert(int key, int value) {
    int h = hash_func(key);
    node[tot].key = key;
    node[tot].value = value;
    node[tot].next = head[h];
    head[h] = tot;
    tot++;
}

// 查询哈希表
int find(int key) {
    int h = hash_func(key);
    for (int i = head[h]; i != -1; i = node[i].next) {
        if (node[i].key == key) return node[i].value;
    }
    return -1; // 理论上不会发生
}

// 快速排序
void swap(int &a, int &b) { int t = a; a = b; b = t; }

void quicksort(int *a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    int pivot = a[l];
    while (i < j) {
        while (i < j && a[j] >= pivot) j--;
        while (i < j && a[i] <= pivot) i++;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[l], a[i]);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);

    // 读入原数组
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        temp[i] = arr[i]; // 复制一份
    }

    // 排序
    quicksort(temp, 0, n - 1);

    // 去重
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || temp[i] != temp[i - 1]) {
            temp[m++] = temp[i];
        }
    }

    // 初始化哈希表
    memset(head, -1, sizeof(head));
    tot = 0;

    // 建立哈希映射：原编号 → 压缩编号
    for (int i = 0; i < m; i++) {
        insert(temp[i], i + 1); // 压缩编号从1开始
    }

    // 输出压缩结果
    for (int i = 0; i < n; i++) {
        int rank = find(arr[i]);
        printf("%d%c", rank, i == n - 1 ? '\n' : ' ');
    }

    return 0;
}