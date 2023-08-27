#include<stdio.h>

int main()
{
    int i, n, m, k, tmp, type1, type2, ans, num[50];
    while(scanf("%d %d %d", &n, &m, &k) == 3){
        type1 = 0, type2 = 0, ans = 0;
        for(i=0; i<n; i++){
            scanf("%d", &tmp);
            if(tmp==1) type1++;
            else if(tmp==2) type2++;
        }
        if(type1>m){
            ans += type1 - m;
            m = 0;
        }
        else m -= type1;
        if(type2 > (m+k)) ans += type2 - m - k;
        printf("%d\n", ans);
    }
}

