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

struct info
{
    int sum;
    int prop;
} tree[mxn * 4];

void build(int ind, int b, int e)
{
    if(b==e){
        tree[ind].sum = 0;
        tree[ind].prop = 0;
        return;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[ind].prop = 0;
    tree[ind].sum = tree[left].sum + tree[right].sum;
}

void propagate(int ind, int b, int e)
{
    if(b != e){
        int left = ind << 1;
        int right = left + 1;
        tree[left].prop += tree[ind].prop;
        tree[right].prop += tree[ind].prop;
    }
    tree[ind].sum += (e-b+1) * tree[ind].prop;
    tree[ind].prop = 0;
}

void update(int ind, int b, int e, int l, int r, int v)
{
    if(tree[ind].prop) propagate(ind, b, e);

    if(e<l || b>r) return;
    if(b>=l && e<=r){
        tree[ind].prop += v;
        propagate(ind, b, e);
        return;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    update(left, b, mid, l, r, v);
    update(right, mid+1, e, l, r, v);

    tree[ind].sum = tree[left].sum + tree[right].sum;
}

int query(int ind, int b, int e, int l, int r)
{
    if(tree[ind].prop) propagate(ind, b, e);

    if(e<l || b>r) return 0;
    if(b>=l && e<=r){
        return tree[ind].sum;
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    int q1 = query(left, b, mid, l, r);
    int q2 = query(right, mid+1, e, l, r);

    return q1 + q2;
}

void solve(int tc)
{
    int n, q, x, y, v, ans, typ;
    sfi2(n, q);

    build(1, 1, n);

    pfs("Case "), pfi(tc), pfs(":\n");
    while(q--){
        sfi(typ);
        if(typ == 0){
            sfi3(x, y, v);
            update(1, 1, n, x+1, y+1, v);
        }
        else{
            sfi2(x, y);
            ans = query(1, 1, n, x+1, y+1);
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
