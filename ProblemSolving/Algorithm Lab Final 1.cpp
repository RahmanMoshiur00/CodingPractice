#include<bits/stdc++.h>
using namespace std;

void Count_Sort(int arr[], int n, int exp)
{
	int output[n];
	int cnt[10] = {0};

	for(int i = 0; i < n; i++)
		cnt[ (arr[i]/exp)%10 ]++;

	for(int i = 1; i < 10; i++)
		cnt[i] += cnt[i - 1];

	for(int i = n-1; i >= 0; i--){
		output[ cnt[ (arr[i]/exp)%10 ] - 1 ] = arr[i];
		cnt[ (arr[i]/exp)%10 ]--;
	}

	for(int i = 0; i < n; i++)
		arr[i] = output[i];
}

void Radix_Sort(int arr[], int n, int maxx)
{
	for(int exp = 1; maxx/exp > 0; exp *= 10)
		Count_Sort(arr, n, exp);
}

int main()
{
    int n;
    cout << "Enter total number of elements present in the array: ";
    cin >> n;

    int arr[n], maxx;

    cout << "Enter " << n << " array elements:\n";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    maxx = arr[0];
    for(int i=1; i<n; i++)
        maxx = max(maxx, arr[i]);

    Radix_Sort(arr, n, maxx);

    cout << "Array after sorting:";
    for(int i=0; i<n; i++) cout << " "<< arr[i];
    cout << endl;

    return 0;
}

/*
10
5 8 3 2 9 1 4 10 7 6
*/
