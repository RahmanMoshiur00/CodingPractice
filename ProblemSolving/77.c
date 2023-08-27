/*77*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[30];
    printf("Enter a string:");
    scanf("%s", str);
    int i, words, words_cap = 0, words_small =  0, numbers = 0, vowels = 0;
    for(i=0; i<strlen(str); i++){
        if(str[i] >= 'A' && str[i] <= 'Z') words_cap++;
        if(str[i] >= 'a' && str[i] <= 'z') words_small++;
        if(str[i] >= '0' && str[i] <= '9') numbers++;
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' ) vowels++;
    }

    words = words_cap + words_small;

    printf("in '%s', words = %d\n", str, words);
    printf("in '%s', numbers = %d\n", str, numbers);
    printf("in '%s', vowels = %d\n", str, vowels);
}
