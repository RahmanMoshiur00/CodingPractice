#include<bits/stdc++.h>
using namespace std;
#define MX 1000005
#define sq(a) (a*a)
#define intt long long

vector<intt> primes;
bool check[MX];

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
    if(n<0){
        printf("%lld = -1 x", n);
        n *= -1;
    }
    else printf("%lld =", n);
    bool checker = false;
    for(intt i=0; primes[i]<=(intt)sqrt(n); i++){
        while(n%primes[i]==0){
            if(!checker){
                printf(" %lld", primes[i]);
                checker = true;
            }
            else printf(" x %lld", primes[i]);
            n /= primes[i];
        }
    }
    if(n!=1){
        if(checker==true) printf(" x %lld", n);
        else printf(" %lld", n);
    }
    printf("\n");
}

int main()
{
    sieve(MX);

    intt n;
    while(scanf("%lld", &n) && n){
        primeFactorization(n);
    }

    return 0;
}
