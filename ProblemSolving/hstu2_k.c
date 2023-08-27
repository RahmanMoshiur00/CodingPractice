#include<stdio.h>
#include<string.h>
main()
{
    char text[10000][101], end[] = "E-N-D";
    int i , k=0, temp, max, j, count = 0, first = 0, lenth[100];

    for(i=0; i<10000; i++){
        scanf("%s", text[i]);
        k++;
        if(strcmp(end, text[i]) == 0) break;
    }

    temp = k;

    for(i=0; i<temp; i++){
            count = 0;
        for(j=0; j<strlen(text[i]); j++){
            if((text[i][j]>='a' && text[i][j]<='z') || (text[i][j]>='A' && text[i][j]<='Z') || text[i][j]=='-') count++;
        }
        lenth[i] = count;
    }

    max = lenth[0];
    for(i=1; i<temp; i++){
        if(lenth[i]>max){
            max = lenth[i];
            first = i;
        }
    }

    for(i=0; i<strlen(text[first]); i++){
        if(text[first][i]>='A' && text[first][i]<='Z'){
            text[first][i] = text[first][i] + ('a' - 'A');
        }
    }

    for(i=0; i<strlen(text[first]); i++){
        if((text[first][i]>='a' && text[first][i]<='z') || text[first][i]=='-') printf("%c", text[first][i]);
    }
    printf("\n");

    return 0;
}
