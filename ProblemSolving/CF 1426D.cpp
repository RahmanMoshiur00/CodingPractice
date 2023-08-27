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

    set< pair<int,int> > st;
    int arr[n+1], cum[n+1] = {0};
    st.insert(make_pair(0, 0));
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        cum[i] = cum[i-1] + arr[i];
        st.insert(make_pair(cum[i], i));
    }

    int ans = 0, prev = -1;
    for(int i=0; i<=n; i++){
        st.erase(make_pair(cum[i], i));
        auto it = st.lower_bound(make_pair(cum[i], -1));
        if(it != st.end() && cum[i]== it->first){
            if(prev < it->second){
                prev = it->second;
                ans++;
                debug cout << "at: " << i << ' ' << it->second << endl;
            }

        }
    }

    cout << ans << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

