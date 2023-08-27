#include<stdio.h>
main()
{
    int a, b;
    scanf("%d", &b);
    for(a=0; a<b; a++){
        int m, n, j;
        scanf("%d", &n);
        for(m=1; m<=n; m++){
            for(j=1; j<=n; j++){
                printf("*");
            }
            printf("\n");
        }
    }
}
