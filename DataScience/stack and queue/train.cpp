#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr_in = new int[n];
    int* arr_out = new int[n];
    for (int i=0;i<n;i++)
        cin>>arr_in[i];
    for (int i=0;i<n;i++)
        cin>>arr_out[i];

    int j=0;
    int top=-1;
    int* temp = new int[n];
    for (int i=0;i<n;i++){
        if (arr_in[i]==arr_out[j])
        j++;
        else{
            top++;
            temp[top]=arr_in[i];
        }
        while (top>=0 && temp[top]==arr_out[j]){
            top--;
            j++;
        }
        
    }


    if (top==-1)
    cout<<"YES";
    else
    cout<<"NO";
}

