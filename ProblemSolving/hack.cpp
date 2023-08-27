#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define ERROR 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define INF 10000007
#define LLINF 100000000000000007

#define F first
#define S second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end()

typedef long long  ll;

int main()
{

    ll n,x,i,j;
    cin>>n;

    vector<ll>even,odd;
    for(i=0; i<n ; i++){
        cin>>x;
        if( x%2==0 ) even.pb(x);
        else odd.pb(x);
    }

    sort(all(even),greater<ll>());
    sort(all(odd),greater<ll>());

    if( fabs(even.size() - odd.size()) <= 1 ){
        cout<<0<<endl;
        return 0;
    }

    ll res = 0 , ans = 0;
    if( odd.size() > even.size() ){
        for(i=even.size()+1; i<odd.size(); i++)
            res += odd[i];
        cout<<res<<endl;
        return 0;
    }

    else{
        for( i= odd.size()+1; i<even.size(); i++)
            ans += even[i];
        cout<<ans<<endl;
        return 0;
    }

    return 0;
}
