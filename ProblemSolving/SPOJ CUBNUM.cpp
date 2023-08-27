#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
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
#define INF           1000000000
#define mod           1000000007
#define mxn           100010
#define cube(x)       ((x)*(x)*(x))

int dp[mxn];

void solve(){
    vector<int> cb;
    for(int i=1; cube(i)<mxn; i++) cb.pb(cube(i));
    int n = cb.size();

    dp[0] = 0;
    for(int i=1; i<mxn; i++){
        dp[i] = INT_MAX;
        for(int j=0; j<n; j++){
            if(i>=cb[j]) dp[i] = min(dp[i], 1+dp[i-cb[j]]);
            else break;
        }
    }
}

int main()
{
    solve();

    int t = 0, n;
    while(scanf("%d", &n) != EOF){
        printf("Case #%d: %d\n", ++t, dp[n]);
    }

    return 0;
}

