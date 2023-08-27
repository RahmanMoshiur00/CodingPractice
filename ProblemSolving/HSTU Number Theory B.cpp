#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          '\n'
#define sp            ' '
#define debug(x)      cout<<">debug> "<< #x <<" : "<<x<<endl
#define FOREACH(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b)    for(intl i=(intl)(a);i<=(intl)(b);++i)
#define ROF(i,a,b)    for(intl i=(intl)(a);i>=(intl)(b);--i)
#define pb            push_back
#define MP            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000000
#define mod           1000000007
#define mxn           1000010


int ds[mxn];
vector<int> prime;
bool check[mxn];

void sieve(){
    int sq = sqrt(mxn) + 1;
    prime.pb(2);
    for(int i=4; i<mxn; i+=2) check[i] = true;
    for(int i=3; i<mxn; i+=2){
        if(!check[i]){
            prime.pb(i);
            if(i <= sq){
                for(int j=i*i; j<mxn; j+=i*2) check[j] = true;
            }
        }
    }
}

void ds_sum_generate(){
    ds[1] = 1;

    for(int i=2; i<mxn; i++){
        int n = i;
        if(!check[i]) ds[i] = 1 + i;
        else{
            for(int j=0; prime[j]<=sqrt(n+1); j++){
                if(n % prime[j] == 0){
                    int val = prime[j];
                    while(n % prime[j] == 0){
                        n /= prime[j];
                        val *= prime[j];
                    }
                    ds[i] = ds[n] * ((val-1) / (prime[j]-1));
                    break;
                }
            }
        }
    }
}

int main()
{

    sieve();
    ds_sum_generate();

    int l, r;
    sfi(l), sfi(r);

    int res = l;
    double least_triviality = double(ds[l]-l) / double(l);
    //cout<<l<<": "<<ds[l]<<sp<<least_triviality<<endl;
    for(int i=l+1; i<=r; i++){
        double triviality = double(ds[i]-i) / double(i);
        //cout<<i<<": "<<ds[i]<<sp<<triviality<<endl;
        if(triviality < least_triviality)  least_triviality = triviality , res = i;
    }

    pfi(res);

    return 0;
}

