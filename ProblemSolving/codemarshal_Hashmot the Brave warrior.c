#include<stdio.h>
main()
{
    long long res, a, b;
    while(scanf("%lld %lld", &a, &b)==2){
        if(a>=b) res = a - b;
        else if(b>a) res = b - a;
        printf("%lld\n", res);
    }
    return 0;
}
