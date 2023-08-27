#include<bits/stdc++.h>
using namespace std;
#define sfi(x)        scanf("%d", &x)
#define pfi(x)        printf("%d\n", x)
#define mxn           100010

int n;
int tr[2*mxn];

void build(){
    for(int i=0; i<2*i; i++) tr[i] = 0;
}

void update(int l, int r, int val){
    for(l+=n, r+=n; l<r; l/=2, r/=2){
        if(l)
    }
}
