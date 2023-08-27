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


bool checker[mxn];
vector<intl> primes;

void sieve(intl mx){
    int sq = sqrt(mx)+2;

    primes.pb(2LL);
    checker[0] = checker[1] = true;

    for(intl i=4LL; i<=mx; i+=2) checker[i] = true;

    for(intl i=3LL; i<=mx; i+=2LL){
        if(!checker[i]){
            primes.pb(i);
            if(i<=sq){
                for(intl j=i*i; j<=mx; j+=i*2) checker[j] = true;
            }
        }
    }
}

intl findSmallestDiv(intl n){
    intl sq = sqrt(n+1), sz = primes.size();

    for(intl i=0; i<sz and primes[i]<=sq; i++) if(n%primes[i]==0) return primes[i];

    return n;
}


intl solve(intl n){
    if(n%2==0) return n/2;
    return 1 + solve(n - findSmallestDiv(n));
}

int main()
{
    sieve(mxn*1LL);

    intl n, ans = 0LL, val;
    cin>>n;

    cout<<solve(n)<<endl;

    return 0;
}
