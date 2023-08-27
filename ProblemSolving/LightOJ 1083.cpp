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

#define mxn           30010


struct info{
    int mn;
    int indx;
} tree[4 * mxn];

int arr[mxn], n;

void build(int node, int b, int e)
{
    if(b==e){
        tree[node].indx = b;
        tree[node].mn = arr[b];
        return;
    }

    int mid = (b+e) >> 1;
    int left = node << 1;
    int right = left + 1;

    build(left, b, mid);
    build(right, mid+1, e);

    tree[node].mn = min(tree[left].mn, tree[right].mn);
    tree[node].indx = (tree[node].mn == tree[left].mn) ? tree[left].indx : tree[right].indx;
}

pair<int,int> RMQ_index(int ind, int b, int e, int l, int r)
{
    if(e<l or b>r){
        return {INT_MAX, INT_MAX};
    }
    if(b>=l and e<=r){
        return {tree[ind].mn, tree[ind].indx};
    }

    int mid = (b+e) >> 1;
    int left = ind << 1;
    int right = left + 1;

    pair<int,int> q1 = RMQ_index(left, b, mid, l, r);
    pair<int,int> q2 = RMQ_index(right, mid+1, e, l, r);

    return min(q1, q2);
}

int query(int l, int r){
    if(l > r) return INT_MIN;
    if(l==r) return arr[l];

    pair<int,int> p = RMQ_index(1, 1, n, l, r); // finds the index of the minimum height
    int m = p.second; // index of the minimum height in range of l...r

    int q1 = query(l, m-1);
    int q2 = query(m+1, r);

    return max3(q1, q2, (r-l+1)*arr[m]);
}

void solve(int tc)
{
    sfi(n);

    rep(i, 1, n+1) sfi(arr[i]);

    build(1, 1, n);
    int ans = query(1, n);

    pfs("Case "), pfi(tc), pfs(": "), pfin(ans);
}

int32_t main()
{
    //INPUT OUTPUT

    //solve(1);
    int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

