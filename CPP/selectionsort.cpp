// we select smallest element first and give it the position of first element 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,min,pos;
    cout<<"Enter length of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter elements of array : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
    min=a[i];
    pos=i;
    for(int j=i+1;j<n;j++){
        if(a[j]<min){
            min=a[j];
            pos=j;
        }
    }
    int t=a[i];
    a[i]=a[pos];
    a[pos]=t;
}
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
return 0;
}
