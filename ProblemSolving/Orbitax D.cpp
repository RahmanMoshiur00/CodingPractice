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
    int n;
    cin >> n;

    int arr[n];
    set< pair<int, int> > st;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        st.insert(make_pair(i, arr[i]));
    }

    pair<int, int> p = *st.begin(), q;
    st.erase(st.begin());

    int fi = p.second, last = p.second, ans = 0, tot;
    while(!st.empty()){
        p = *st.begin();
        st.erase(st.begin());
        if(p.second >= last){
            last = p.second;
        }
        else{
            tot = p.second;
            while(!st.empty()){
                q = *st.begin();
                st.erase(st.begin());
                tot += q.second;
                ans++;
                if(tot >= last){
                    last = tot;
                    break;
                }
            }
            if(tot < last){
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

/*
5
10 5 15 5 10
*/
