#include<stdio.h>
int main()
{
    int t, l; scanf("%d", &t);
    for(l=1; l<=t; l++){
        int n, i, a, b;
        scanf("%d", &n);
        long long res = 0, ans = 0;
        for(i=1; i<n; i++){
            scanf("%d %d", &a, &b);
            res = res + a - b;
            if(res > ans) ans = res;
        }
        printf("Case %d: %lld\n", l, ans);
    }
}
