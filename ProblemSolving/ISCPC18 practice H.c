#include<stdio.h>

int main(){

    int tc, t;
    scanf("%d", &tc);

    for(t=1; t<=tc; t++){
        int i, l, r, v , ans = 0;
        scanf("%d %d", &l, &r);

        for(i=0; i<=31; i++){
            v = pow(2, i);
            if(v>=l && v<=r) ans++;
        }

        printf("%d\n", r - l + 1 - ans);
    }

}
