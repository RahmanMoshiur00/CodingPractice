#include<bits/stdc++.h>
using namespace std;
#define pb  push_back
#define MX  1000005

vector<int> primes;
bool check[MX];

void sieve(int n){
    check[0] = check[1] = true;
    primes.pb(2);
    for(int i=2; i<=n; i+=2) check[i] = true;
    int rt = sqrt(n) + 2;
    for(int i=3; i<=n; i+=2){
        if(!check[i]){
            primes.pb(i);
            if(i<=rt){
                for(int j=i*i; j<=n; j += i*2) check[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    sieve(MX);

    int n, sz = primes.size();

    while(cin>>n && n){
        bool chk = true;
        for(int i=1; (primes[i]<=n/2) && (i<sz); i++){
            if(!check[ primes[i] ] && !check[ n-primes[i] ]){
                cout<<n<<" = "<<primes[i]<<" + "<<n-primes[i]<<endl;
                chk = false;
                break;
            }
        }
        if(chk) cout<<"Goldbach's conjecture is wrong."<<endl;
    }

    return 0;
}
