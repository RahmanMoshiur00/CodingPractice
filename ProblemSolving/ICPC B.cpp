#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 200010;
int n, p, arr[mxn];

bool ok(int x)
{
    int tot = 0, res;
    for(int i=0; i<n; i++){
        tot += x/arr[i];
        if(tot >= p) return true;
    }
    return false;
}

void solve(int test_case)
{
    cin >> n >> p;

    for(int i=0; i<n; i++) cin >> arr[i];

    int lo = 0, hi = 2e18, mid;
    while(hi-lo>1){
        mid = (lo+hi) / 2;

        debug cout << "Check: " << lo <<' ' << mid << " " << hi << endl;

        if(ok(mid)) hi = mid;
        else lo = mid;
    }

    for(int i=lo; i<=hi; i++){
        if(ok(i)){
            cout << i << endl;
            return;
        }
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

