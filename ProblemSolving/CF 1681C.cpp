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

    int a[n], b[n];
    pair<int,pair<int,int>> p[n];

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    for(int i=0; i<n; i++) p[i] = make_pair(a[i], make_pair(b[i], i));

    sort(p, p+n);

    for(int i=1; i<n; i++){
        if(p[i-1].second.first > p[i].second.first){
            cout << -1 << endl;
            return;
        }
    }

    int idx[n], v[n];
    for(int i=0; i<n; i++) idx[i] = p[i].second.second, v[i] = i;

    vector<pair<int,int>> ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(idx[i]==v[j]){
                swap(v[i], v[j]);
                if(i!=j) ans.push_back({i+1, j+1});
                break;
            }
        }
    }

    cout<< ans.size() << endl;
    for(int i=0; i<ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

