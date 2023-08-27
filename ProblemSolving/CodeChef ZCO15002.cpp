#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, counter = 0;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);
    for(int i=0, j=1; i<n && j<n; ){
        if(arr[j]-arr[i]>=k){
            counter += n-j;
            i++;
        }
        else j++;
    }
    cout<<counter<<endl;

    return 0;
}
