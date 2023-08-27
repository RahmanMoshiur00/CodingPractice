#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
#define MX      10005 //sqrt(10^12) = 10^6; so sieve between 1 to 10^6 is enough
#define pb      push_back
#define mp      make_pair

vector<int> primes;
bool check[MX];

void sieve(int n){
    primes.pb(2);
    check[0]=check[1]=true;
    int rt = sqrt(n)+2;
    for(int i=4; i<=n; i+=2) check[i] = true;
    for(int i=3; i<=n; i+=2){
        if(!check[i]){
            primes.pb(i);
            if(i<=rt){
                for(int j=i*i; j<=n; j+=2*i) check[j] = true;
            }
        }
    }
}

pair<int, int> prime_fact(int n){
    if(!check[n]) return mp(n, 1);
    int sz = primes.size();
    int ans = 1, fr = 1;
    for(int i=0; primes[i]<=sqrt(n)+1 && i<sz; i++){
        if(n%primes[i]==0){
            ans = primes[i];
            fr = 0;
            while(n%primes[i]==0){
                fr++;
                n /= primes[i];
            }
        }
    }
    if(n>1){ ans = n; fr = 1; }
    return mp(ans, fr);
}

int prime_divisor_counter(int n, int m){
    int ans = 0, i=1, div;
    div = n/pow(m, i++);
    while(div){
        ans += div;
        div = (n*1.0)/pow(m, i++);
    }
    return ans;
}

int main()
{
    sieve(MX);

    int tc; scanf("%d", &tc);
    int n, m;
    for(int t=1; t<=tc; t++){
        scanf("%d %d", &m, &n);
        pair<int, int> res = prime_fact(m);
        int ans = prime_divisor_counter(n, res.first)/res.second;
        if(ans==0) printf("Case %d:\nImpossible to divide\n", t);
        else printf("Case %d:\n%d\n", t, ans);
    }

    return 0;
}


