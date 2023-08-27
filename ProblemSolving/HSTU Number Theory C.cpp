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
#define mxn           5000010



int phi[mxn];
intu sum[mxn];

void phi_sieve(){
    phi[1] = 1;
    sum[1] = 1LL;

    for(int i=2; i<mxn; i++) phi[i] = i;
    for(int i=2; i<mxn; i++){
        if(phi[i] == i){
            phi[i] = i - 1;
            for(int j=2*i; j<mxn; j+=i) phi[j] = (phi[j]/i) * (i-1);
        }
    }

    intu t;
    for(int i=2; i<mxn; i++){
        t = phi[i];
        t *= phi[i];
        sum[i] = sum[i-1] + t;
    }
}

int main()
{

    phi_sieve();

    int tc, l, r; sfi(tc);

    for(int t=1; t<=tc; t++){
        scanf("%d %d", &l, &r);
        printf("Case %d: %llu\n", t, sum[r] - sum[l-1]);
    }


    return 0;
}


