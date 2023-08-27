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
    string s;
    cin >> s;

    int fi = 0, se = 0;
    for(int i=0; i<s.size(); i++){
        if(i<3) fi += s[i] - '0';
        else se += s[i] - '0';
    }

    if(fi == se) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

