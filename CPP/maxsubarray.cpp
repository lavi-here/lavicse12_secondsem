//This code is of maximum subarray using brutre force approach
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxsum=INT_MIN;
    for(int st=0;st<n;st++){
        int currsum=0;
        for(int end=st;end<n;end++){
            currsum += a[end];
            maxsum = max(maxsum,currsum);
        }
    }
    cout<<"The maximum sum of subarray is: "<<maxsum;
    return 0;
}