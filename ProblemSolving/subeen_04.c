#include<stdio.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int num, i;
        scanf("%d", &num);
        printf("Case %d: ", l);
        for(i=1; i<=num; i++){
            if(num % i == 0){
                printf("%d", i);
                if(i==num) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
