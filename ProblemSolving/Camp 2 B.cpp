#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define sfi(x)        scanf("%lld", &x)
#define debug         if( 0 )

const int mxn = 1e5 + 5e4 + 10;

int n, tree[4*mxn], arr[mxn];

void build(int ind, int l, int r)
{
    if(l==r){
        if(l<=n) tree[ind] = 1;
        else tree[ind] = 0;
        return;
    }

    int mid = (l+r) /2 ;
    int left = ind * 2;
    int right = left + 1;

    build(left, l, mid);
    build(right, mid+1, r);

    tree[ind] = tree[left] + tree[right];
}

int query(int ind, int l, int r, int ql, int qr)
{
    if(r<ql || l>qr) return 0;
    if(ql<=l && r<=qr) return tree[ind];

    int mid = (l+r) /2 ;
    int left = ind * 2;
    int right = left + 1;

    int q1 = query(left, l, mid, ql, qr);
    int q2 = query(right, mid+1, r, ql, qr);

    return q1 + q2;
}

void update(int ind, int l, int r, int ql, int qr, int v)
{
    if(r<ql || l>qr) return;
    if(ql<=l && r<=qr){
        tree[ind] = v;
        return;
    }

    int mid = (l+r) /2 ;
    int left = ind * 2;
    int right = left + 1;

    update(left, l, mid, ql, qr, v);
    update(right, mid+1, r, ql, qr, v);

    tree[ind] = tree[left] + tree[right];
}

void solve(int test_case)
{
    printf("Case %lld:\n", test_case);
    int q;
    scanf("%lld %lld", &n, &q);

    for(int i=1; i<=n; i++) sfi(arr[i]);

    build(1, 1, n+q);

    int sz = n + q, k;
    char ch[10];
    while(q--){
        scanf("%s", ch);

        if(ch[0] == 'c'){
            sfi(k);
            int lo = 1, hi = sz, mid, pos = -1, tot;
            while(hi-lo > 1){
                mid = (lo + hi) / 2;
                tot = query(1, 1, sz, 1, mid);
                if(tot >= k){
                    hi = mid;
                } else {
                    lo = mid;
                }
            }

            for(int i=lo; i<=hi; i++){
                if(query(1, 1, sz, 1, i) == k){
                    pos = i;
                    break;
                }
            }

            if(pos == -1){
                printf("none\n");
            } else{
                printf("%lld\n", arr[pos]);
                update(1, 1, sz, pos, pos, 0);
            }
        } else{
            sfi(k);
            arr[++n] = k;
            update(1, 1, sz, n, n, 1);
        }
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

