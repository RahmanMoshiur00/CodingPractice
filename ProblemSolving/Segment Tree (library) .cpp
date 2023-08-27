#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           100010


int n;  // array size
int t[2 * mxn]; //segment tree array


// build the tree
void build() {
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];  // i<<1 = i*2 and i<<1|1 = (i*2) + 1
}

// set value at position p
void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1]; // (p >>= 1) = (p /= 2) , (p>>1 = p/2)
}

// sum on interval [l, r)
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
    build();
    modify(0, 1);
    printf("%d\n", query(3, 11));
    return 0;
}
