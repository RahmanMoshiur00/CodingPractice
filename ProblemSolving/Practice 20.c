/*25*/
#include<stdio.h>
int i = 0;
char findCap(char str[])
{
    if((int) str[i] >= 65 && (int) str[i] <= 90) return str[i];
    else{
        i++;
        findCap(str);
    }
}

int main()
{
    char str[30];
    printf("Enter a string:");
    scanf("%s", str);
    char c = findCap(str);
    printf("First capital of %s is %c", str, c);
}
