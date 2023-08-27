#include<stdio.h>
main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        unsigned long int n, j;
        scanf("%lu", &n);
        printf("Case %d:\n", i);
        for(j=1; j<=10; j++){
            printf("%lu * %lu = %lu\n", n, j, n*j);
        }
    }
}
