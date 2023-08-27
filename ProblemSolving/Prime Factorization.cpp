#include<bits/stdc++.h>
using namespace std;
#define intt   long long
#define pb     push_back
#define MX     10000000 //10^7

bool checker[MX];
vector<intt> primes;
vector< pair<intt, intt> > prime_factors; // this array stores the prime factors

void sieve(intt mx){ //this function takes mx as parameter and stores 1 to mx prime numbers in "primes" and "prime_index"
    intt sq = sqrt(mx)+2;

    primes.pb(2); //2 is even prime number
    checker[1] = true; // making 1 a composite number

    for(intt i=4; i<=mx; i+=2) checker[i] = true; // i's are composite numbers

    for(intt i=3; i<=mx; i+=2){
        if(!checker[i]){
            primes.pb(i);
            if(i<=sq){ //katakuti shuru... this checkpoint is used to avoid overflow of i*i
                for(intt j=i*i; j<=mx; j+=i*2) checker[j] = true; //rannao shesh! Be ready for PET PUJO! :p
            }
        }
    }
}

void prime_factorization(intt n){
    intt counter = 0;
    for(intt i=0; primes[i]<=sqrt(n); i++){
        counter = 0;
        if(n%primes[i]==0){
            n /= primes[i];
            counter++;
            while(n%primes[i]==0){
                n /= primes[i];
                counter++;
            }
            prime_factors.push_back({primes[i], counter});
        }
    }
    if(n!=1){
        prime_factors.push_back({n,1});
    }
}


int main()
{
    /*
    Input:
    5
    7007
    123456
    1
    0
    81
    Output:
    7007 = 7^2 11 13
    123456 = 2^6 3 643
    1 = 1
    0 = 0
    81 = 3^4
    */

    sieve(100000); //10^6

    intt n, q;
    cin>>q;
    while(q--){
        cin>>n;
        if(n==0 || n==1){
            cout<<n<<" = "<<n<<endl;
            continue;
        }
        prime_factorization(n);
        int sz = prime_factors.size();
        cout<<n<<" =";
        for(int i=0; i<sz; i++){
            cout<<" "<<prime_factors[i].first;
            if(prime_factors[i].second != 1) cout<<"^"<<prime_factors[i].second;
        }
        cout<<endl;
        prime_factors.clear(); //must've to clear the stored data for further storing and computing
    }

    return 0;
}
