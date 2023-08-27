#include <stdio.h>
#include <string.h>

int main()
{
    char str[205];
    gets(str);

    int i, len = strlen(str);

    for(i=len-1; i>=0; i--) printf("%c", str[i]);
    printf("\n");

    return 0;
}

