#include<stdio.h>
#include<string.h>
int main()
{
    char a[10] = {'a', 'b', '\n'};
    char b[10] = {"CSE"};

    int c = strlen(a);
    int d = strlen(b);
    printf("a=%d\n", c);
    printf("b=%d", d);
}
