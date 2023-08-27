#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 15, mod = 998244353;

int fact[mxn], cnt[mxn][2];

long long bigmod ( long long a, long long p, long long m ) // finds a^p % m
{
    long long res = 1;
    long long x = a;

    while ( p )
    {
        if ( p & 1 ) //p is odd
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res;
}
long long modinverse(long long a, long long m) // caller function
{
    return bigmod(a, m-2, m);
}

int nCr(int n, int r)
{
    if(n < r) return 0;
    if(n == r) return 1;
    int denominator = (fact[n-r] * fact[r]) % mod;
    return (fact[n] * modinverse(denominator, mod)) % mod;

}

void solve(int test_case)
{
    int n, k, l, r;
    cin >> n >> k;

    fact[0] = 1;
    for(int i=1; i<mxn; i++) fact[i] = (fact[i-1] * i) % mod;

    for(int i=0; i<n; i++){
        cin >> l >> r;
        cnt[l][0]++;
        cnt[r+1][1]++;
    }

    int tot[mxn] = {0}, res = 0;
    for(int i=1; i<mxn; i++){
        tot[i] = tot[i-1] + cnt[i][0] - cnt[i][1];

        debug cout << i << " -> " << cnt[i][0] << ' ' << cnt[i][1] << endl;

        if(cnt[i][0]>0 && tot[i]>=k){
            res += (cnt[i][0] * nCr(tot[i-1]-cnt[i][1], k-1)) % mod;
            if(tot[i]>=k) res += nCr(tot[i], k) % mod;
            debug cout << "at: " << i << " -> " << res << endl;
        }
    }

    res %= mod;

    cout << res << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

