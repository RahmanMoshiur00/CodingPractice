#include<bits/stdc++.h>
using namespace std;
#define MX      1000005
#define sq(a)   (a*a)
#define intt    long long
#define WF19    ios_base::sync_with_stdio(false);cin.tie(NULL);

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
    int sz = primes.size();
    for(intt i=0; (primes[i]<=(intt)sqrt(n)) && i<sz; i++){
        while(n%primes[i]==0){
            cout<<"    "<<primes[i]<<endl;
            n /= primes[i];
        }
    }
    if(n!=1) cout<<"    "<<n<<endl;
    cout<<endl;
}

int main()
{
    WF19

    sieve(MX);

    intt n;
    while(scanf("%lld", &n)){
        if(n<0){
            return 0;
        }
        primeFactorization(n);
    }

    return 0;
}
