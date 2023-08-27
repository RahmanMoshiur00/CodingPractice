#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main()
{
    ull ans, s, e;
    while(true){
        ans = 0;
        cin>>s>>e;
        if(s==0 && e==0) return 0;
        ans = (e * (e+1)) - (s * (s-1));
        ans /= 2;
        cout<<ans<<endl;
    }
}
