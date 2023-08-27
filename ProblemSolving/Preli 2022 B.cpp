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
    int a, b, c, k, v;
    cin >> a >> b >> c >> k;

    int n = a+b+c;
    int ra = a%k, rb = b%k, rc = c%k;

    set<int> st;
    st.insert(ra);
    st.insert(rb);
    st.insert(rc);

    cout << "Case "<< test_case<<": ";
    if(st.size() > 1){
        cout << "Fight" << endl;
    }
    else{
        v = (a/k) + (b/k) + (c/k);
        if(v%3==0) cout << "Peaceful" << endl;
        else cout << "Fight" << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

