#include<stdio.h>
int main()
{
    char a[100], b[100], c[20];
    gets(a);
    gets(b);
    int n;

    for(n=0; n<100; n++){
        if(a[n] > b[n]){
            printf("'%s' comes first than '%s'\n", b, a);
            break;
        }
        else if(a[n] < b[n]){
            printf("'%s' comes first than '%s'\n", a, b);
            break;
        }
        else if((a[n] == b[n]) && (a[n] == '\0' && b[n] == '\0')){
            printf("Strings are equal\n");
            break;
        }
    }
}

