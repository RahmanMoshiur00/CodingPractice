#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll counter = 0;

void merge(int arr[], int lo, int hi)
{
    int mid = (lo+hi)/2, n = hi-lo+1;
    int store[n], j = lo, k = mid+1;

    for(int i=0; i<n; i++){
        if(j>mid) store[i] = arr[k++];
        else if(k>hi) store[i] = arr[j++];
        else if(arr[j]>arr[k]) store[i] = arr[k++];
        else store[i] = arr[j++];
    }

    for(int i=0; i<n; i++) arr[lo+i] = store[i];
}

void merge_sort(int arr[], int lo, int hi)
{
    if(lo>=hi) return;
    int mid = (lo+hi)/2;

    merge_sort(arr, lo, mid);
    merge_sort(arr, mid+1, hi);

    merge(arr, lo, hi);
}

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    merge_sort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
}
