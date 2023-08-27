#include<bits/stdc++.h>
using namespace std;
#define pb  push_back
#define mp  make_pair
#define MX  20000005

vector<int> primes;
bool check[MX];
vector< pair<int, int> > twins;

void sieve(int n){
    check[0] = check[1] = true;
    primes.pb(2);
    for(int i=2; i<=n; i+=2) check[i] = true;
    int rt = sqrt(n) + 2, sz = 0;
    for(int i=3; i<=n; i+=2){
        if(!check[i]){
            primes.pb(i);
            sz = primes.size();
            if(primes[sz-1]-primes[sz-2]==2) twins.pb(mp(primes[sz-2], primes[sz-1]));
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

    while(scanf("%d", &n)!=EOF) cout<<"("<<twins[n-1].first<<", "<<twins[n-1].second<<")"<<endl;

    return 0;
}
