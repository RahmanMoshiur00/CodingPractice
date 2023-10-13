#include <bits/stdc++.h>
using namespace std;

int solve(int tc)
{
    int x, n;
    cin >> x >> n;

    int coins[x];
    for(int i=0; i<x; i++){
        cin >> coins[i];
    }
    sort(coins, coins + x);

    int dp[n+1];
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
        for(int j=0; j<x && coins[j]<=i; j++){
            if(dp[i - coins[j]] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }

    if(dp[n] == INT_MAX) return -1;
    else return dp[n];
}
int32_t main()
{
    cout << solve(1) << endl;
}
