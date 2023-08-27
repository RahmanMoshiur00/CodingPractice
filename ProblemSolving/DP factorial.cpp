#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define MAX 100

i64 dp[MAX];

int main()
{
    dp[0] = 1;

    for(int i=1; i<MAX; i++) dp[i] = i * dp[i-1];

    int n; cin>>n;
    while(n--){
        int q; cin>>q;
        cout<<dp[q]<<endl;
    }

    return 0;

}
