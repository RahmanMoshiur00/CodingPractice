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

const int mxn = 200010;

int arr[mxn], n;
bool seg[4*mxn][101], islazy[4*mxn];;
pair<int,int> lazy[4*mxn];

void build(int ind, int l, int r)
{
    if(l == r){
        seg[ind][arr[l]] = true;
        islazy[ind] = false;
        return;
    }

    int mid = (l+r) / 2;
    int left = ind + ind;
    int right = left + 1;

    build(left, l, mid);
    build(right, mid+1, r);

    rep(i, 1, 101){
        if(seg[left][i]|| seg[right][i]) seg[ind][i] = true;
        else seg[ind][i] = false;
    }
}

void propagate(int ind, int l, int r)
{
    int mid = (l+r) / 2;
    int left = ind + ind;
    int right = left + 1;

    int x = lazy[ind].first, y = lazy[ind].second;
    seg[ind][x] = false;
    seg[ind][y] = true;
    islazy[ind] = false;

    if(l != r){
        if(islazy[left]) propagate(left, l, mid);
        if(islazy[right]) propagate(right, mid+1, r);
        islazy[left] = islazy[right] = true;
        lazy[left] = lazy[right] = lazy[ind];
    }
}

void update(int ind, int l, int r, int ql, int qr, int x, int y)
{
    if(islazy[ind]) propagate(ind, l, r);

    if(r<ql || l>qr) return;
    if(l>=ql && r<=qr){
        if(seg[ind][x]){
            islazy[ind] = true;
            lazy[ind] = {x, y};
            propagate(ind, l, r);
        }
        return;
    }

    int mid = (l+r) / 2;
    int left = ind + ind;
    int right = left + 1;

    if(qr <= mid) update(left, l, mid, ql, qr, x, y);
    else if(ql > mid) update(right, mid+1, r, ql, qr, x, y);
    else update(left, l, mid, ql, qr, x, y), update(right, mid+1, r, ql, qr, x, y);

    rep(i, 1, 101){
        if(seg[left][i] || seg[right][i]) seg[ind][i] = true;
        else seg[ind][i] = false;
    }
}

int query(int ind, int l, int r, int i)
{
    if(islazy[ind]) propagate(ind, l, r);

    if(l==i && r==i){
        rep(j, 1, 101){
            if(seg[ind][j]) return j;
        }
    }

    int mid = (l+r) / 2;
    int left = ind + ind;
    int right = left + 1;

    if(i<=mid) return query(left, l, mid, i);
    else return query(right, mid+1, r, i);
}

void solve(int tc)
{
    sfi(n);
    rep(i, 1, n+1) sfi(arr[i]);

    build(1, 1, n);

    int l, r, x, y, ans, q;

    sfi(q);
    while(q--){
        sfi2(l, r); sfi2(x, y);
        update(1, 1, n, l, r, x, y);
    }

    rep(i, 1, n+1){
        ans = query(1, 1, n, i);
        pfis(ans);
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

