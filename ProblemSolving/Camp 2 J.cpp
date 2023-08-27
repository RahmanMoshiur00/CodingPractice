#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define all(a)        a.begin(), a.end()
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 1010;

int n, s[mxn], v[mxn];

bool f(double c, double t)
{
    double tot = 0;
    for(int i=0; i<n; i++){
        tot += (double)s[i] / (v[i] + c);
    }
    return tot >= t;
}

void solve(int test_case)
{
    double t;
    cin >> n >> t;

    for(int i=0; i<n; i++) cin >> s[i] >> v[i];

    int mn = *min_element(v, v+n);

    double lo = -mn, hi = 1e15, mid, r;
    for(int i=0; i<300; i++){
        mid = (lo + hi) / 2;
        if(f(mid, t)) lo = mid;
        else hi = mid;
    }

    cout <<  setprecision(12) << mid << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

