#include<stdio.h>
int main()
{
    int i= 0;
    char str1[100], str2[100];
    gets(str1);
    gets(str2);

    while(str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
        i = i + 1;
        if(str1[i] == '\0' && str2[i] == '\0')
            printf("strings are equal\n");
        else
            printf("string are not equal\n");
}

