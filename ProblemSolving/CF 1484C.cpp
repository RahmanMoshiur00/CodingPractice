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
    int n, m, k, x;
    cin >> n >> m;

    vector<pair<int,int>> f[n+5];
    int cnt[n+1] = {0};

    for(int i=1; i<=m; i++){
        cin >> k;
        for(int j=1; j<=k; j++){
            cin >> x;
            cnt[x]++;
            f[x].push_back(make_pair(k, i));
        }
    }

    for(int i=1; i<=n; i++){
        sort(all(f[i]));
    }

    pair<int, int> p[n+1];
    for(int i=1; i<=n; i++){
        p[i] = make_pair(cnt[i], i);
    }

    sort(p+1, p+n+1);

    int ans[m+1], mx;
    MINUS(ans);

    for(int i=n; i>=1; i--){
        mx = m / 2;
        if(m % 2 != 0) mx++;
        for(auto &v : f[p[i].second]){
            if(ans[v.second] == -1 && mx>0){
                ans[v.second] = p[i].second;
                mx--;
            }
        }
    }

    for(int i=1; i<=m; i++){
        if(ans[i] == -1){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for(int i=1; i<=m; i++) cout << ans[i] << ' ';
    cout << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

