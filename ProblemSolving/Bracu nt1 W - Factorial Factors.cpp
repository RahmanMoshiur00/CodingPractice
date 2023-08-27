#include<bits/stdc++.h>
using namespace std;
#define pb      push_back
#define mp      make_pair
#define MX      1000005
typedef long long intt;

vector<intt> primes;
bool check[MX];
intt dp[MX];

void seive(intt n){
    check[0] = check[1] = true;
    primes.pb(2);
    intt rt = sqrt(n) + 1;
    for(intt i=4; i<=n; i+=2) check[i]=true;
    for(intt i=3; i<=n; i+=2){
        if(!check[i]){
            primes.pb(i);
            if(i<=rt) for(intt j=i*i; j<=n; j+=i*2) check[j] = true;
        }
    }
}

intt primeFactorization(intt n){
    if(!check[n]) return 1;
    intt sz = primes.size(), counter=0;
    for(intt i=0; (primes[i]<=sqrt(n)+1) && (i<sz); i++){
        if(n%primes[i]==0){
            counter++;
            n /= primes[i];
            while(n%primes[i]==0){
                counter++;
                n /= primes[i];
            }
        }
    }
    if(n>1) counter++;
    return counter;
}

void Generate(){
    dp[0] = dp[1] = dp[2] = 1;
    for(intt i=3; i<MX; i++) dp[i] = primeFactorization(i) + dp[i-1];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    seive(MX);
    Generate();
    intt n;

    while(scanf("%lld", &n)!=EOF) cout<<dp[n]<<endl;

    return 0;
}

