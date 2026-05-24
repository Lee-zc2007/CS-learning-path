#include <iostream>
#include <algorithm>
using namespace std;

//每次比较k/2的位置，小的可以删除，更新k和左指针位置
int find(int *a, int *b, int k, int n, int m){
    int la = 0, lb = 0, pa = 0, pb = 0;
    while (true){
        if (la == n)
            return b[lb + k - 1];
        if (lb == m)
            return a[la + k - 1];
        if (k == 1)
            return min(a[la], b[lb]);
        
        pa = min(la + k/2, n) - 1;
        pb = min(lb + k/2, m) - 1;

        
        if (a[pa] <= b[pb]){
            k -= pa - la + 1;   
            la = pa + 1;
        }
        else{
            k -= pb - lb + 1;
            lb = pb + 1;
        }
    }
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int *a = new int[n];
    int *b = new int[m];
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<m; i++)
        cin>>b[i];

    for (int i = 0; i < q; i++){
        int k;
        cin>>k;
        cout<<find(a, b, k, n, m)<<endl;
    }
    return 0;
}