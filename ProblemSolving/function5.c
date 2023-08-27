#include<stdio.h>

char result(int n)
{
    char a;
    if(n>0){
        a = 'P';
        return a;
    }
    else{
        a = 'M';
        return a;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char b = result(n);
    printf("%c", b);
}
