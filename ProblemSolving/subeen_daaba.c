#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int a, b, x, y;
        scanf("%d %d %d %d", &a, &b, &x, &y);
        if(abs(a-x) == abs(b-y)) printf("Case %d: %d\n", l, abs(x-a));
        else if(abs(a-x)>abs(b-y)) printf("Case %d: %d\n", l, abs(a-x));
        else printf("Case %d: %d\n", l, abs(b-y));
    }
    return 0;
}
