#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
#define MX      65550 //sqrt(2^32  - 1) = 65536; so sieve between 1 to 65536 is enough
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
                for(int j=i*i; j<=n; j+=2*i) check[j] = false;
            }
        }
    }
}

void factor_counter(int n){
    int counter = 0;
    for(int i=0; primes[i]<=sqrt(n)+1; i++){
        counter = 0;
        while(n%primes[i]==0){
            counter++;
            n /= primes[i];
        }
        if(counter>0) factor.pb(counter);
    }
    if(n>1) factor.pb(1);
}

int main()
{
    sieve(MX);

    int n;
    while(cin>>n && n){
        factor.clear();
        factor_counter(n<0 ? -n:n);
        int sz = factor.size();
        for(int i=32; i>=1; i--){
            if(n<0 && i%2==0) continue;
            bool checker = true;
            for(int j=0; j<sz; j++){
                if(factor[j]%i != 0){ checker = false; break; }
            }
            if(checker){
                cout<<i<<endl;
                break;
            }
        }
    }

    return 0;
}
