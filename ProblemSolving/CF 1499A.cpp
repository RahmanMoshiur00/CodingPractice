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
    int n, wh1, wh2, w, b;
    cin >> n >> wh1 >> wh2;
    cin >> w >> b;

    int white = 0, black = 0;

    white = min(wh1, wh2);
    black = min(n-wh1, n-wh2);

    white += abs(wh1 - wh2) / 2;
    black += abs(wh1 - wh2) / 2;

    if(white>=w && black>=b) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

