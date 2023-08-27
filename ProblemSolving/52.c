/*52*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[30];
    printf("Enter a string:");
    gets(str);
    int i, count = 0, len = strlen(str);
    for(i=0; i<len; i++){
        if(str[i]==' ') count++;
    }
    printf("there are %d space(s) in %s", count, str);
}

