#include<stdio.h>

main()
{
    int m, n;

    for(m=0; m < 5; m = m + 1){
        for(n=0; n < m + 1; n = n + 1){
            printf("*");
        }
        printf("\n");
    }


}
