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

struct info{
    int value;
    int prop;
    info(){
        value = prop = 0;
    }
} tree[4 * mxn];

string str;
int ans = 0;

void build(int ind, int b, int e)
{
    if(b==e){
        tree[ind].value = str[b-1] - '0';
        tree[ind].prop = 0;
        return;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    build(left, b, mid);
    build(right, mid+1, e);
}

void update(int ind, int b, int e, int i, int j){
    if(i>e || b>j) return;
    if(b>=i && e<=j){
        tree[ind].prop += 1;
        return;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    update(left, b, mid, i, j);
    update(right, mid+1, e, i, j);
}

void query(int ind, int b, int e, int i, int carry)
{
    if(i>e || b>i) return;
    if(i==b && i==e){
        carry += tree[ind].prop;
        if(carry & 1) ans = tree[ind].value ^ 1;
        else ans = tree[ind].value;
        return;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    query(left, b, mid, i, carry+tree[ind].prop);
    query(right, mid+1, e, i, carry+tree[ind].prop);
}

void solve(int tc)
{
    cin>>str;
    int n = str.size();

    rep(i, 0, 4*mxn) tree[i].value = tree[i].prop = 0;

    build(1, 1, n);

    int qry;
    sfi(qry);

    char ch;
    int u, v;

    pfs("Case "), pfi(tc), pfs(":\n");
    while(qry--){
        sfc(ch);
        if(ch=='I'){
            sfi2(u, v);
            update(1, 1, n, u, v);
        }
        else{
            sfi(u);
            query(1, 1, n, u, 0);
            pfin(ans);
        }
    }
}

int32_t main()
{
    //INPUT //OUTPUT

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

