#include <bits/stdc++.h>
using namespace std;
#define sfi(x)        scanf("%d", &x)
#define pfi(x)        printf("%d\n", x)
#define mxn           100010

int n;
int tr[2*mxn];

void build(){
    for(int i=n-1; i>=1; --i) tr[i] = min(tr[2*i], tr[2*i+1]);
}

int query(int l, int r){
    int res = INT_MAX;
    for(l+=n, r+=n; l<r; l/=2, r/=2){
        if(l&1) res = min(res, tr[l++]);
        if(r&1) res = min(res, tr[--r]);
    }
    return res;
}


int main()
{
    int tc, q, l, r;
    sfi(tc);
    for(int t=1; t<=tc; t++){
        sfi(n) , sfi(q);
        for(int i=0; i<n; i++) sfi(tr[n+i]);
        build();
        printf("Case %d:\n", t);
        while(q--){
            sfi(l) , sfi(r);
            pfi(query(l-1, r));
        }
    }

    return 0;
}

