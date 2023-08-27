/*82*/
#include<stdio.h>
int main()
{
    int a = 5;
    printf("After accessing the value: a=%d\n", a);
    int* p = &a;
    *p = 10;
    printf("After accessing the value: a=%d", a);
}
