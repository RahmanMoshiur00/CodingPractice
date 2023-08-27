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
#define debug         if( 1 )

#define mxn           100010

struct info{
    int mx;
    int mn;
    info(){
        mx = INT_MIN;
        mn = INT_MAX;
    }
} tree[4 * mxn];

int arr[mxn];

void build(int ind, int b, int e)
{
    if(b==e){
        tree[ind].mx = arr[b];
        tree[ind].mn = arr[b];
        return;
    }

    int mid = (b+e) / 2;
    int left = ind * 2;
    int right = left + 1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[ind].mx = max(tree[left].mx , tree[right].mx);
    tree[ind].mn = min(tree[left].mn , tree[right].mn);
}

pair<int,int> query(int ind, int b, int e, int i, int j)
{
    if(i>e || b>j){
        return make_pair(INT_MIN, INT_MAX);
    }
    if(b>=i && e<=j){
        return make_pair(tree[ind].mx, tree[ind].mn);
    }

    int mid = (b+e) / 2;
    int left = ind * 2;
    int right = left + 1;

    pair<int,int> q1 = query(left, b, mid, i, j);
    pair<int,int> q2 = query(right, mid+1, e, i, j);

    return make_pair( max(q1.first, q2.first), min(q1.second, q2.second) );
}

void solve(int tc)
{
    int n, d;
    sfi2(n, d);

    rep(i, 1, n+1) sfi(arr[i]);

    rep(i, 0, 4*mxn) tree[i].mx = INT_MIN, tree[i].mn = INT_MAX;
    build(1, 1, n);

    int res = 0;
    pair<int,int> p;
    rep (i, 1, (n-d+1) + 1){
        int j = i + d - 1;
        p = query(1, 1, n, i, j);
        res = max(res, p.first - p.second);
    }

    pfs("Case "), pfi(tc), pfs(": "), pfin(res);
}

int32_t main()
{
    //INPUT //OUTPUT

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

