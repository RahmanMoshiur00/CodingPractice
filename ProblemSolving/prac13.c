#include<stdio.h>
#include<string.h>
int main()
{
    int i, j, k=0, count=0, words=0;
    char arr[50], sarr[15];
    gets(arr);
    gets(sarr);

    for(i=0; i<strlen(arr); i++){
        k=0, words=0;
        if(arr[i]==sarr[k++]){
                words=1;
            for(j=i+1; j<i+strlen(sarr); j++){
                if(arr[j]!=sarr[k++]) break;
                else words++;
            }
        }
        if(words==strlen(sarr)) count++;
    }

    printf("%d\n", count);
    return 0;
}
