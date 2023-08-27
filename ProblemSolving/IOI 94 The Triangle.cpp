#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; scanf("%d", &n);
    int arr[n][n], dp[2][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++) scanf("%d", &arr[i][j]);
    }

    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++){
        dp[i%2][0] = dp[(i-1)%2][0] + arr[i][0];
        dp[i%2][i] = dp[(i-1)%2][i-1] + arr[i][i];
        for(int j=1; j<i; j++) dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-1]) + arr[i][j];
    }

    int ans = dp[(n-1)%2][0];
    for(int j=1; j<n; j++) ans = max(ans, dp[(n-1)%2][j]);

    printf("%d\n", ans);

    return 0;
}
