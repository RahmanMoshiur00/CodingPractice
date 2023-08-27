/*74*/
#include<stdio.h>
int main()
{
    int a, b, temp;
    printf("Enter two numbers to swap:");
    scanf("%d%d", &a, &b);
    printf("a=%d and b=%d\n", a, b);
    int* p = &a;
    int* q = &b;
    temp = *p;
    *p = *q;
    *q = temp;
    printf("After swapping: a=%d and b=%d", a, b);
}
