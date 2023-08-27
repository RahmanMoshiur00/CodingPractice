#include<stdio.h>
#include<string.h>
int main()
{
    char a[100], b[100];
    gets(a);
    gets(b);
    int n = strcmp(a, b);
    printf("%d\n", n);
    if(n > 0){
        printf("'%s' comes before '%s'", b, a);
    }
    else if(n < 0){
        printf("'%s' comes before '%s'", a, b);
    }
    else if(n == 0){
        printf("'%s' are equal '%s'\n", b, a);
    }
    return 0;
}
