#include<stdio.h>
#include<string.h>
int main()
{
    int l, t;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[1001];
        if(l==0) gets(arr);
        gets(arr);
        char vowel[] = "AEIOUaeiou";
        int i, j, count=0;
        for(i=0; i<strlen(arr); i++){
            for(j=0; j<strlen(vowel); j++){
                if(arr[i]==vowel[j]) count++;
            }
        }
        printf("Number of vowels = %d\n", count);
    }
    return 0;
}
