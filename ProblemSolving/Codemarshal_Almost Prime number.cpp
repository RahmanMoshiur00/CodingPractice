#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;
#define sf            scanf
#define pf            printf
#define intl          long long
#define intu          unsigned long long
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define fill(a,v)     memset((a), v, sizeof(a))
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000LL //10^9
#define mod           1000000007LL //10^9 + 7
#define MX            1000005      //10^6+5

typedef pair<intl,intl> pii;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/*===================================================================================================*/

bool checker[MX];
vector<intl> store;

void sieve(intl mx){
    intl sq = sqrt(mx)+2;

    intl t = 2;
    while(2*t<=1e12) t = 2*t, store.pb(t);

    for(intl i=3; i<=mx; i+=2){
        if(!checker[i]){
            t = i;
            while(i*t<=1e12) t = i*t, store.pb(t);
            if(i<=sq){
                for(intl j=i*i; j<=mx; j+=i*2) checker[j] = true;
            }
        }
    }
}

int main()
{
    FasterIO

    sieve(MX);
    sort(all(store));
    intl sz = store.size();

    intl n , l , h;
    cin>>n;
    while(n--){
        cin>>l>>h;
        intl hi = upper_bound(all(store), h) - store.begin();
        intl li = lower_bound(all(store), l) - store.begin();
        cout<<hi-li<<endl;
    }

    return 0;
}


