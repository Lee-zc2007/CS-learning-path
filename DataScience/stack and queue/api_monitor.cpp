#include <iostream>
using namespace std;

int main(){
    int id,n,sup;
    char subs;
    cin>>id;
    cin>>subs;
    cin>>n;

    int* req = new int[n];
    int* res = new int[n];
    for (int i=0;i<n;i++)
    cin>>req[i];

    switch (subs){
        case 'a':
        sup = 3;
        break;

        case 'b':
        sup = 6;
        break;

        case 'c':
        sup = 9;
        break;
    }


    int arr[10];
    int count=0;
    for (int i=0;i<n;i++){
        if(i>9 && arr[i%10]==1)//先移除，用原来的count判断，接受请求过后再更新count，先更新count会出错
        count--;

        if (req[i]==id && count<sup){
            res[i]=1;
            arr[i%10]=1;
            count++;
        }
        else if (req[i]==id && count>=sup)
        arr[i%10]=res[i]=-1;
        else if (req[i]!=id)
        arr[i%10]=res[i]=0;
    }

    for (int i=0;i<n;i++){
        cout<<res[i]<<' ';
    }

    delete []res;
    delete []req;
}