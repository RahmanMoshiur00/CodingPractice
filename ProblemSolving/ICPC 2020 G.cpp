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
    int tc = 1, n;
    double xx, yy, sx = 0, sy = 0, sxs = 0, sxy = 0, x, y, a1;
    while(cin >> n && n){
        sx = 0, sy = 0, sxs = 0, sxy = 0;
        for(int i=0; i<n; i++){
            cin >> xx >> yy;
            sx += xx;
            sy += yy;
            sxs += xx * xx;
            sxy = xx * yy;
        }
        a1 = ((n*sxy) - (sx*sy)) / ((n*sxs) - (sx*sx));
        x = ((a1*sxs) - (sxy)) / ((a1*sx) - sy);
        y = (a1*sx) + (a1*x) - sy;

        cout << "Case " << tc++ << ": " << x << " " << y << endl;
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

