#include<stdio.h>
int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        int n, j, k;
        scanf("%d", &n);
        printf("Case %d:\n", i);
        for(j=1; j<n; j++){
            for(k=1; k<=j; k++) printf("*");
            printf("\n");
        }
        for(j=1; j<=n; j++) printf("*");
        printf("\n");
        for(j=n-1; j>=1; j--){
            for(k=j; k>=1; k--) printf("*");
            printf("\n");
        }
    }
}
