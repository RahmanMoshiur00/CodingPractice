#include<stdio.h>
main()
{
    int x, y, z, res;
    scanf("%d %d %d", &x, &y, &z);
    if(x>y && x<z || x<y && x>z) res = x;
    else if(x<y && y<z || x>y && y>z) res = y;
    else if(z>x && z<y || z<x && z>y) res = z;
    res = abs(res-x) + abs(res-y) + abs(res-z);
    printf("%d\n", res);
}
