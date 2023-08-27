#include <bits/stdc++.h>
using namespace std;

#define int long long
#define debug if(0)

int fact[200005];
int mod = 998244353;

int bigMod(int b, int p, int mod)
{
    if(p == 0) return (1%mod);

    int tmp;
    if(p%2==0){
        tmp = bigMod(b, p/2, mod);
        return (tmp * tmp) % mod;
    }
    else{
        tmp = bigMod(b, p-1, mod);
        return (tmp * b) % mod;
    }
}

void solve(int tc)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    if(arr[n-1]>arr[n-2]+1){
        cout << 0 << endl;
        return;
    }
    if(arr[n-1]==arr[n-2]){
        cout << fact[n] << endl;
        return;
    }

    int x = 0;
    for(int i=0; i<n; i++){
        if(arr[i]<arr[n-1]-1) x++;
        else break;
    }

    int y = 0;
    for(int i=n-1; i>=0; i--){
        if(arr[i] == arr[n-1]) y++;
        else break;
    }

    int tmp = (fact[n] * fact[n-x-1]) % mod;
    tmp = (tmp * bigMod(fact[n-x], mod-2, mod)) % mod;

    int ans = (fact[n] - tmp) % mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}

int32_t main()
{
    fact[0] = fact[1] = 1;
    for(int i=2; i<200005; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }

    int tc;
    cin >> tc;
    for(int i=1; i<=tc; i++) solve(i);
}
