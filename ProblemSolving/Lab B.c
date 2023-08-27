#include<stdio.h>
#include<string.h>

#define MX 10000000

char str1[MX], str2[MX];

int main()
{
    printf("Enter a string:\n");
    gets(str1);
    int i;
    for(i=0; str1[i]!='\0'; i++){
        str2[i] = str1[i];
    }
    str2[i] = '\0';
    printf("\nOriginal String: %s\n", str1);
    printf("Copied String: %s\n", str2);

    //String copy operation using built-in function
    strcpy(str2, str1);
    printf("\nOriginal String: %s\n", str1);
    printf("Copied String: %s\n", str2);

    return 0;
}
