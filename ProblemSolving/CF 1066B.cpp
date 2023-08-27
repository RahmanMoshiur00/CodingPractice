#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          '\n'
#define sp            ' '
#define debug(x)      cout<<">debug> "<< #x <<" : "<<x<<endl
#define FOREACH(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b)    for(intl i=(intl)(a);i<=(intl)(b);++i)
#define ROF(i,a,b)    for(intl i=(intl)(a);i>=(intl)(b);--i)
#define pb            push_back
#define MP            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000000
#define mod           1000000007
#define mxn           1010

intl a[mxn], dp[mxn][mxn], n, r;

intl solve(intl p, intl l){
    if(l>n) return dp[p][l] = 0;

    if(dp[p][l] == -1){
        if(a[p] == 1) dp[p][l] = min(1+solve(p+1, p+r-1), solve(p+1, l));
        else dp[p][l] = solve(p+1, l);
    }

    return dp[p][l];
}

int main()
{
    cin>>n>>r;
    for(int i=0; i<mxn; i++){
        for(int j=0; j<mxn; j++) dp[i][j] = -1;
    }

    for(int i=1; i<=n; i++) cin>>a[i];

    bool found = false;
    a[0] = 1, a[n+1] = 1;
    int st, ed;
    for(int i=0; i<=n+1; i++){
        if(a[i]==1){
            if(!found) st = i, found = true;
            else{
                int d = i - st - 1;
                if(d > 2*r){
                    cout<<-1<<endl;
                    return 0;
                }
                found = false;
                st = i;
            }
        }
    }

    cout<<solve(1, 1)<<endl;

    return 0;
}

