#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, i, j;
        scanf("%d %d", &n, &m);
        for(i=1; i<(2*n); i++){
            if(i<=n)
             for(j=1; j<=i; j++){
                printf("%d", m);
                if(j==i) printf("\n");
                else printf(" ");
             }
            else
            for(j=1; j<=(2*n)-i; j++){
                printf("%d", m);
                if(j==(2*n)-i) printf("\n");
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
