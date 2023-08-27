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
    int n; cin >> n;
    int a[n], b[n];

    set< pair<int,int> > st;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        cin >> b[i];
        st.insert(make_pair(b[i], i));
    }

    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        auto it = st.lower_bound(make_pair(a[i], 0));
        ans = min(ans, i + it->second);
    }
    cout << ans << endl;


//    if(a[0]<b[0]){
//        cout << 0 << endl;
//        return;
//    }


//    int ans1 = INT_MAX, ans2 = INT_MAX;
//    for(int i=0; i<n; i++){
//        if(a[i]<b[i]){
//            ans1 = i + 1;
//            break;
//        }
//    }
//
//    for(int i=0; i<n; i++){
//        if(a[i]<b[i]){
//            ans2 = i + 1;
//            break;
//        }
//    }
//
//    cout << min(ans1, ans2) << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

