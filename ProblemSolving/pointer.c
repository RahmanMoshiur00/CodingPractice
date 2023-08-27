#include<stdio.h>
#include<string.h>

int main()
{
    int i; char s[100] = "dambi", s1[10] = "m";
    for(i=1; i<=5; i++){
        strcat(s, s1);
    }

    printf("%s", s);
}
