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
#define mxn           1000010



int main()
{
    int n, m;
    cin>>n>>m;
    n += m;

    int arr[n+1], left[n+1], right[n+1], res[n+1];
    bool driver[n+1];

    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=1; i<=n; i++) cin>>driver[i] , res[i] = 0;

    int last = -1;
    for(int i=1; i<=n; i++){
        if(driver[i]) last = i;
        left[i] = last;
    }

    last = -1;
    for(int i=n; i>=1; i--){
        if(driver[i]) last = i;
        right[i] = last;
    }

    for(int i=1; i<=n; i++){
        if(!driver[i]){
            if(left[i] == -1) res[right[i]]++;
            else if(right[i] == -1) res[left[i]]++;
            else if(abs(arr[left[i]]-arr[i]) <= abs(arr[right[i]]-arr[i])) res[left[i]]++;
            else res[right[i]]++;
        }
    }

    for(int i=1; i<=n; i++) if(driver[i]) cout<<res[i]<<sp;

    return 0;
}

