#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef pair<intl,intl> pii;
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



int main()
{
    FasterIO

    intl n, k;
    cin>>n>>k;

    intl a[n+5], dp[n+5], dpb[n+5];
    for(int i=1; i<=n; i++) cin>>a[i];

    dp[k] = 0; dp[k+1] = a[k+1];
    for(int i=k+2; i<=n; i++) dp[i] = a[i] + max(dp[i-1], dp[i-2]);

    dpb[1] = 0; dpb[2] = a[1];
    for(int i=3; i<=n; i++) dpb[i] = max(dpb[i-1]+a[i-1], dpb[i-2]+a[i-2]);

    intl res = INT_MIN;
    for(int i=k; i<=n; i++) res = max(res, dp[i]+dpb[i]);

    cout<<res<<endl;

    return 0;
}
