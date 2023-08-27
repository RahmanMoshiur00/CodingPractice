#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d", &t);
    scanf(" ");
    while(t--){
        int i, j;
        char arr[10000];
        gets(arr);
        for(i=0, j=strlen(arr)-1; i<strlen(arr)/2; i++, j--){
            if(arr[i]!=arr[j]){
                printf("Sorry! It is not palindrome!\n");
                goto end;
            }
        }
        printf("Yes! It is palindrome!\n");
        end:
            printf("");
    }
    return 0;
}
