#include<stdio.h>
#include<string.h>

void stringcopy(char a[], char b[], int len, int i)
{
    b[i] = a[i];
    i++;
    if(i == len){
        b[i] = '\0';
        return;
    }
    stringcopy(a, b, len, i);
}
int main()
{
    char a[50];
    printf("Enter a string to copy:");
    gets(a);
    int len = strlen(a);
    char b[len];
    stringcopy(a, b, len, 0);
    printf("The first string is: %s\n", a);
    printf("The second string is: %s\n", b);
    return 0;
}
