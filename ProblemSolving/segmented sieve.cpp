#include<bits/stdc++.h>
using namespace std;

vector<long long> sieve(long long n){
    vector<bool> checker(n);
    checker[1] = true;
    for(long long i=4; i<=n; i+=2) checker[i] = true;

    vector<long long> primes;
    primes.push_back(2);

    long long root = sqrt(n+1.0);

    for(long long i=3; i<=n; i+=2){
        if(!checker[i]){
            primes.push_back(i);
            if(i<=root)
                for(long long j=i*i; j<=n; j+=i*2) checker[j] = true;
        }
    }

    return primes;
}

int main()
{
    long long low, high;
    cin>>low>>high;

    long long root_high = sqrt(high+1.0);

    vector<long long> reserve_primes;
    reserve_primes = sieve(root_high);

    vector<bool> check(high-low+1);

    vector<long long> segmented_primes;

    int k=0;

    for(long long j=low; j<=high; j++){
        int counter = 0;
        for(long long i = 0; i<reserve_primes.size(); i++){
            if(j%reserve_primes[i]==0){
                check[k++] = true;

                counter = 1;
                break;
            }
        }
        if(counter==0) segmented_primes.push_back(j);
    }

    for(int i=0; i<segmented_primes.size(); i++) cout<<segmented_primes[i]<<" ";


}
