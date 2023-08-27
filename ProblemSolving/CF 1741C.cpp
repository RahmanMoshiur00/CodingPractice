#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int MXN = 262144 + 5;

int arr[MXN], ans = 0;
bool notPossible = false;

pair<int,int> func(int l, int r)
{
    debug cout << l << ' ' << r << endl;
    if(r-l == 1){
        if(arr[l]>arr[r]) ans++;
        if(abs(arr[l]-arr[r]) != 1) notPossible = true;
        return {min(arr[l], arr[r]), max(arr[l], arr[r])};
    }

    int mid = (l+r)/2;
    pair<int,int> lp = func(l, mid);
    pair<int,int> rp = func(mid+1, r);
    int mn = min(lp.first, rp.first), mx = max(lp.second, rp.second);

    if(mx-mn != r-l){
        notPossible = true;
        debug cout << "NotPossible at " << l << ' ' << r << ": " << abs(rp.second-lp.first) << endl;
    }
    if(lp.first > rp.first) ans++;
    return {min(lp.first, rp.first), max(lp.second, rp.second)};
}

void solve(int test_case)
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) cin >> arr[i];

    if(n == 1){
        cout << 0 << endl;
        return;
    }

    notPossible = false;
    ans = 0;

    pair<int,int> p = func(1, n);

    if(notPossible) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

/*
6
8
6 5 7 8 4 3 1 2
4
3 1 4 2
1
1
8
7 8 4 3 1 2 6 5
2
1 2
2
2 1
*/
