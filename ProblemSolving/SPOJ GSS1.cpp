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
#define spc           printf(" ")
#define nwl           printf("\n")
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

const int mxn = 50010;

struct node
{
    int prefix, total, suffix, maxsum;
} seg[4*mxn];

int arr[mxn], n;

void build(int ind, int l, int r)
{
    if(l == r){
        seg[ind].prefix = seg[ind].total = seg[ind].suffix = seg[ind].maxsum = arr[l];
        return;
    }

    int mid = (l+r) >> 1;
    int left = ind << 1;
    int right = ind << 1 | 1;

    build(left, l, mid);
    build(right, mid+1, r);

    seg[ind].prefix = max(seg[left].prefix, seg[left].total + seg[right].prefix);
    seg[ind].total = seg[left].total + seg[right].total;
    seg[ind].suffix = max(seg[right].suffix, seg[right].total + seg[left].suffix);
    seg[ind].maxsum = max(max3(seg[ind].prefix, seg[ind].total, seg[ind].suffix), max3(seg[left].maxsum, seg[right].maxsum, seg[left].suffix + seg[right].prefix));
}

node query(int ind, int l, int r, int ql, int qr)
{
    if(l>=ql && r<=qr){
        return seg[ind];
    }

    int mid = (l+r) >> 1;
    int left = ind << 1;
    int right = ind << 1 | 1;


    if(qr <= mid) return query(left, l, mid, ql, qr);
    if(ql > mid) return query(right, mid+1, r, ql, qr);


    node q, q1, q2;
    q1 = query(left, l, mid, ql, qr);
    q2 = query(right, mid+1, r, ql, qr);

    q.prefix = max(q1.prefix, q1.total + q2.prefix);
    q.total = q1.total + q2.total;
    q.suffix = max(q2.suffix, q2.total + q1.suffix);
    q.maxsum = max(max3(q.prefix, q.total, q.suffix), max3(q1.maxsum, q2.maxsum, q1.suffix + q2.prefix));

    return q;
}

void solve(int tc)
{
    sfi(n);

    for(int i=1; i<=n; i++) sfi(arr[i]);

    build(1, 1, n);

    int q, l, r; sfi(q);

    node ans;
    while(q--){
        sfi2(l, r);
        ans = query(1, 1, n, l, r);
        pfin(ans.maxsum);
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}
