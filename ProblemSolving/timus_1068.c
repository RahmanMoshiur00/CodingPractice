#include<stdio.h>
int main()
{
    int n, sum=0, i;
    scanf("%d", &n);
    if(n==0) sum=1;
    else if(n<0){
        for(i=n; i<=1; i++) sum += i;
    }
    else if(n>0){
        sum = (n*(n+1)) / 2;
    }
    printf("%d\n", sum);
    return 0;
}
