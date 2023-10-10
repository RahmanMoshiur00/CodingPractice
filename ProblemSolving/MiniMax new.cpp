#include <bits/stdc++.h>
using namespace std;

int Minimax(int depth, int idx, bool isMax, int arr[], int h)
{
    if(depth == h){
        return arr[idx];
    }

    if(isMax){
        return max( Minimax(depth+1, idx*2, false, arr, h), Minimax(depth+1, idx*2 + 1, false, arr, h) );
    }
    else{
        return min( Minimax(depth+1, idx*2, true, arr, h), Minimax(depth+1, idx*2 + 1, true, arr, h));
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int h = 0;
    while(n>1){
        n /= 2;
        h++;
    }

    cout << "The optimal result: " << Minimax(0, 0, false, arr, h) << endl;
}

/*
8
3 5 2 9 12 5 23 23
*/
