#include<stdio.h>
#include<string.h>

int main()
{
    char ch[1000];
    gets(ch);
    int j=0, n;
    for(n=0; n<strlen(ch); n++){
        if((ch[n] >= 'a' && ch[n] <= 'z') || (ch[n] >= 'A' && ch[n] <= 'z') || (ch[n] >= '0' && ch[n] <= '9')){
            printf("%c", ch[n]);
        }
        else{
            printf("\n");
        }
    }
}
