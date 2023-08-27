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
#define mxn           1050010

double lg[mxn];

void lg_generate(){
    lg[1] = 0.0;
    for(int i=2; i<mxn; i++) lg[i] = lg[i-1] + log(i);
}

int factor(int n, int p){
    int res = 0;
    while(n/p) res += n/p , n /= p;
    return res;
}

int zeros(int n, int b){
    int zero = INF, cnt = 0;

    if(b%2==0){
        while(b%2==0) cnt++, b /= 2;
        zero = min(zero, factor(n,2)/cnt);
    }
    for(int i=3; i<=sqrt(b+1); i+=2){
        if(b%i==0){
            cnt = 0;
            while(b%i==0) cnt++ , b /= i;
            zero = min(zero, factor(n, i)/cnt);
        }
    }
    if(b!=1) zero = min(zero, factor(n, b));

    return zero;
}

int main()
{
    lg_generate();

    int n, b;
    while(cin>>n>>b) cout<<zeros(n,b)<<sp<<int(1.000000001 + (lg[n] / log(b)))<<endl;


    return 0;
}

