#include<bits/stdc++.h>
using namespace std;
#define intt   long long
#define pb     push_back
#define MX     10000000 //10^7

bool checker[MX];
vector<intt> primes;

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

intt divisor_counter(intt n){
    intt ans=1, counter=0;
    for(intt i=0; primes[i]<=sqrt(n); i++){
        counter = 0;
        if(n%primes[i]==0){
            n /= primes[i];
            counter++;
            while(n%primes[i]==0){
                n /= primes[i];
                counter++;
            }
            ans *= counter+1;
        }
    }
    if(n!=1) ans *= 2;

    return ans;
}


int main()
{
    /*
    Input:
    6
    7007
    123456
    1
    668
    81
    12
    ***food for thought: What is(are) the divisor(s) of zero(0)?
    Output:
    12
    28
    1
    6
    5
    6
    */

    sieve(100000); //10^6

    intt n, q;
    cin>>q;
    while(q--){
        cin>>n;
        cout<<divisor_counter(n)<<endl;
    }

    return 0;
}

