#include<stdio.h>

int main()
{
    int t, y;
    scanf("%d", &t);

    for(y=1; y<=t; y++){
        unsigned long num, sum=0;
        int i, j, l;
        scanf("%lu", &num);
        unsigned int n;
        if(num%2==0) n = num-1;
        else n = num;

        for(i=n; i>=1; i-=2){
            sum = 0;
            for(j=i; j>=1; j-=2){
                sum += j;
                if(sum>=num) break;
            }
            if(sum==num) break;
        }
        printf("Case %d: ", y);
        if(sum==num){
            for(l=j; l<=i; l+=2){
                printf("%d", l);
                if(l==i) printf("\n");
                else printf("+");
            }
        }
        else printf("impossible\n");

    }
    return 0;
}
