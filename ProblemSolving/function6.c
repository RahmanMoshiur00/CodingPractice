#include<stdio.h>

void plus(int n)
{
    printf("%d\n", n);
}

int main()
{
    int i, n;
    scanf("%d", &n);
    for(i=0; i <= n; i++) plus(i);
}
