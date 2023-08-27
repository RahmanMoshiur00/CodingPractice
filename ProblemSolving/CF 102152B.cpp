#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long // change here

#define sfi(x)        scanf("%lld", &x) // change here
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
#define space         printf(" ")
#define newline       printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 0 )

const int mxn = 100010;

bool vis[mxn];

void solve(int tc)
{
    int seg, n, q, l, r;
    sfi3(seg, n, q);

    ZERO(vis);
    for(int i=0; i<seg; i++) {
        sfi2(l, r);
        for(int j=l; j<=r; j++) vis[j] = true;
    }

    pair<int,int> p[n+1];

    for(int i=0; i<=n; i++) p[i] = make_pair(-1LL, -1LL);

    int start = 0, finish = 0, len = 0;
    for(int i=n; i>=1; i--){
        if(!vis[i]){
            start = finish = i;
            int j;
            for(j=i-1; j>=1; j--){
                if(!vis[j]) start = j;
                else break;
            }
            i = j;
            len = finish - start + 1;
            while(len && p[len] == make_pair(-1LL, -1LL)){
                p[len] = make_pair(finish - len + 1, finish);
                len--;
            }
        }
    }

    int x;
    while(q--){
        sfi(x);
        cout<< p[x].first << sp << p[x].second << endl;
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

