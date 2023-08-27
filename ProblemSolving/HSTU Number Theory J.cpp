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
#define mxn           2000010

int phi[mxn];
int depth[mxn];
intl csum[mxn];

void phi_sieve(){
    for(int i=1; i<mxn; i++) phi[i] = i;
    for(int i=2; i<mxn; i++){
        if(phi[i]==i){
            phi[i] = i - 1;
            for(int j=2*i; j<mxn; j+=i) phi[j] = (phi[j]/i) * (i-1);
        }
    }
}

intl find_depth(int n){
    intl res = 1LL;
    while(phi[n] != 1){
        res++;
        n = phi[n];
    }
    return res;
}

void depth_calculate(){
    csum[1] = 1;
    for(int i=2; i<mxn; i++){
        csum[i] = csum[i-1] + find_depth(i);
    }
}


int main()
{
    phi_sieve();
    depth_calculate();

    int tc, l, r; sfi(tc);
    while(tc--){
        sfi(l) , sfi(r);
        pfl(csum[r] - csum[l-1]);
    }


    return 0;
}

