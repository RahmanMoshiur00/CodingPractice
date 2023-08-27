#include<bits/stdc++.h>
using namespace std;
#define intt long long

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    intt t, x, y, GCD, LCM;
    cin>>t;

    while(t--){
        cin>>x>>y;
        if(x==0 && y==0){
            cout<<"0 0"<<endl;
            continue;
        }
        else if(x==1 || y==1 || x==0 || y==0){
            cout<<min(x,y)<<" "<<max(x, y)<<endl;
            continue;
        }

        GCD = LCM = 0;
        if(__gcd(x, y) == 1){
            cout<<"-1"<<endl;
            continue;
        }
        GCD = __gcd(x, y);
        LCM = (x*y)/GCD;
        if(max(x,y)<max(GCD, LCM)) cout<<"-1"<<endl;
        else cout<<min(GCD, LCM)<<" "<<max(GCD, LCM)<<endl;
    }

    return 0;
}
