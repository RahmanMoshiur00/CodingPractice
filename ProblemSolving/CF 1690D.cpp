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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt[n+1];
    cnt[0] = 0;
    for(int i=1; i<=n; i++){
        if(s[i-1]=='B') cnt[i] = cnt[i-1] + 1;
        else cnt[i] = cnt[i-1];
    }

    int v, ans = INT_MAX;
    for(int i=1; i+k-1<=n; i++){
        v = cnt[i+k-1] - cnt[i-1];
        debug cout << "Check at " << i << " : " << v << endl;
        v = k - v;
        ans = min(ans, v);
    }

    cout << ans << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

