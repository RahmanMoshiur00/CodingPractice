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
    int a, b, c, d, aa, bb, cc;
    cin >> a >> b >> c;

    d = b - c;
    aa = b + d;
    if(aa%a==0 && aa/a>0){
        cout << "YES" << endl;
        return;
    }

    d = a - c;
    if(d%2==0){
        d /= 2;
        bb = c + d;
        if(bb%b==0 && bb/b>0){
            cout << "YES" << endl;
            return;
        }
    }

    d = a - b;
    cc = b - d;
    if(cc%c==0 && cc/c>0){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

