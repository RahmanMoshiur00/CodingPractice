#include<bits/stdc++.h>
using namespace std;
int heapsize = 0;//heapsize is needed for sorting and emitting the sorted data from the 'arr' array

void Heapify(vector<int>& arr, int i){
    int target = i;

    if((2*i)<=heapsize && arr[target]<arr[2*i]) target = 2*i;
    if((2*i)+1<=heapsize && arr[target]<arr[(2*i)+1]) target = (2*i) + 1;

    if(target != i){
        swap(arr[target], arr[i]);
        Heapify(arr, target);
    }
}


void HeapSort(vector<int>& arr){
    heapsize = arr.size()-1;

    for(int i=arr.size()/2; i>=1; i--) Heapify(arr, i);

    for(int i=arr.size()-1; i>=2; i--){
        swap(arr[i], arr[1]);
        heapsize--;
        Heapify(arr, 1);
    }
}


int main()
{
    cout<<"Enter how many entries you want to enter: ";
    int n;
    cin>>n;
    vector<int> arr(n+1); //we will start storing data from index 1, because 2i and 2i+1 are child of i

    for(int i=1; i<arr.size(); i++) cin>>arr[i];

    HeapSort(arr);

    cout<<"Sorted Array: ";
    for(int i=1; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
