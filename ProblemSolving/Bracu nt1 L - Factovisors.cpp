#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
#define pb      push_back
#define mp      make_pair
#define ff      first
#define ss      second
#define MX      10000005

vector<intt> primes;
bool check[MX];
vector< pair<intt, intt> > factors;

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
    intt sz = primes.size(), counter;
    for(intt i=0; (primes[i]<=sqrt(n)+1) && (i<sz); i++){
        counter = 0;
        if(n%primes[i]==0){
            counter++;
            n /= primes[i];
            while(n%primes[i]==0){
                counter++;
                n /= primes[i];
            }
            factors.pb(mp(primes[i], counter));
        }
    }
    if(n>1) factors.pb(mp(n, 1));
}

intt pow_counter(intt n, intt p){
    intt res = 0, i = 0, cal = 0;
    while(true){
        cal = n / pow(p, ++i);
        res += cal;
        if(cal==0) break;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    seive(MX);

    intt n, m;
    while(scanf("%lld %lld", &n, &m) != EOF){
        if(n>=m || m==1){
            cout<<m<<" divides "<<n<<"!"<<endl;
            continue;
        }
        else if(m==0){ cout<<m<<" does not divide "<<n<<"!"<<endl; continue; }

        primeFactorization(m);

        bool Divide = true;
        int sz = factors.size();

        for(intt i=0; i<sz; i++){
            if(factors[i].ss > pow_counter(n, factors[i].ff)){
                Divide = false;
                break;
            }
        }

        if(Divide) cout<<m<<" divides "<<n<<"!"<<endl;
        else cout<<m<<" does not divide "<<n<<"!"<<endl;

        factors.clear();
    }

    return 0;
}
