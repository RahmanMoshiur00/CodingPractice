#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int x, y;
        scanf("%d %d", &x, &y);
        double ans = (x*y) / 2.0;
        printf("Case %d: %d\n", l, (int)ceil(ans));
    }
}
