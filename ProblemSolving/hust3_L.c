#include<stdio.h>
#include<string.h>
int main()
{
    int l,i;
    char s[1000];
    while(gets(s)){
        for(i=0;i<strlen(s);i++) printf("%c", s[i]-7);
        printf("\n");
     }
    return 0;
}
