// Moshiur

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
    int mx, mn, n;
    cin >> n;

    if(n%2==1 || n==2){
        cout << -1 << endl;
        return;
    }

    int m = n/2;

    if(m%2==0){
        mx = m/2;
        if(m%3 == 0) mn = m/3;
        else mn = (m/3) + 1;
    }
    else{
        mx = 1 + (m-3)/2;
        if(m%3 == 0) mn = m/3;
        else mn = (m/3) + 1;
    }

    cout << mn << ' ' << mx << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

