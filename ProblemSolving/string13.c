#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1000];
    gets(ch);
    int i, start = 0;
    for(i=0; i<strlen(ch); i++){
        if(ch[i] >= 'a' && ch[i] <= 'z'){
            if(start == 0){
                ch[i] = 'A' - 'a' + ch[i];
                printf("%c", ch[i]);
                start = 1;
            }
            else{
                printf("%c", ch[i]);
            }
        }
        else if((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= '0' && ch[i] <= '9')){
            if(start == 0){
                start = 1;
                printf("%c", ch[i]);
            }
            else{
                printf("%c", ch[i]);
            }
        }
        else{
            if(start == 1){
                start = 0;
                printf("\n");
            }
        }
    }
}
