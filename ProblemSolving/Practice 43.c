/*78*/
#include<stdio.h>
int main()
{
    char str[30];
    printf("Enter a string to find lenth:");
    gets(str);
    int i, lenth = 0;
    for(i=0; *(str+i) != '\0'; i++){
        lenth++;
    }
    printf("Lenth of '%s' = %d", str, lenth);
}
