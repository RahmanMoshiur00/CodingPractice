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
    int p[n];
    for(int i=0; i<n; i++) cin >> p[i];

    int cum = p[0], x, l, ans = 0;
    for(int i=1; i<n; i++){
        if(p[i]*100 > cum*k){
            l = (p[i]*100) - (cum*k);
            x = l / k;
            if(l%k != 0) x++;
            cum += x;
            ans += x;
        }
        cum += p[i];
    }

    cout << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

