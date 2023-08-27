#include<bits/stdc++.h>
using namespace std;
#define pb      push_back
#define mp      make_pair
#define MX      1000005
typedef long long intt;

vector<intt> primes;
bool check[MX];
intt pow_counter[MX];
set<intt> factors;

void seive(intt n){
    check[0] = check[1] = true;
    primes.pb(2);
    intt rt = sqrt(n) + 1;
    for(intt i=4; i<=n; i+=2) check[i]=true;
    for(intt i=3; i<=n; i+=2){
        if(!check[i]){
            primes.pb(i);
            if(i<=rt) for(intt j=i*i; j<=n; j+=i*2) check[j] = true;
        }
    }
}

void primeFactorization(intt n){
    int sz = primes.size(), counter;
    for(intt i=0; (primes[i]<=sqrt(n)+1) && (i<sz); i++){
        counter = 0;
        if(n%primes[i]==0){
            counter++;
            n /= primes[i];
            while(n%primes[i]==0){
                counter++;
                n /= primes[i];
            }
            if(pow_counter[primes[i] ]==0) factors.insert(primes[i]);
            pow_counter[primes[i] ] += counter;
        }
    }
    if(n>1){
        if(pow_counter[n]==0) factors.insert(n);
        pow_counter[n] += 1;
    }
}

int main()
{
    seive(MX);

    intt tc, n;
    cin>>tc;
    for(intt t=1; t<=tc; t++){
        cin>>n;
        for(intt i=2; i<=n; i++) primeFactorization(i);

        cout<<"Case "<<t<<": "<<n<<" = ";
        intt num , sz = primes.size();
        set<intt>::iterator it=factors.begin();
        num = *it;
        it++;
        cout<<num<<" ("<<pow_counter[num]<<")";
        while(it!=factors.end()){
            num = *it;
            cout<<" * "<<num<<" ("<<pow_counter[num]<<")";
            it++;
        }
        cout<<endl;

        factors.clear();
        memset(pow_counter, 0, sizeof(pow_counter));
    }

    return 0;
}
