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
    int n, d;
    cin >> n >> d;

    pair<int,int> p[n];
    for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;

    sort(p, p+n);

    int ans = p[0].second, lft = 0;
    for(int i=1; i<n; i++){
        if(p[i].first - p[0].first < d){
            ans += p[i].second;
        }
        else{
            int tot = ans;
            for(int j=i; j<n; j++){
                while(p[j].first - p[lft].first >= d ){
                    tot -= p[lft].second;
                    lft++;
                }
                tot += p[j].second;
                ans = max(ans, tot);
            }
            break;
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

