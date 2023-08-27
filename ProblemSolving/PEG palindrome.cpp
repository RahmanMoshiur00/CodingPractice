#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define MX  5005

char str[MX], rstr[MX];
int dp[MX][MX];
int n;

int LCS(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(str[i-1] == rstr[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main()
{

    cin>>n; cin>>str;

    for(int i=n-1; i>=0; i--) rstr[i] = str[n-i-1];
    rstr[n] = '\0';
    cout<<n - LCS()<<endl;

    return 0;
}


