#include<stdio.h>
#include<string.h>

int main()
{
    int i, count = 0;
    char word[101];
    scanf("%s", word);

    for(i=0; i<strlen(word); i++){
        if(word[i]>='a' && word[i]<='z'){
            count++;
            if(count==2) break;
        }
    }

    if(count==0){
        for(i=0; i<strlen(word); i++){
            word[i] = word[i] + ('a' - 'A');
        }
    }

    else if(count==1 && (word[0]>='a' && word[0]<='z')){
        word[0] = word[0] - ('a' - 'A');
        for(i=1; i<strlen(word); i++){
            word[i] = word[i] + ('a' - 'A');
        }
    }

    count = 0;

    printf("%s\n", word);

    return 0;
}
