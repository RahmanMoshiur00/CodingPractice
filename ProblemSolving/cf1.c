#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    unsigned long n;
    scanf("%lu", &n);
    unsigned long long ans = (unsigned long long)pow(8.0, n*1.0);
    char str[50];
    sprintf(str, "%llu", ans);
    printf("%c\n", str[strlen(str)-1]);
}
