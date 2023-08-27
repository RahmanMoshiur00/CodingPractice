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
    int r, c, x;
    cin >> r >> c >> x;

    int r1, c1;

    r1 = x % r;
    if(r1 == 0) r1 = r;

    c1 = x / r;
    if(x%r != 0) c1++;

    //cout << r1 << " - " << c1 << endl;

    int tot = ((r1-1)*c) + c1;
    cout << tot << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

