#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,n,num,pos=0,flag=0;
    cout<<"Enter the length of array";
    cin>>n;
    cout<<"Enter the array";
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the key to be searched";
    cin>>num;
    for(int i=0;i<n;i++){
        if(a[i]==num){
            flag=1;
            pos=i+1;
        }
    }
    if(flag==0){
        cout<<"Element not found"<<endl;
    }else{
        cout<<"Element found at "<<pos<<endl;
    }
    return 0;
}
