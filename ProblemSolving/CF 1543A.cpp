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
    int a, b;
    cin >> a >> b;

    if(a==b){
        cout << "0 0" << endl;
        return;
    }

    if(a>b) swap(a, b);

    int d = b-a;

    int lq = a / d;
    int lb = lq * d;
    int ub = (lq+1) * d;

    cout << d << ' ' << min(a-lb, ub-a) << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

