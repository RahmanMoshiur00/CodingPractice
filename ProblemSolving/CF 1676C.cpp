#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

int cal(string s, string t)
{
    int ret = 0;
    for(int i=0; i<s.size(); i++){
        ret += abs(s[i]-t[i]);
    }
    return ret;
}

void solve(int test_case)
{
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i=0; i<n; i++) cin >> s[i];

    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans = min(ans, cal(s[i], s[j]));
        }
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

