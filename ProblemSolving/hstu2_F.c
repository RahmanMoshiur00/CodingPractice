#include<stdio.h>
#include<string.h>

int main()
{
    int i, upper = 0, lower = 0;
    char ch[101];
    scanf("%s", ch);

    for(i=0; i<strlen(ch); i++){
        if(ch[i]>='a' && ch[i]<='z') lower++;
        else if(ch[i]>='A' && ch[i]<='Z') upper++;
    }

    if(lower>upper){
        for(i=0; i<strlen(ch); i++){
            if(ch[i]>='A' && ch[i]<='Z') ch[i] = ch[i] + ('a' - 'A');
        }
    }

    else if(lower<upper){
        for(i=0; i<strlen(ch); i++){
            if(ch[i]>='a' && ch[i]<='z') ch[i] = ch[i] - ('a' - 'A');
        }
    }

    if(lower==upper){
        for(i=0; i<strlen(ch); i++){
            if(ch[i]>='A' && ch[i]<='Z') ch[i] = ch[i] + ('a' - 'A');
        }
    }
    printf("%s\n", ch);

    return 0;

}
