#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++){
        int l, r, v, ans = 0;
        scanf("%d %d", &l, &r);

        for(int i=1; i<=31; i++){
            v = v*2;
            if(v>=l && v<=r) ans++;
        }

        printf("%d\n", ans);
    }

}
