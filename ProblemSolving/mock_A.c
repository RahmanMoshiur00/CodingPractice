#include<stdio.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        int n, i;
        scanf("%d", &n);
        getchar();
        for(i=0; i<=n; i++){
            printf("%d ", i);
            if(i != n) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
