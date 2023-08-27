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
    int n, m, x1, y1, x2, y2;
    cin >> n >> m;

    bool yes = false;
    for(int i=0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(y1 == x2) yes = true;
    }

    if(m%2==1) cout << "NO\n";
    else if(yes) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

