#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

int find_distance(int x, int y, int m, int n)
{
    return abs(x-m) + abs(y-n);
}

void solve(int test_case)
{
    int x, y, m, n, d;
    cin >> x >> y >> m >> n >> d;

    if(find_distance(x, y, m, n) <= d){
        cout << -1 << endl;
        return;
    }

    if((m-1>d && y-n>d) or (n-1>d && x-m>d)){
        cout << x-1+y-1 << endl;
    }
    else{
        cout << -1 << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

