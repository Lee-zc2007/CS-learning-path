#include <iostream>
using namespace std;

int search(int *a, int x, int n){
    int l = 0, r = n-1;
    int ans = 0;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[mid] < x)
            l = mid + 1;
        else{
            ans = mid + 1;//从1开始编号
            r = mid - 1;//不能直接更成mid，会卡死
        }
    }
    return ans;
}

int main(){
    int n, q;
    cin>>n>>q;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];

    for (int i = 0; i < q; i++){
        int x;
        cin>>x;
        cout<<search(a, x, n)<<endl;
    }
}