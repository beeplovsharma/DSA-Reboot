#include<bits/stdc++.h>
using namespace std;

// Using double pointer
void fun(int arr[],int n,int left,int right){
    if(left>=right) return;

    swap(arr[left],arr[right]);
    fun(arr,n,left+1,right-1);
}

// Using Single Pointer
void fun2(int arr[],int n,int i){
    if(i>=n/2) return;

    swap(arr[i],arr[n-i-1]);
    fun2(arr,n,i+1);
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // fun(arr,12,0,11);
    fun2(arr,12,0);
    for(int i=0;i<12;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}