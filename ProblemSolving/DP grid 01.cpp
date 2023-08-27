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
#define MX            1005

intl R , C , paths = 0;
intl dp[MX][MX];
string str[MX];

bool inGrid(int r, int c){
    if((r>=1 && r<=R) && (c>=1 && c<=C)) return true;
    else return false;
}

/*
intl (int r, int c){
    if(!inGrid(r, c)) return INT_MIN;
    if(str[r][c]=='0' || (r==R && c==1)) dp[r][c] = 0;
    if(dp[r][c]==-1) dp[r][c] = 1 + max(f(r, c-1), f(r+1, c));
    return dp[r][c];
}
*/

void f(int r, int c){
    if(!inGrid(r, c) || str[r][c-1]=='0') return;
    if(r==1 && c==C){
        paths++;
        return;
    }
    f(r-1, c);
    f(r, c+1);
}

int main()
{
    FasterIO
    while(false){}

    cin>>R>>C;
    for(int i=1; i<=R; i++) cin>>str[i];

    mem(dp, -1LL);

    f(R, 1);

    cout<<paths<<endl;

    return 0;
}
