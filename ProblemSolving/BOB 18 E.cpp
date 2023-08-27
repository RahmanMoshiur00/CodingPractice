#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld\n", (intl)x)
#define pfis(x)       printf("%lld ", (intl)x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, ed = (begin); i >= (ed); --i)
#define mem(a, v)     for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a))
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define SQ(x)         ((x)*(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 0 )
#define mxn           100010

int pow2[63];

void precal()
{
    pow2[0] = 1;
    rep(i, 1, 62) pow2[i] = 2 * pow2[i-1];
}

int bfs(int d, int x)
{
    queue< pair<pair<int, int>, int> > qu;
    qu.push({{0, 0}, d});

    while(!qu.empty()){
        int u = qu.front().first.first, l = qu.front().first.second, p = qu.front().second; qu.pop();
        if(u == x) return l;

        if(p>=0 and u + pow2[p] <= 2*x) qu.push({{u + pow2[p], l+1}, p-1});
        if(p>=0 and u + pow2[p] >= 0) qu.push({{u - pow2[p], l+1}, p-1});
    }

    return -1;
}


void solve(int tc)
{
    int d, x;
    sfi2(d, x);

    int ans = bfs(d, x);

    pfs("Case "), pfi(tc), pfs(": ");
    if(ans == -1){
        puts("NO");
    }
    else{
        pfs("YES "), pfin(ans);
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    //solve(1);

    precal();
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

