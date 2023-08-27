#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 1010;
const int mod = 1e9 + 7;

int facto[mxn];

void initializer()
{
    facto[0] = facto[1] = 1;
    for(int i=2; i<mxn; i++){
        facto[i] = (facto[i-1] * i) % mod;
    }
}

int bigMod(int b, int p, int mod)
{
    if(p == 0) return 1;

    if(p & 1){
        return (b*bigMod(b, p-1, mod)) % mod;
    }
    else{
        int r = bigMod(b, p/2, mod);
        return (r*r) % mod;
    }
}

int nCr(int n, int r)
{
    int down = (facto[n-r] * facto[r]) % mod;

    down = bigMod(down, mod-2, mod);

    return (facto[n] * down) % mod;
}

void solve(int test_case)
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    int in = 0, out = 0;
    for(int i=n-k; i<n; i++){
        if(arr[i] == arr[n-k]) in++;
    }
    for(int i=n-k-1; i>=0; i--){
        if(arr[i] == arr[n-k]) out++;
    }

    cout << nCr(in+out, in) << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    initializer();
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

