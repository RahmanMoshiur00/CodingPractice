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


bool isPrime[mxn];


int main()
{

    intl l, r; cin>>l>>r;

    for(intl i = 2; i * i <= r; i++){
        for(intl j = max(i * i, (l + (i - 1)) / i  * i); j <= r; j += i) {
            isPrime[j - l] = true;
        }
    }

    int cnt = 0;

    for(intl i=0; i<r - l + 1; i++) if(!isPrime[i]) cnt++;

    int print = 0;
    if(cnt >= (r - l + 1)/2){
        cout<<"YES"<<endl;
        intl not_prime;
        if(l==1LL){
            not_prime = 4;
            cout<<2<<sp<<1<<endl;
            print++;
        }
        else not_prime = l+1LL;
        for(intl i = max(l, 3LL); i <= r; i++){
            if(!isPrime[i - l]){
                for(intl j = not_prime; ; j++){
                    if(isPrime[j - l]){
                        cout<<i<<sp<<j<<endl;
                        not_prime++;
                        print++;
                        break;
                    }
                    else not_prime++;
                }
            }
            if(print == (r - l + 1)/2) break;
        }
    }
    else{
        cout<<"NO"<<endl;
    }


    return 0;
}

