#include<bits/stdc++.h>
using namespace std;
#define intt            long long
#define uintt           unsigned long long
#define pii             pair<intt,intt>
#define piii            pair<intt, pair<intt, intt> >
#define fi              first
#define se              second
#define sf              second.first
#define ss              second.second
#define pb              push_back
#define mp              make_pair
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())
#define PI              acos(-1.0)
#define WF19            ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SQ(a)           ((a)*(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define FOR(i,a,b)      for(intt i=a;i<(intt)b;i++)
#define ROF(i,a,b)      for(intt i=a;i>=(intt)b;i--)
#define REP(i,b)        for(intt i=0;i<(intt)b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))

#define INF             1000000000 //10^9
#define MX              1000005    //10^6 + 5

vector<intt> primes;
bool check[MX];
set<intt> factors;
intt factor_count[MX];
intt dp[10005];

void sieve(intt n){
    check[0] = check[1] = true;
    primes.push_back(2);
    for(intt i=4; i<=n; i+=2) check[i] = true;
    intt rt = sqrt(n) + 2;
    for(intt i=3; i<=n; i+=2){
        if(!check[i]){
            primes.push_back(i);
            if(i<=rt){
                for(intt j=i*i; j<=n; j+=i*2) check[j] = true;
            }
        }
    }
}

void primeFactorization(intt n){
    intt sz = primes.size(), counter = 0;
    for(intt i=0; (primes[i]<=(intt)sqrt(n)+2) && i<sz; i++){
        counter = 0;
        if(n%primes[i]==0){
            n /= primes[i];
            counter++;
            while(n%primes[i]==0){
                n /= primes[i];
                counter++;
            }
            factors.insert(primes[i]);
            factor_count[primes[i] ] += counter;
        }
    }
    if(n>1){
        factors.insert(n);
        factor_count[n] += 1;
    }
}

intt bigMod(intt a, intt b, intt m){ //a^b%m
     intt mod=1;
     while(b>0){
        if(b&1) mod =(mod*a)%m;
        b /= 2;
        a =(a*a)%m;
    }
    return mod;
}

int main()
{
    WF19
    sieve(MX);
    intt n;
    while(scanf("%lld", &n) != EOF){
        if(dp[n]==0){
            for(intt i=2; i<=n; i++){
                primeFactorization(i);
            }
            factor_count[2] -= factor_count[5];
            factor_count[5] = 0;
            intt ans = 1;
            for(set<intt>::iterator it=factors.begin(); it!=factors.end(); it++){
                intt a = *it;
                ans = ((ans%10) *  bigMod(a,factor_count[a], 10LL))%10;
            }
            printf("%6lld -> %lld\n", n, ans);
            dp[n] = ans;
            factors.clear();
            MEM(factor_count,0);
        }
        else printf("%5lld -> %lld\n", n, dp[n]);
    }

    return 0;
}
