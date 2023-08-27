#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        int n, i, j;
        scanf("%d", &n);
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
