#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define sf            scanf
#define pf            printf
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000LL //1e9
#define mod           1000000007LL
#define MX            1000005      //1e6

typedef pair<intl, intl> pii;

bool cmp(pii a, pii b){
    if(a.ss>b.ss) return true;
    else if(a.ss==b.ss){
        if(a.ff<b.ff) return true;
        else return false;
    }
    else return false;
}


int main()
{
    intl n, a, b; cin>>n;
    vector< pii > t(n);
    for(int i=0; i<n; i++){
        cin>>t[i].ff;
        cin>>a>>b;
        t[i].ss = a+b;
    }

    sort(t.begin(), t.end(), cmp);

    intl dp = 0 , ans = INT_MIN;
    for(int i=0; i<n; i++){
        dp += t[i].ff;
        ans = max(ans , dp+t[i].ss);
    }

    cout<<ans;

    return 0;
}
