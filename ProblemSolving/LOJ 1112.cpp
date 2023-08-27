#include<bits/stdc++.h>
using namespace std;
#define sfi(x)        scanf("%d", &x)
#define pfi(x)        printf("%d\n", x)
#define mxn           100010

int n;
int tr[2*mxn];

void build(){
    for(int i=n-1; i>=1; --i) tr[i] = tr[2*i] + tr[2*i+1];
}

void update(int p, int val){
    for(tr[p+=n]+=val; p>=2; p/=2) tr[p/2] = tr[p] + tr[p^1];
}

void update_to_zero(int p){
    for(tr[p+=n]=0; p>=2; p/=2) tr[p/2] = tr[p] + tr[p^1];
}

int query(int l, int r){
    int sum = 0;
    for(l+=n, r+=n; l<r; l/=2, r/=2){
        if(l&1) sum += tr[l++];
        if(r&1) sum += tr[--r];
    }
    return sum;
}

int main()
{
    int tc, q, code, p, val, l, r;
    sfi(tc);
    for(int t=1; t<=tc; t++){
        sfi(n) , sfi(q);
        for(int i=0; i<n; i++) sfi(tr[n+i]);
        build();
        printf("Case %d:\n", t);
        while(q--){
            sfi(code);
            if(code==1){
                sfi(p);
                pfi(tr[n+p]);
                update_to_zero(p);
            }
            else if(code==2){
                sfi(p) , sfi(val);
                update(p, val);
            }
            else{
                sfi(l) , sfi(r);
                pfi(query(l, r+1));
            }
        }
    }

    return 0;
}
