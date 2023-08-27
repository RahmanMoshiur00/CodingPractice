#include <bits/stdc++.h>
using namespace std;
typedef int    intt;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%d", &x)
#define sfi2(x, y)    scanf("%d %d", &x, &y)
#define sfi3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfl(x)        scanf("%lld", &x)
#define sfl2(x, y)    scanf("%lld %lld", &x, &y)
#define sfl3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sfd(x)        scanf("%lf", &x)
#define sfd2(x, y)    scanf("%lf %lf", &x, &y)
#define sfd3(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)
#define sfs(x)        scanf("%s", x)
#define sfsn(x)       scanf("%[^\n]s", x)
#define pfi(x)        printf("%d", (intt)x)
#define pfi2(x, y)    printf("%d %d", (intt)x, (intt)y)
#define pfi3(x, y, z) printf("%d %d %d", (intt)x, (intt)y, (intt)z)
#define pfl(x)        printf("%lld", (intl)x)
#define pfl2(x, y)    printf("%lld %lld", (intl)x, (intl)y)
#define pfl3(x, y, z) printf("%lld %lld %lld", (intl)x, (intl)y, (intl)z)
#define pfs(x)        printf("%s", x)
#define space         printf(" ")
#define newl          printf("\n")
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(x, i)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define found(x, a)    x.find(a) != x.end()
#define ff            first
#define ss            second
#define all(a)        a.begin(),a.end()
#define endl          '\n'
#define sp            ' '
#define mem(a, v)     memset((a), v, sizeof(a))
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define mxn           100010



void solve(int tc)
{
    int n; cin>>n;
    int arr[n];

    rep(i, 0, n) cin>>arr[i];

    sort(arr, arr+n);

    int res = 0;
    for(int i=0; i<n; i+=2){
        res += abs(arr[i+1] - arr[i]);
    }

    cout<<res<<endl;
}

int32_t main()
{
    solve(1);
    //int tc; sfl(tc); rep(t, 1, tc+1) solve(t);

    return 0;
}

