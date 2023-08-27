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
    int m, p;
    cin >> m >> p;
    if(p < m) swap(p, m);

    int ans = 0, x;
    while(p-m >= 3){
        x = (p-m) / 3;
        if(m-x < 0) break;
        p = p - (x*3);
        m = m - x;
        ans += x;
    }

    if(p-m == 2 && m>0){
        ans++;
        p -= 3;
        m -= 1;
    }

    ans += m / 2;

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

