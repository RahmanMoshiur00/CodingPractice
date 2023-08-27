#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n];
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    int zeros = 0, multiple = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0) zeros++;
        if(mp[arr[i]] > 1) multiple = 1;
    }

    if(zeros > 0){
        cout << n - zeros << endl;
    }
    else if(multiple == 1){
        cout << n << endl;
    }
    else{
        cout << n + 1 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

