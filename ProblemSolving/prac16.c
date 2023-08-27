#include<stdio.h>
#include<string.h>

int main()
{
    int i, j=0;
    char a[20], b[20];
    gets(a);
    gets(b);
    for(i=0; i<strlen(a); i++){
        if(a[i]==b[j]) j++;
    }
    if(j==strlen(b)) printf("yes\n");
    else printf("no\n");
}
