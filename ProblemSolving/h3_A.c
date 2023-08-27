#include<stdio.h>
#include<string.h>
main()
{
    char vowel[] = "aeiouy", inp[101];
    scanf("%s", inp);
    int i;

    for(i=0; i<strlen(inp); i++){
        int result = 0, j;
        for(j=0; j<6; j++){
            if(inp[i] == vowel[j]) result = 1;
        }
        if(result==0) printf(".%c", inp[i]);
    }
    printf("\n");
}
