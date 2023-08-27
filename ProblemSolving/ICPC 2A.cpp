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

    int arr[n], dep[n];
    set<int> st;
    for(int i=0; i<n; i++){
        cin >> arr[i] >> dep[i];
        st.insert(arr[i]);
        st.insert(dep[i]);
    }

    map<int,int> mp;
    int ind = 0;
    for(auto &x : st) mp[x] = ind++;

    int room = 0, cnt[mp.size() + 2] = {0}, ans[n];
    for(int i=0; i<n; i++){
        cnt[mp[arr[i]]]++;
        cnt[mp[dep[i]]+1]--;
    }

    int cum[mp.size() + 2], mx;
    mx = cum[0] = cnt[0];
    for(int i=1; i<mp.size(); i++){
        cum[i] = cum[i-1] + cnt[i];
        mx = max(mx, cum[i]);
    }

    cout << mx << endl;
    for(int i=0; i<n; i++){
        if(i!=0) cout << ' ';
        cout << cum[mp[arr[i]]];
    } cout << endl;


}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

