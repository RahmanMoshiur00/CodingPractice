#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int tc)
{
    int x, n;
    cin >> x >> n;

    int coins[x];
    for(int i=0; i<x; i++)
        cin >> coins[i];

    sort(coins, coins + x);

    int dp[n+1];
    dp[0] = 1;

    for(int i=0; i<x; i++){
        dp[i] = 0;
        for(int j=1; j<=n; j++){
            if(j - coins[i] >= 0)
        }
    }

    for(int i=1; i<=n; i++){
        dp[i] = 0;
        for(int j=x-1; j>=0; j--){
            if(i - coins[j] >= 0){
                dp[i] += dp[i - coins[j]];
                dp[i] %= mod;
            }
        }
    }

    return dp[n];
}

int32_t main()
{
    cout << solve(1) << endl;
}
