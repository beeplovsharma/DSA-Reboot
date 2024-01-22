#include <bits/stdc++.h>
using namespace std;

int fun(int arr[],int low,int high){
    int i = low;
    int j = high;
    int pivot = arr[low];

    while(i<j){
        while (arr[i] <= pivot && i <= high-1)
        {
            i++;
        }
        while (arr[j] >= pivot && j >= low+1)
        {
            j--;
        }

        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qs(int arr[], int low, int high)
{
    if(low<high)
    {
        int partition = fun(arr, low, high);
        qs(arr, low, partition - 1);
        qs(arr, partition + 1, high);
    }
}

int main()
{
    int arr[] = {4,6,2,5,7,9,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    qs(arr, 0, n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}