#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

struct Pair{
    int ff, ss, ind;
    Pair(int f, int s, int i){
        ff = f;
        ss = s;
        ind = i;
    }

    bool operator < (const Pair& a) const{
        if(ff != a.ff) return ff < a.ff;
        if(ss != a.ss) return ss < a.ss;
        return ind < a.ind;
    }
};

void solve(int tc)
{
    int n;
    cin >> n;

    int x, y;
    vector <Pair> v;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back(Pair(x, 1, i));
        v.push_back(Pair(y+1, -1, i));
    }

    sort(v.begin(), v.end());

    set<int> st;
    for(int i=0; i<n; i++) st.insert(i+1);

    int ans[n];
    for(auto &it : v){
        if(it.ss == 1){
            ans[it.ind] = *st.begin();
            st.erase(st.begin());
        }
        else{
            st.insert(ans[it.ind]);
        }
    }

    int tot = *max_element(ans, ans+n);
    cout << tot << endl;
    for(int i=0; i<n; i++) cout << ans[i] << ' ';
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}
