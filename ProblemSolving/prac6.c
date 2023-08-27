
#include<stdio.h>
int main()
{
    int n, i, j, k, l=1;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        for(k=i; k<=((n*2)-1)/2; k++) printf(".");
        for(k=1; k<=(i*2)-1; k++) printf("*");
        for(k=i; k<=((n*2)-1)/2; k++) printf(".");
        printf("\n");
    }
    return 0;
}
