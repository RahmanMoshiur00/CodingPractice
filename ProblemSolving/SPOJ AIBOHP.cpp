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
#define MX            6105

string str, rstr;
int dp[MX][MX];

/*
int T(int s, int e){
    //if(s>e) return INT_MAX; this gets WA
    if(s>=e) return 0;
    if(dp[s][e] == -1){
        if(str[s]==str[e]) dp[s][e] = T(s+1 , e-1);
        else dp[s][e] = 1 + min(T(s+1, e), T(s, e-1));
    }
    return dp[s][e];
}
*/

int LCS(){
    int n = str.length() , m = rstr.length(); //m == n

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(str[i-1] == rstr[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int main()
{
    FasterIO

    int t; cin>>t;
    while(t--){
        cin>>str;

    //LCS solution took 0.32s while recursive one took 0.48 and both took same memory
        //using LCS
        rstr = "";
        int sz = str.length();
        for(int i=sz-1; i>=0; i--) rstr += str[i];
        cout<<sz - LCS()<<endl;

        //using recursion
        //cout<<T(0, str.length() - 1)<<endl;
    }

    return 0;
}

