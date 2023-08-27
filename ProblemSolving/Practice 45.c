/*80*/
#include<stdio.h>
int main()
{
    int a, b, sum;
    printf("Enter two numbers to find sum:");
    scanf("%d%d", &a, &b);
    int* p = &a;
    int* q = &b;
    sum = *p + *q;
    printf("%d+%d=%d", a, b, sum);
}
