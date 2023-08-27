#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d", &n)==1){
        if(n==0) break;
        int i;
        for(i=1; i<=n; i++){
            printf("%d", i);
            if(i!=n) printf(" ");
            else printf("\n");
        }
    }
}
