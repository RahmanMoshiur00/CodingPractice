#include <bits/stdc++.h>
using namespace std;
typedef int intt;
typedef long long int intl;
typedef unsigned long long intu;
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    scanf("%lld %lld", &x, &y)
#define sfi3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define pfi(x)        printf("%lld", (intl)x)
#define pfi2(x, y)    printf("%lld %lld", (intl)x, (intl)y)
#define pfi3(x, y, z) printf("%lld %lld %lld", (intl)x, (intl)y, (intl)z)
#define sfd(x)        scanf("%lf", &x)
#define sfd2(x, y)    scanf("%lf %lf", &x, &y)
#define sfd3(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)
#define sfs(x)        scanf("%s", x)
#define sfsn(x)       scanf("%[^\n]s", x)
#define pfs(x)        printf("%s", x)
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); i += 1)
#define per(i, end, begin) for (__typeof(end) i = (end)-1; i >= (begin); i -= 1)
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define mem(a, v)     memset((a), v, sizeof(a))
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ff            first
#define ss            second
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define SQ(x)         ((x)*(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 1 )
#define mxn           100010

void solve(int tc)
{
    int n; scanf("%d", &n);
    int m = 2*n - 1;
    int arr[m][n], dp[2][n];

    for(int i=0; i<m; i++){
        if(i<n) for(int j=0; j<=i; j++) scanf("%d", &arr[i][j]);
        else{
            int k = m-i-1;
            for(int j=0; j<=k; j++) scanf("%d", &arr[i][j]);
        }
    }

    dp[0][0] = arr[0][0];

    for(int i=1; i<m; i++){
        if(i<n){
            dp[i%2][0] = dp[(i-1)%2][0] + arr[i][0];
            dp[i%2][i] = dp[(i-1)%2][i-1] + arr[i][i];
            for(int j=1; j<i; j++) dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-1]) + arr[i][j];
        }
        else{
            int k = m-i-1;
            for(int j=0; j<=k; j++) dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j+1]) + arr[i][j];
        }
    }

    printf("Case %d: %d\n", tc, dp[0][0]);
}

int main()
{
    //INPUT
    int tc; scanf("%d", &tc);
    for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

