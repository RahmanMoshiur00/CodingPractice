#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    set< pair<int,int> > st;

    int q, k, p;
    while(true){
        cin >> q;
        if(q == 0) return;
        if(q == 1){
            cin >> k >> p;
            st.insert({p, k});
        }
        else if(q == 2){
            if(st.empty()) cout << 0 << '\n';
            else{
                auto it = st.rbegin();
                cout << it -> second << '\n';
                st.erase(*it);
            }
        }
        else{
            if(st.empty()) cout << 0 << '\n';
            else{
                auto it = st.begin();
                cout << it -> second << '\n';
                st.erase(it);
            }
        }
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


