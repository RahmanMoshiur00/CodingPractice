#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    n = 10000000;
    vector<bool> checker(n);
    checker[0] = true;
    checker[1] = true;
    for(long long i=4; i<=n; i+=2) checker[i] = true;

    vector<long long> primes;
    primes.push_back(2);

    long long root = sqrt(n+1.0);

    for(long long i=3; i<=n; i+=2){
        if(!checker[i]){
            primes.push_back(i);
            if(i<=root){
                for(long long j=i*i; j<=n; j+=i*2) checker[j] = true;
            }
        }
    }


    printf("{");
    long long len = primes.size();
    for(long long i=0; i<len; i++) printf(", %lld", primes[i]);
    printf(" }");

    return 0;
}
