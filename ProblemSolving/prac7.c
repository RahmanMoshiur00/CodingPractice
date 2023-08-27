#include<stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        for(j=n-i+1; j<n; j++) printf(".");
        for(j=1; j<n-i+1; j++) printf("%d", j);
        printf("%d", n-i+1);
        for(j=n-i; j>=1; j--) printf("%d", j);
        for(j=n-i+1; j<n; j++) printf(".");
        printf("\n");
    }
    return 0;
}
