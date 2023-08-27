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

    int arr[n+1];
    for(int i=1; i<=n; i++) cin >> arr[i];

    for(int i=1; i<=n; i++){
        if(arr[i] == 0){
            cout << i << ' ' << 1 << endl;
            return;
        }
    }

    pair<int,int> p[n+1];
    int cum[n+1];

    cum[0] = 0;
    p[0] = make_pair(0, 0);
    for(int i=1; i<=n; i++){
        cum[i] = cum[i-1] + arr[i];
        p[i] = make_pair(cum[i], i);
    }

    sort(p, p+n+1);

    debug{
        cout << "Pairs:: \n";
        for(int i=0; i<=n; i++){
            cout << p[i].first << ' ' << p[i].second << endl;
        } cout << "End of pairs!" << endl;
    }

    int start = -1, sz = LLONG_MAX;
    for(int i=0; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(p[i].first == p[j].first){
                if(p[j].second - p[i].second < sz){
                    sz = p[j].second - p[i].second;
                    start = p[i].second + 1;
                }
            }
            else break;
        }
    }

    if(start != -1) cout << start << ' ' << sz << endl;
    else cout << start << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

