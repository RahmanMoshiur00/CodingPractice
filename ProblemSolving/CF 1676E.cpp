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
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(all(v));
    reverse(all(v));

    vector<int> cum(n);
    cum[0] = v[0];
    for(int i=1; i<n; i++){
        cum[i] = cum[i-1] + v[i];
    }

    int x, ans = 0;
    while(q--){
        cin >> x;
        if(x>cum[n-1]){
            cout << -1 << endl;
            continue;
        }
        ans = lower_bound(cum.begin(), cum.end(), x) - cum.begin();
        ans++;
        cout << ans << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

