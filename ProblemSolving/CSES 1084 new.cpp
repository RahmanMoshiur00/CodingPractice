#include <bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> st;
    int desire[n], available[m];
    for(int i=0; i<n; i++){
        cin >> desire[i];
    }
    for(int i=0; i<m; i++){
        cin >> available[i];
        st.insert(available[i]);
    }

    //sort(desire, desire+n);

    int ans = 0;
    for(int i=0; i<n; i++){
        if(st.empty()) break;
        auto it = st.lower_bound(desire[i]-k);
        if(it!=st.end() && (*it>=desire[i]-k && *it<=desire[i]+k)){
            ans++;
            st.erase(it);
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

