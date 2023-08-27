#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, i, space, j;
    scanf("%d", &n);
    for(i=0; i<=n; i++){
        for(space = n-i; space>=1; space--){
            printf("  ");
        }

        for(j=(-i); j<=i; j++) printf("%d ", abs(j));


        for(space = n-1; space>=1; space--){
        printf("  ");
        }
        printf("\n");
    }
}

