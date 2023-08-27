#include<stdio.h>

int main()
{
    int n, i, j, l=0;
    scanf("%d", &n);

    for(i=1; i<=n/2; i++){
        for(j=n/2; j>=i; j--) printf(".");
        for(j=l+i; j>=1; j--) printf("*");
        for(j=n/2; j>=i; j--) printf(".");
        l++;
        printf("\n");
    }

    for(i=1; i<=n; i++) printf("*");
    if(n%2==0) printf("*");
    printf("\n");

    l=n/2;

    for(i=n/2; i>=1; i--){
        for(j=n/2; j>=i; j--) printf(".");
        for(j=l+i; j>1; j--) printf("*");
        for(j=n/2; j>=i; j--) printf(".");
        l--;
        printf("\n");
    }

    return 0;
}

