#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
#define MX      1000005 //sqrt(10^12) = 10^6; so sieve between 1 to 10^6 is enough
#define pb      push_back

vector<int> primes;
bool check[MX];
vector<int> factor;

void sieve(int n){
    primes.pb(2);
    check[0]=check[1]=true;
    int rt = sqrt(n)+2;
    for(int i=4; i<=n; i+=2) check[i] = true;
    for(int i=3; i<=n; i+=2){
        if(!check[i]){
            primes.pb(i);
            if(i<=rt){
                for(int j=i*i; j<=n; j+=2*i) check[j] = true;
            }
        }
    }
}

intt prime_fact(intt n){
    if(n<MX && !check[n]) return 2;
    int sz = primes.size();
    intt ans = 1, counter;
    for(int i=0; primes[i]<=sqrt(n)+1 && i<sz; i++){
        counter = 0;
        if(n%primes[i]==0){
            counter++;
            n /= primes[i];
            while(n%primes[i]==0){
                counter++;
                n /= primes[i];
            }
            ans *= counter+1;
        }
    }
    if(n>1) ans *= 2;
    return ans;
}

int main()
{
    sieve(MX);

    int tc; scanf("%d", &tc);
    intt n;
    for(int t=1; t<=tc; t++){
        scanf("%lld", &n);
        printf("Case %d: %lld\n", t, prime_fact(n)-1);
    }

    return 0;
}

