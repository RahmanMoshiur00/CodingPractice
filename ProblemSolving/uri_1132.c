#include<stdio.h>
int main()
{
    int i, a, b, sum=0;
    scanf("%d %d", &a, &b);
    if(a>b){
        int f = a;
        a = b;
        b = f;
    }
    for(i=a; i<=b; i++){
        if(i%13!=0) sum += i;
    }
    printf("%d\n", sum);
}
