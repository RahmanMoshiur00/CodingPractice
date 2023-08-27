#include<stdio.h>

int main()
{
    int t, x;
    scanf("%d", &t);
    for(x=1; x<=t; x++){
        int nf, tp, count=0, i;
        scanf("%d %d", &nf, &tp);
        for(i=1; i<=nf; i++){
            int p, f;
            scanf("%d %d", &p, &f);
            if(p==1 && f>=tp) count += f;
            else if(p==2) count += f;
        }
        printf("Case %d: %d\n", x, count);
    }
    return 0;
}
