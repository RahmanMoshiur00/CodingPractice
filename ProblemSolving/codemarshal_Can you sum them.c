#include<stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    unsigned int num[n];
    unsigned long sum = 0;
    for(i=0; i<n; i++) scanf("%u", &num[i]);
    for(i=0; i<n; i+=2) sum += num[i];
    printf("%lu\n", sum);
}
