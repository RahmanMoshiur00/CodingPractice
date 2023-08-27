#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 0 )

#define mxn           200010


vector<int> primes; // stores prime numbers

void sieve(int n) // finds all primes till n; including n
{
    bool mark[n+5]; // (mark[i] == false) for all prime i; initially mark[] is set to false
    memset(mark, false, sizeof mark);

    mark[1] = true;
    for(int i=4; i<=n; i+=2) mark[i] = true;

    primes.push_back(2LL);

    int rt = sqrt(n) + 2;
    for(int i=3; i<=n; i+=2){
        if(!mark[i]){
            primes.push_back(i);
            if(i <= rt){
                for(int j=i*i; j<=n; j += 2*i) mark[j] = true;
            }
        }
    }
}


void solve(int tc)
{
    int n; sfi(n);

    int v, one = 0, two = 0;
    rep(i, 0, n){
        sfi(v);
        if(v == 1) one++;
        else two++;
    }

    int ans[n+1], sum[n+1], prime;
    sum[0] = 0;

    rep(i, 1, n+1){
        prime = *upper_bound(all(primes), sum[i-1]);

        if(prime - sum[i-1] == 1){
            if(one){
                ans[i] = 1;
                sum[i] = sum[i-1] + 1;
                one--;
            }
            else{
                ans[i] = 2;
                sum[i] = sum[i-1] + 2;
                two--;
            }
        }
        else if(prime - sum[i-1] == 2){
            if(two){
                ans[i] = 2;
                sum[i] = sum[i-1] + 2;
                two--;
            }
            else{
                ans[i] = 1;
                sum[i] = sum[i-1] + 1;
                one--;
            }
        }
        else{
            if(two){
                ans[i] = 2;
                sum[i] = sum[i-1] + 2;
                two--;
            }
            else{
                ans[i] = 1;
                sum[i] = sum[i-1] + 1;
                one--;
            }
        }
    }

    rep(i, 1, n+1) pfis(ans[i]);
}

int32_t main()
{
    int n = mxn * 10;
    sieve(n);

    solve(1);

    return 0;
}

