#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

int weight[105], value[105], dp[205][100005];

void solve(int test_case)
{
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) cin >> weight[i] >> value[i];

    ZERO(dp);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(j-weight[i]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);
        }
    }

    cout << "Case " << test_case << ": " << dp[n][k] << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

