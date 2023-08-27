#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long intu;
typedef long long int intl;

#define watchi(a, i)    cout<<":>>   "<< #a <<"-> ["<<i<<"]"<<" : "<<a<<endl
#define watch(a)        cout<<":>>   "<< #a <<" : "<<a<<endl
#define FastRead        ios::sync_with_stdio(0); cin.tie(0);
#define OUTPUT          freopen("output.txt","w",stdout);
#define INPUT           freopen("input.txt","r",stdin);

#define int             long long
#define pfi(a)          printf("%lld", (intl)a)
#define pfin(a)         printf("%lld", (intl)a), printf("\n")
#define pfis(a)         printf("%lld", (intl)a), printf(" ")
#define pfc(a)          printf("%c", a)
#define pfs(a)          printf("%s", a)
#define pfsn(a)         printf("%s", a), printf("\n")
#define space           printf(" ")
#define newl            printf("\n")
#define endl            '\n'
#define sp              ' '

#define sfi(a)          scanf("%lld", &a)
#define sfi2(a,b)       sfi(a), sfi(b)
#define sfi3(a, b, c)   sfi(a), sfi(b), sfi(c)
#define sfc(a)          scanf(" %c", &a)
#define sfs(a)          scanf(" %s", a)
#define sfsn(a)         scanf(" %[^\n]s", a)

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, ed = (begin); i >= (ed); --i)
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)

#define ZERO(a)         memset(a, 0, sizeof(a))
#define MINUS(a)        memset(a, 0xff, sizeof(a))
#define setval(a, v)    for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }

#define all(a)          a.begin(), a.end()
#define max3(a, b, c)   max(a,max(b,c))
#define min3(a, b, c)   min(a,min(b,c))
#define INF             1000000007
#define debug           if( 0 )

/*
bool vis[mxn];

void bfs(int n, int m)
{
    queue< pair<int,int> > qu;
    vis[n] = true;
    qu.push({n, 0});

    while(!qu.empty()){
        int v = qu.front().first, l = qu.front().second; qu.pop();
        if(v == m){
            pfin(l);
            return;
        }
        if(v*2 <= m and !vis[v*2]){
            vis[v*2] = true;
            qu.push({v*2, l+1});
        }
        if(v*3 <= m and !vis[v*3]){
            vis[v*3] = true;
            qu.push({v*3, l+1});
        }
    }
    pfin(-1);
}
*/

void call(int n, int m, int l){
    if(n == m){
        pfin(l);
        exit(0);
    }
    if(n>m) return;

    call(n*2, m, l+1);
    call(n*3, m, l+1);
}
void solve(int tc)
{
    int n, m;
    sfi2(n, m);

    //bfs(n, m);
    call(n, m, 0);
}

int32_t main()
{
    //INPUT //OUTPUT

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

// int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1}; //4 Direction
// int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
// int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
// int dx[]={2,1,-1,-2,-1,1}; int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

