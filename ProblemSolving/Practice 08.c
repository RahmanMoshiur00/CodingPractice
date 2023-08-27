/*11*/
#include<stdio.h>
#include<string.h>
int main()
{
    int i, j, count = 1;
    char str1[100];
    printf("Enter string:");
    scanf("%s", str1);
    char str2[strlen(str1)];

    for(i=0, j = strlen(str1)-1; i<strlen(str1); i++, j--){
        str2[j] = str1[i];
    }

    for(i=0; i<strlen(str1); i++){
        if(str2[i] != str1[i]) count=0;
    }

    if(count==1) printf("\n%s is palindrome\n", str1);
    else printf("\n%s is not palindrome\n", str1);
}
