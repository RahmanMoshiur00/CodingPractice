#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 100010;



void solve(int test_case)
{
    int l, r, a;
    cin >> l >> r >> a;

//    debug{
//        cout << "For: " << l << ' ' << r << ' ' << ' ' << a << endl;
//        int mx = 0, v;
//        for(int i=l; i<=r; i++){
//            v = (i/a) + (i%a);
//            if(v>mx){
//                mx = v;
//                cout<<"New max: "<<mx << "   At: " << i << endl;
//            }
//        }
//        cout << "\n\n";
//    }

    int q = r / a;
    int v = (q*a) - 1;
    int ans = 0;
    //cout << "v = " << v << endl;

    if(v>=l){
        ans = max(ans, (v/a) + (v%a));
    }

    ans = max(ans, (r/a) + (r%a));

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

