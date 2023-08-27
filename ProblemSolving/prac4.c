//1-2+3-4+5-6+.... series solving with loop

#include<stdio.h>

int main()
{
    int n, i, sum=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        if(i%2==0) sum += i * -1;
        else sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
