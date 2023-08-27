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
    int n, m, sr, sc, dr, dc;
    cin >> n >> m >> sr >> sc >> dr >> dc;

    int ans = 0;
    if(sc==dc){
        ans = 0;
    }
    else if(sc < dc){
        ans = dc - sc;
        if(dr>=sr) ans = min(ans, dr-sr);
    }
    else{// sc > dc
        ans = 2*(m-sc) + (sc - dc);
        if(dr>=sr) ans = min(ans, dr-sr);
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

