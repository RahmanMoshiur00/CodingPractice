//1^2 + 2^2 + ... + n^2 series solving with loop
#include<stdio.h>

int main()
{
    int i, n, sum=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        sum += i*i;
    }
    printf("%d\n", sum);
}
