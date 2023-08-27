#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int lo, int hi, int data){
    int mid = (lo+hi) / 2;
    if(lo>hi) return -1;
    if(data == arr[mid]) return mid;
    else if(data > arr[mid]) return binarySearch(arr, mid+1, hi, data);
    else return binarySearch(arr, lo, mid-1, data);
}

int main()
{
    int n;
    cout<<"How many numbers you want to entry?"<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter "<<n<<" numbers:"<<endl;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    cout<<"Enter data which you want to search: ";
    int data;
    cin>>data;
    int ans = binarySearch(arr, 0, n, data);
    if(ans == -1) cout<<data<<" is not found!\n";
    else cout<<data<<" is found at position "<<ans<<endl;

    return 0;
}
