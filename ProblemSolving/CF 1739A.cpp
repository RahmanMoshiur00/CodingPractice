#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;
int n, m;

bool inv(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m) return true;
    return false;
}

void solve(int test_case)
{
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(inv(i-1, j+2) && inv(i-1, j-2) && inv(i-2, j+1) && inv(i-2, j-1) && inv(i+1, j-2) && inv(i+1, j+2) && inv(i+2, j-1) && inv(i+2, j+1)){
                cout << i+1 << ' ' << j+1 << endl;
                return;
            }
        }
    }

    cout << n << ' ' << m << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

