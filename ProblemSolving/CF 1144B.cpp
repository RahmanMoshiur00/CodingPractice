#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x) // changes
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x) // no changes
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

#define mxn           100010


void solve(int tc)
{
    int n, v;
    sfi(n);

    priority_queue<int> even1, odd1, even2, odd2;
    rep(i, 0, n){
        sfi(v);
        if(v & 1) odd1.push(v), odd2.push(v);
        else even1.push(v), even2.push(v);
    }

    int ans1 = 0, ans2 = 0;
    rep(i, 0, n){
        if(i&1){
            if(odd1.empty()) break;
            odd1.pop();
        }
        else{
            if(even1.empty()) break;
            even1.pop();
        }
    }

    while(!even1.empty() or !odd1.empty()){
        if(!even1.empty()){
            ans1 += even1.top();
            even1.pop();
        }
        if(!odd1.empty()){
            ans1 += odd1.top();
            odd1.pop();
        }
    }

    rep(i, 0, n){
        if(!(i&1)){
            if(odd2.empty()) break;
            odd2.pop();
        }
        else{
            if(even2.empty()) break;
            even2.pop();
        }
    }

    while(!even2.empty() or !odd2.empty()){
        if(!even2.empty()){
            ans2 += even2.top();
            even2.pop();
        }
        if(!odd2.empty()){
            ans2 += odd2.top();
            odd2.pop();
        }
    }

    int ans = min(ans1, ans2);
    cout<<ans<<endl;
}

int32_t main()
{
    solve(1);

    return 0;
}

