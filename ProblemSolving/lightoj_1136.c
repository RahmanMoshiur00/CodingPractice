#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int num1, num2, count=0, n;
        scanf("%d %d", &num1, &num2);
        for(n=num1; n<=num2; n++){
            if(((n*(n+1))/2)%3==0) count++;
        }
        printf("Case %d: %d\n", l, count);
    }
}
