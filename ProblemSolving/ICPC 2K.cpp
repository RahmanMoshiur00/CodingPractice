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
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    int cum[n] = {0}, tot = 0;
    tot = cum[0] = arr[0];
    for(int i=1; i<n; i++){
        cum[i] = cum[i-1] + arr[i];
        tot += arr[i];
    }

    int ans = LLONG_MAX, left = 0, right = 0;
    for(int i=0; i<n; i++){
        left = cum[i];
        right = tot - cum[i];
        debug cout << left << ", " << right << endl;
        ans = min(ans, max(left, right));
    }

    cout << 2*ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

