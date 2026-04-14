#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"ENTER NO OF ELEMENTS : ";
    cin>>n;
    int a[n];
    cout<<"ENTER ARRAY : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"SORTED ARRAY :";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
// complexity= O(n^2)
// no of swapping = (n)(n-1)/2
