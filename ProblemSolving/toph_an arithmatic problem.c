#include<stdio.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int a, b, c, n;
        scanf("%d %d %d %d", &a, &b, &c, &n);
        if((b-a) == (c-b)) printf("Case %d: %d\n", l, n*(b-a));
        else printf("Case %d: Error\n", l);
    }

}
