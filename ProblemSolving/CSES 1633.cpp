#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solve(int n)
{
    int dp[n+1];
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++){
        dp[i] = 0;
        for(int j=1; j<=i && j<=6; j++){
            dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
}
