#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* box_arr = new int[n];
    for (int i=0;i<n;i++){
        cin>>box_arr[i];
    }

    int result=0;

    for (int p=0;p<n;p++){
        result=0;
        for (int q=0;q<n;q++){
            if (box_arr[q]>box_arr[p]){
                result=q;
            }
        }
        cout<<result<<' ';
    }
}