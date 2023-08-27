#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 5010;

void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int mx = *max_element(arr, arr+n),
        mn = *min_element(arr, arr+n);

    if(mx == mn){
        cout << "NO" << endl;
        return;
    }


    cout << "YES\n";

    int map_id = 0;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        if(mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = map_id;
            map_id++;
        }
    }

    vector<int> adj[mxn];
    for(int i=0; i<n; i++){
        adj[ mp[arr[i]] ].push_back(i+1);
    }


    //root to all other nodes except of the same level
    for(int i=1; i<map_id; i++){
        for(int j=0; j<adj[i].size(); j++) cout << adj[0][0] << ' ' << adj[i][j] << endl;
    }

    //root leveled nodes
    for(int i=1; i<adj[0].size(); i++) cout << adj[1][0] << ' ' << adj[0][i] << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

