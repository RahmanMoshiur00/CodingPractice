#include<stdio.h>

int main()
{
    int n, i, j, l=2;

    scanf("%d", &n);

    for(i=1; i<=n/2; i++){
        for(j=i; j<=n/2; j++) printf(".");
        for(j=1; j<=n-(((n/2)-i+1)*2); j++){
            if(j>n/2){
                printf("%d", j-l);
                l+=2;
            }
            else
            printf("%d", j);
        }
        for(j=i; j<=n/2; j++) printf(".");
        printf("\n");
    }

    l=2;

    for(i=1; i<=n; i++){
        if(i>(n/2)+1){
                printf("%d", i-l);
                l+=2;
            }
        else
            printf("%d", i);
    }
    printf("\n");

    l=2;

    for(i=n/2; i>=1; i--){
        for(j=i; j<=n/2; j++) printf(".");
        for(j=1; j<=n-(((n/2)-i+1)*2); j++){
            if(j>n/2){
                printf("%d", j-l);
                l+=2;
            }
            else
            printf("%d", j);
        }
        for(j=i; j<=n/2; j++) printf(".");
        printf("\n");
    }

    return 0;

}
