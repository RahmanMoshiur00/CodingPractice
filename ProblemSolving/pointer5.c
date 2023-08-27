#include<stdio.h>
int main()
{
    int a = 3;
    int* p = &a;
    printf("&p = %d\n", &p);
    printf("p = %d\n", p);
    printf("&a = %d\n", &a);
}
