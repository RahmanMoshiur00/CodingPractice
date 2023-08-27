#include<bits/stdc++.h>
using namespace std;

#define maxn    101

int f(string& str1, int i, string& str2, int j, int dp[maxn][maxn])
{
    if(i==str1.size()) return (str2.size() - j);
    if(j==str2.size()) return (str1.size() - i);

    if(dp[i][j] != -1) return dp[i][j];

    int res;
    if(str1[i] == str2[j]) res = f(str1, i+1, str2, j+1, dp);
    else res = 1 + min(min(f(str1, i, str2, j+1, dp), f(str1, i+1, str2, j, dp)), f(str1, i+1, str2, j+1, dp));

    dp[i][j] = res;
    return dp[i][j];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int dp[maxn][maxn];
    memset(dp, 0xff, sizeof(dp));

    cout << f(str1, 0, str2, 0, dp) << endl;


    dp[0][0] = 0;
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
    }

    cout << dp[str1.size()][str2.size()] << endl;

    return 0;
}
