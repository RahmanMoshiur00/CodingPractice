#include<stdio.h>
int len = 0;
int n = 0;
int lenth(char a[])
{
    if(a[n] != '\0'){
        len++;
        n++;
        lenth(a);
    }
    return len;
}
int main()
{
        char a[100] = {"dambi puchki"};
        int l = lenth(a);
        printf("Lenth of the string is %d\n", l);
}
