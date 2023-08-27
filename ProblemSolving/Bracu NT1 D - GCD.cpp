#include<bits/stdc++.h>
using namespace std;
#define intt long long

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n, ans = 0;
    while(cin>>n && n){
        ans = 0;
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++) ans += __gcd(i,j);
        cout<<ans<<endl;
    }

    return 0;
}

