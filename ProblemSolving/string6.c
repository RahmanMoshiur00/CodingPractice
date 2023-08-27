#include<stdio.h>
#include<string.h>
int main()
{
    char ara[1000];
    gets(ara);

    int a = strlen(ara);
    printf("Length=%d", a);

}
