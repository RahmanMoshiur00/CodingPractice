#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solve(int tc)
{
    int x, n;
    scanf("%d %d", &x, &n);

    int coins[x];
    for(int i=0; i<x; i++)
        scanf("%d", &coins[i]);

    sort(coins, coins + x);
    int dp[n+1];
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        dp[i] = 0;
        for(int j=0; j<x && coins[j]<=i; j++){
            dp[i] += dp[i - coins[j]];
            dp[i] %= mod;
        }
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    printf("%d\n", solve(1));
}
