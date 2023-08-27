#include<stdio.h>
#include<string.h>
int main()
{
    char ara[10], ara2[11];
    gets(ara);

    int i, j, k;
    k = strlen(ara);
    printf("%d\n", k);
    for(i = k-1, j = 0; i >= 0; i--, j++){
        ara2[j] = ara[i];
    }
    ara2[j] = '\0';
    printf("%s\n", ara2);
}
