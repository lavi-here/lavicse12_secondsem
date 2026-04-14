#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countSort(int arr[], int size, int place){
    const int max = 10;
    int output[size];
    int count[max];
    for (int i = 0; i < max; ++i)
       {
         count[i] = 0;
       }
    for (int i = 0; i < size; i++)
        {
            count[(arr[i] / place) % 10]++;
        }
    for (int i = 1; i < max; i++)
        {
            count[i] += count[i - 1];
        }
    for (int i = size - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
        {
            arr[i] = output[i];
        }
}

void radixsort(int arr[], int size) {
    int max = getMax(arr, size);
    for (int place = 1; max / place > 0; place *= 10)
        countSort(arr, size, place);
}
void printArray(int array[],int size){
    int i;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int arr[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    printArray(arr,n);
    return 0;
}