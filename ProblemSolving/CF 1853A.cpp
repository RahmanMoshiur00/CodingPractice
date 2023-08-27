#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 100010;


void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int minDiff = INT_MAX;
    for(int i=1; i<n; i++){
        minDiff = min(minDiff, arr[i] - arr[i-1]);
    }

    int ans = 0;
    if(minDiff < 0)
        ans = 0;
    else if(minDiff == 0)
        ans = 1;
    else{
        ans = minDiff / 2;
        ans++;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}
