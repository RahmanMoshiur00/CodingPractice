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
    int x, y, n;
    cin >> x >> y >> n;

    int cnt = 0;
    while(x%2==0 & x>0) x /= 2, cnt++;
    while(y%2==0 & y>0) y /= 2, cnt++;

    int tot = 1;
    for(int i=0; i<cnt; i++) tot *= 2;

    if(tot >= n) cout << "yes" << endl;
    else cout << "no" << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

