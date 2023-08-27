#include<bits/stdc++.h>
using namespace std;
#define intt            long long
#define uintt           unsigned long long
#define pii             pair<intt,intt>
#define piii            pair<intt, pair<intt, intt> >
#define ff              first
#define ss              second
#define sf              second.first
#define tt              second.second
#define pb              push_back
#define mp              make_pair
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())
#define PI              acos(-1.0)
#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)
#define WF19            ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SQ(a)           ((a)*(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define FOR(i,a,b)      for(intt i=a;i<(intt)b;i++)
#define ROF(i,a,b)      for(intt i=a;i>=(intt)b;i--)
#define REP(i,b)        for(intt i=0;i<(intt)b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))

#define INF             100000000 //10^9
#define MAX             1000005   //10^6 + 5


vector<int> primes;
bool check[MAX];
intt store[INF];

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

intt divisor_counter(intt n){
    int dummy = n;
    intt sum = 1, sz = primes.size(), pw;
    for(int i=0; (primes[i]<=sqrt(n)+1) && (i<sz); i++){
        pw = 0;
        if(n%primes[i]==0){
            pw++;
            n /= primes[i];
            while(n%primes[i]==0){
                pw++;
                n /= primes[i];
            }
            sum *= pw+1;
        }
    }
    if(n>1) sum *= 2;

    if(dummy<INF) store[dummy] = sum;
    return sum;
}


int main()
{
    WF19

    sieve(MAX);

    intt t, l, u, mx, div, num; cin>>t;
    while(t--){
        cin>>l>>u;
        mx = INT_MIN;
        for(intt i=l; i<=u; i++){
            if(i<INF && store[i]>0) div = store[i];
            else div = divisor_counter(i);
            if(div>mx){
                num = i;
                mx = div;
            }
        }
        cout<<"Between "<<l<<" and "<<u<<", "<<num<<" has a maximum of "<<mx<<" divisors."<<endl;
    }
    return 0;
}
