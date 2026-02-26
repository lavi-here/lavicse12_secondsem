#include <bits/stdc++.h>
using namespace std;

int main() {
    int i,n,target,low,high,mid;
    cout<<"Enter the length of array";
    cin>>n;
    cout<<"Enter the array";
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>target;
    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==target){
            cout<<"Element found at index "<<mid<<endl;
            return 0;
        }else if(a[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<"Element not found"<<endl;
    return 0;
}
