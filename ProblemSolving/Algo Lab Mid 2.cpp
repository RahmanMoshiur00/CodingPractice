#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[], int l, int r)
{
    int pivot = arr[(l+r)/2];

    while(l <= r){
        while(arr[l] < pivot) l++;
        while(arr[r] > pivot) r--;

        if(l <= r){
            swap(arr[l], arr[r]);
            l++, r--;
        }
    }

    return l;
}

void QuickSort(int arr[], int l, int r)
{
    int idx = Partition(arr, l, r);

    if(l < idx-1) QuickSort(arr, l, idx-1);
    if(r > idx) QuickSort(arr, idx, r);
}

void solve()
{
    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<"Before sorting:";
    for(int i=0; i<n; i++) cout<<" "<<arr[i];
    cout<<endl;

    QuickSort(arr, 0, n-1);

    cout<<"After sorting:";
    for(int i=0; i<n; i++) cout<<" "<<arr[i];
    cout<<endl;
}

int main()
{
    int tc; cin>>tc;
    while(tc--) solve();
}


/*
10

1
3
1
-9

2
-1 7
2
6 3
2
5 5

3
1 2 3
3
3 2 1
3
7 7 7

5
6 3 8 2 9

10
0 3 -2 8 3 1 9 4 2 10
*/
