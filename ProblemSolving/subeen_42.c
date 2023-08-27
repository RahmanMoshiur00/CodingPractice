#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n,i;
        scanf("%d", &n);
        for(i=n; i>=0; i--){
            if(i==1 || i==0) printf("%d", i+1);
            else printf("2^%d", i);
            if(i==0) printf("\n");
            else printf(" + ");
        }
    }
    return 0;
}
