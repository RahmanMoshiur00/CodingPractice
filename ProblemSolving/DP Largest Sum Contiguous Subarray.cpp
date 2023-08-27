#include<bits/stdc++.h>
using namespace std;
#define i64 long long

i64 longestSumSubarray(vector<int>& arr){
    int n = arr.size();
    i64 max_current = arr[0];
    i64 max_till_now = arr[0];

    for(int i=1; i<n; i++){
        max_current = max((i64)arr[i], arr[i] + max_current);
        max_till_now = max(max_till_now, max_current);
    }

    return max_till_now;
}

int main()
{
    cout<<"Enter how the number of element in the array: ";
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<longestSumSubarray(arr)<<endl;

    return 0;
}
