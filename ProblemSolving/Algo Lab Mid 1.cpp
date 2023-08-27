#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int mx = arr[0];
    for(int i=1; i<n; i++){
        if(mx < arr[i]) mx = arr[i];
    }

    cout<<"Maximum element: "<<mx<<endl;
}

int main()
{
    int tc; cin>>tc;
    while(tc--) solve();

    return 0;
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
