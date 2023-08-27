#include<stdio.h>

main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int cow, i;
        scanf("%d", &cow);
        printf("Case %d:\n", l);
        for(i=0; i<cow; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            if((x<=x2 && x>=x1) && (y<=y2 && y>=y1)) printf("Yes\n");
            else printf("No\n");
        }
    }
}
