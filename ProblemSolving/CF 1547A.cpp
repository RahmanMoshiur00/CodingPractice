
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
    int a, b, x, y, m, n, ans = 0;
    cin >> a >> b >> x >> y >> m >> n;
    if(a==x && a==m){
        if((b<n && n<y) || (b>n && n>y)) ans += 2;
    }
    else if(b==y && b==n){
        if((a<m && m<x) || (a>m && m>x)) ans += 2;
    }
    ans += abs(a-x) + abs(b-y);
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
