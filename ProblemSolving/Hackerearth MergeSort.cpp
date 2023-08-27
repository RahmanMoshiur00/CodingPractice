#include<bits/stdc++.h>
using namespace std;

long long counter = 0 , k;
void merge_sort(int arr[], int lo, int hi)
{
	if(lo==hi) return;
	int mid = (lo+hi) / 2;

	merge_sort(arr, lo, mid);
	merge_sort(arr, mid+1, hi);

	int first = lo, second = mid+1;
	int temp[hi-lo+1];

	for(int i=0; i<=hi-lo; i++){
		if(first == mid+1) temp[i] = arr[second++];
		else if(second == hi+1) temp[i] = arr[first++];
		else if(arr[first]<=arr[second]){
            if(arr[second]-arr[first]<=k) counter += mid - second + 1;
            temp[i] = arr[first++];
		}
		else if(arr[first]>arr[second]){
			if(arr[first]-arr[second]<=k) counter += mid - first + 1;
			temp[i] = arr[second++];
		}
	}

	for(int i=lo, j=0; i<=hi; i++, j++) arr[i] = temp[j];
}

int main()
{
	int n, ans;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	merge_sort(arr, 0, n-1);
	cout<<n-counter<<endl;
	return 0;
}
