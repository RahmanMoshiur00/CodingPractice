#include <bits/stdc++.h>
using namespace std;

#define mxn   100010

int n;
int tr[2*mxn];

void build(){
    for(int i=n-1; i>=1; --i) tr[i] = 0;
}

void update(int l, int r){
    for(l+=n, r+=n; l<r; l/=2, r/=2){
        if(l&1){
            if(tr[l]==0) tr[l] = 1;
            else tr[l] = 0;
            l++;
        }
        if(r&1){
            --r;
            if(tr[r]==0) tr[r] = 1;
            else tr[r] = 0;
        }
    }
}

int query(int p){
    p+=n;
    int res = tr[p];
    for(p/=2; p>=1; p/=2){
        if(tr[p]==1){
            if(res == 0) res = 1;
            else res = 0;
        }
    }
    return res;
}

int main()
{
    int tc, q, l, r, p;
    scanf("%d", &tc);
    char ch, str[mxn];

    for(int t=1; t<=tc; t++){
        scanf(" %s", str);
        n = strlen(str);
        for(int i=0; i<n; i++) tr[n+i] = str[i] - '0';
        build();
        scanf(" %d", &q);
        printf("Case %d:\n", t);
        while(q--){
            scanf(" %c", &ch);
            if(ch=='I'){
                scanf(" %d %d", &l, &r);
                update(l-1,r);
            }
            else{
                scanf(" %d", &p);
                printf("%d\n", query(p-1));
            }
        }
    }

    return 0;
}
