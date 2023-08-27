#include<bits/stdc++.h>
using namespace std;
#define intt long long
#define pb  push_back
#define MX  20000005

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

bool primeChecker(intt n){
    bool checker = true;
    for(intt i=0; primes[i]<=(intt)sqrt(n)+1; i++){
        if(n%primes[i]==0){
            checker = false;
            break;
        }
    }
    return checker;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    sieve(MX);

    intt n, sz = (intt)primes.size(), counter=0, perfect = 0;

    while(cin>>n && n){
        if(!check[n]){
            perfect = (intt)(pow(2LL, n*1LL)-1LL);
            counter = (intt)(pow(2LL, 1LL*(n-1LL)) * (pow(2LL, n*1LL)-1LL));
            if(perfect<MX && (!check[perfect])) cout<<"Perfect: "<<counter<<"!"<<endl;
            else if(primeChecker(perfect)) cout<<"Perfect: "<<counter<<"!"<<endl;
            else cout<<"Given number is prime. But, NO perfect number is available."<<endl;
        }
        else cout<<"Given number is NOT prime! NO perfect number is available."<<endl;
    }

    return 0;
}
