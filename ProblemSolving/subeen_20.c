#include<stdio.h>
#include<string.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[10001];
        if(l==0) gets(arr);
        gets(arr);
        int count=0;

        char* tok;
        tok = strtok(arr, ",!:?. ");

        while(tok != NULL){
            if(strlen(tok)>0) count++;
            tok = strtok(NULL, ",!:?. ");
        }

        printf("Count = %d\n", count);
    }
    return 0;
}
